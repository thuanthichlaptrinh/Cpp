#pragma once
#ifndef DynamicTwoArray_h
#define DynamicTwoArray_h

// Khai báo thư viện
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctime>
#include <cmath>

// Tạo 1 kiểu dữ liệu mới
typedef int ItemType;
typedef ItemType *ArrPtr; 

// Khai báo nguyên mẫu hàm
void NhapSoNguyenDuong(int &n);
void initArrayPoiter(ArrPtr *&a, int &m, int &n);
void deleteArrayPoiter(ArrPtr *&a, int m, int n);
void NhapMang2ChieuSoNguyen(ArrPtr *&a, int &m, int &n);
void TaoMang2ChieuSoNguyen(ArrPtr *&a, int &m, int &n);
void LoadMang2ChieuSoNguyen(char *fileName, ArrPtr *&a, int &m, int &n);
void XuatMang2ChieuSoNguyen(ArrPtr *a, int m, int n);
void GhiMang2ChieuSoNguyen(char *fileName, ArrPtr *a, int m, int n);
void HoanVi(ItemType &a, ItemType &b);
int partiton(ItemType *temp, int l, int r);
void QuickSort(ItemType *temp, int l, int r);
void SapXepTrenMaTran(ArrPtr *a, int m, int n, int e);
int TinhTongCacPhanTuTamGiacTren(ArrPtr*a, int m, int n);
int DemSoDuongTrenDuongCheoChinh(ArrPtr *&a, int m, int n);
int DemSoAmTrenDuongCheoPhu(ArrPtr *&a, int m, int n);  

// Định nghĩa hàm 
void NhapSoNguyenDuong(int &n){
	do{
		scanf("%d", &n);
	} while (n <= 0);
}
void initArrayPoiter(ArrPtr *&a, int &m, int &n){
	a = new ArrPtr[m *sizeof(ItemType)]; // Cấp phát ma trận con trỏ chứa m hàng và mỗi hàng có n cột 
	for (int i = 0; i < m; i++){
		a[i] = new ItemType[n * sizeof(ItemType)];  // Cấp phát mỗi hàng có n phần tử
	}
}
void deleteArrayPoiter(ArrPtr *&a, int m, int n){
	for (int i = 0; i < m; i++){
		delete[] a[i]; // Xóa từng hàng của ma trận
	}
	delete[] a; // Xóa ma trận con trỏ chứa m hàng
}
void NhapMang2ChieuSoNguyen(ArrPtr *&a, int &m, int &n){
	printf("Nhap so dong: "); NhapSoNguyenDuong(m);
	printf("Nhap so cot: "); NhapSoNguyenDuong(n);
	initArrayPoiter(a, m, n);
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			ItemType temp;
			printf("Nhap a[%d][%d] = ", i, j);
			scanf("%d", &temp);
			a[i][j] = temp;
		}
	}
}
void TaoMang2ChieuSoNguyen(ArrPtr *&a, int &m, int &n){
	printf("Nhap so dong: "); NhapSoNguyenDuong(m);
	printf("Nhap so cot: "); NhapSoNguyenDuong(n);
	initArrayPoiter(a, m, n);
	srand((unsigned)time(NULL));
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			ItemType temp;
			temp = rand() % 101 - 50;
			a[i][j] = temp;
		}
	}
}
void LoadMang2ChieuSoNguyen(char *fileName, ArrPtr *&a, int &m, int &n){
	FILE *fi = fopen(fileName, "rt");
	if (!fi){
		printf("File khong ton tai. Vui long kiem tra lai !\n");
		return;
	}
	fscanf(fi, "%d%d\n", &m, &n);
	initArrayPoiter(a, m, n);
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			ItemType temp;
			fscanf(fi, "%d", &temp);
			a[i][j] = temp; // hoac *(a + i) = temp
		}
	}
	fclose(fi);
}
void XuatMang2ChieuSoNguyen(ArrPtr *a, int m, int n){
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			printf("%4d", a[i][j]);
		}
		printf("\n\n");
	}
}
void GhiMang2ChieuSoNguyen(char *fileName, ArrPtr *a, int m, int n){
	FILE *fo = fopen(fileName, "wt");
	if (!fo){
		printf("File khong ton tai. Vui long kiem tra lai !\n");
		return;
	}
	fprintf(fo, "%d %d\n", m, n);
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			fprintf(fo, "%-4d", a[i][j]);
		}
		fprintf(fo, "\n\n");
	}
	fclose(fo);
}
void HoanVi(ItemType &a, ItemType &b){
	ItemType temp = a;
	a = b;
	b = temp;
}
int partiton(ItemType *temp, int l, int r){
	int pivot = temp[r];
	int vt = l - 1;
	for (int i = l; i < r; i++){
		if (temp[i] < pivot){
			vt++;
			HoanVi(temp[vt], temp[i]);
		}
	}
	vt++;
	HoanVi(temp[vt], temp[r]);
	return vt;
}
void QuickSort(ItemType *temp, int l, int r){
	if (l < r){
		int pivot = partiton(temp, l, r);
		QuickSort(temp, l, pivot - 1);
		QuickSort(temp, pivot + 1, r);
	}
}
void SapXepTrenMaTran(ArrPtr *a, int m, int n, int e){
	// Khởi tạo mảng phụ
	int sl = m;
	ItemType *temp = new ItemType[sl];
	// Lưu từng phần tử tại cột e của ma trận vào mảng phụ
	for (int i = 0; i < m; i++) {
		temp[i] = a[i][e];
	}
	// Sắp xếp các phần tử trên cột e của ma trận
	QuickSort(temp, 0, sl - 1);
	// Lưu các phần tử đã sắp xếp vào lại ma trận
	for (int i = 0; i < m; i++) {
		a[i][e] = temp[i];
	}
	XuatMang2ChieuSoNguyen(a, m, n);
	// giải phóng vùng nhớ cho mảng temp
	delete[] temp;
}
int TinhTongCacPhanTuTamGiacTren(ArrPtr*a, int m, int n){
	int sum = 0;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (j > i){
				sum += a[i][j];
			}
		}
	}
	return sum;
}

/* ================================= Bài Toán Liệt Kê =================================*/
// Liệt kê các số nguyên tố xuất hiện trong ma trận
bool KiemTraSNT(int n){
	if(n < 2){
		return false;
	}
	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0){
			return false;
		}
	}
	return true;
}
void LietKeCacPhanTuLaSNT(ArrPtr *a, int m, int n){
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(KiemTraSNT(a[i][j]) == true){
				printf("%4d", a[i][j]);
			}
		}
	}
}

/* ================================= Kỹ thuật đếm =================================
Bài 450: Đếm số lượnɡ cặp ɡiá trị đối xứnɡ nhɑu wɑ đườnɡ chéo chính
Bài 451: Đếm số lượnɡ dònɡ ɡiảm
Bài 452: Đếm phần tử cực đại
Bài 455: Đếm số chẵn tronɡ mɑ trận tɑm ɡiác trên
*/
// Bài 450: Đếm số lượnɡ cặp ɡiá trị đối xứnɡ nhɑu wɑ đườnɡ chéo chính
int DemSoDoiXungDuongTrenDuongCheoChinh(ArrPtr *&a, int m, int n){
    int dem = 0;
    return dem;
}

// Bài 453: Đếm ɡiá trị dươnɡ trên đườnɡ chéo chính
int DemSoDuongTrenDuongCheoChinh(ArrPtr *&a, int m, int n){
    int dem = 0;
    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if(i == j && a[i][j] >= 0){
                dem++;
            }
        }
    }
    return dem;
}
// Bài 454: Đếm số âm trên đườnɡ chéo phụ
int DemSoAmTrenDuongCheoPhu(ArrPtr *&a, int m, int n){
    int dem = 0;
     for(int i = 0; i < m; i++){
            if (a[i][n - i - 1] <= 0){
                dem++;
            }
    }
    return dem;
}

/* Kỹ thuật đặt cờ hiệu
Bài 456: Kiểm trɑ đườnɡ chéo chính có tănɡ dần hɑy ko
Bài 457: Kiểm trɑ mɑ trận có đối xứnɡ wɑ chéo chính ko
Bài 458: Kiểm trɑ mɑ trận có đối xứnɡ wɑ chéo phụ ko
Bài 459: Kiểm trɑ mɑ trận có phải là mɑ phươnɡ ko? Mɑ phươnɡ là khi tổnɡ ptử trên các dònɡ, cột và 2 chéo chính phụ bằnɡ nhɑu
*/


/* Sắp xếp
Bài 460: Sắp chéo chính tănɡ dần
Bài 461: Sắp chéo phụ ɡiảm dần
Bài 462: Hoán vị 2 dònɡ
Bài 463: Hoán vị 2 cột
Bài 464: sắp các dònɡ tănɡ dần theo tổnɡ dònɡ
Bài 465: Đưɑ chẵn về đầu mɑ trận vuônɡ
Bài 466: * Mɑ trận vuônɡ A(n x n) với n >=3. Sắp tɑm ɡiác trên tănɡ dần từ trên xuốnɡ dưới và từ trái sɑnɡ phải
Bài 467: * Mɑ trận vuônɡ A với n>=3. Sắp tɑm ɡiác dưới ɡiảm dần từ trên xuốnɡ dưới và từ trái sɑnɡ phải
Bài 468: * Xây dựnɡ mɑ phươnɡ A
*/

#endif