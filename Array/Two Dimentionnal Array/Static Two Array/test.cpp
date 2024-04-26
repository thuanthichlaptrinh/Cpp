#include <bits/stdc++.h>
#define MAX_DONG 100
#define MAX_COT 100
using namespace std;

void Input(int a[][MAX_COT], int &n, int &m){
    do{
        cout << "Nhap so dong: "; cin >> n;
        if(n < 0 || n > MAX_DONG){
            cout << "So dong phai nam trong doan [1;" << MAX_DONG << "]\n";
        }
    }while(n < 0 || n > MAX_DONG);

    do{
        cout << "Nhap so cot: "; cin >> m;
        if(m < 0 || m > MAX_COT){
            cout << "So cot phai nam trong doan [1;" << MAX_COT << "]\n";
        }
    }while(m < 0 || m > MAX_COT);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << "Nhap a[" << i << "][" << j << "]: "; 
            cin >> a[i][j];
        }
    }
}
void DocFile(int a[][MAX_COT], int &n, int &m){
    ifstream f; 
    f.open("SoNguyen.txt", ios::in);
    f >> n;
    f >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            f >> a[i][j];
        }
    }
    f.close();
}

void Output(int a[][MAX_COT], int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[i][j] << "    ";
        }
        cout << "\n\n";
    }
}

// Bài 1: Liệt kê các số nguyên tố xuất hiện trong ma trận
bool KiemTraSNT(int x){
    if(x < 2){
        return false;
    }
    int n = sqrt(x);
    for(int i = 2; i <= n; i++){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}
void LietKeSNT(int a[][MAX_COT], int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(KiemTraSNT(a[i][j]) == true){
                cout << a[i][j] << "  ";
            }
        }
    }
}

// Bài 2: Tìm phần tử lớn nhất trong ma trận và liệt kê vị trí
int Max(int a[][MAX_COT], int n, int m){
    int max = a[0][0];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] > max){
                max = a[i][j];
            }
        }
    }
    return max;
}
void LietKeViTriCuaMax(int a[][MAX_COT], int n, int m){
    int max = Max(a, n, m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == max){
                cout << "a[" << i + 1 << "][" << j + 1 << "]\t";
            }
        }
    }
}

// Bài 3: Tìm dòng có tổng các phần tử lớn nhất trong ma trận
// Bước 1: Tìm giá trị lớn nhất trên dòng
// Bước 2: Xuất các chỉ số dòng có tất cả các phần tử bằng với giá trị max vừa tìm
int SumMax(int a[][MAX_COT], int n, int m){
    int max = INT_MIN; // giả sử max có tổng ptu lớn nhất
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = 0; j < m; j++){
            sum += a[i][j];
        }
        if(sum > max){ 
            max = sum; // cập nhật max là giá trị lớn nhất mới
        }
    }
    return max;
}
void XuatDongSumMax(int a[][MAX_COT], int n, int m){
    int max = SumMax(a, n, m);
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = 0; j < m; j++){
            sum += a[i][j];
        }
        if(sum == max){
            cout << i + 1 << "  ";
        }
    }
}

// Bài 4. Tìm cột có nhiều số Fibonacci nhất trong ma trận

// Bài 5. Tổng phần tử thuộc tam giác dưới, trên
// i = 0, i >= j
int TongTamGiacDuoi(int a[][MAX_COT], int n, int m){
    int tong = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){ // chỉ số cột phải <= chỉ số dòng
            tong += a[i][j];
        }
    }
    return tong;
}

// i = 0, i = j
int TongTamGiacTren(int a[][MAX_COT], int n, int m){
    int tong = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < m; j++){ // chỉ số cột phải <= chỉ số dòng
            tong += a[i][j];
        }
    }
    return tong;
}

// Bài 6: In các phần tử ở biên
void XuatPhanTuBien(int a[][MAX_COT], int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){ // chỉ số cột phải <= chỉ số dòng
            if(i == 0 || j == 0 || i == n - 1 || j == m - 1){
                cout << a[i][j] << "    "; 
            }
            else {
                cout << "     ";
            }
        }
        cout << "\n\n";
    }
}
/*
1. Tinh tong cac so nguyen to trong ma tran
2. Tinh tong cac phan tu tren tung dong
3. Tinh tong cac phan tu tren tung cot
4. Xuat cac phan tu tren duong cheo chinh
5. Xuat cac phan tu tren duong cheo phu
*/
int TinhTongSNT(int a[][MAX_COT], int dong, int cot){
    int sum = 0;
    // duyet tung phan tu trong mang 2 chieu
    for(int i = 0; i < dong; i++){ // duyet qua cac phan tu dong
        for(int j = 0; j < cot; j++){ // duyet qua cac phan tu cot
            if(KiemTraSNT(a[i][j]) == true){
                sum += a[i][j];
            }
        }
    }
    return sum;
}
void TinhTongCacPhanTuTrenTungDong(int a[][MAX_COT], int dong, int cot){
    for(int i = 0; i < dong; i++){ // duyet qua cac phan tu dong
        int sum = 0;
        for(int j = 0; j < cot; j++){ // duyet qua cac phan tu cot
            sum += a[i][j]; // tinh tong tren dong thu i
        }
        cout << "\nTong tren dong thu " << i << ": " << sum;
    }
    cout << endl;
}
void TinhTongCacPhanTuTrenTungCot(int a[][MAX_COT], int dong, int cot){
    for(int i = 0; i < cot; i++){ // duyet qua cac phan tu dong
        int sum = 0;
        for(int j = 0; j < dong; j++){ // duyet qua cac phan tu cot
            sum += a[j][i]; // tinh tong tren cot thu i
        }
        cout << "\nTong tren cot thu " << i << ": " << sum;
    }
    cout << endl;
}
// chi co ma tran vuong moi co duong cheo chinh
void XuatCacPhanTuTrenDuongCheoChinh(int a[][MAX_COT], int dong, int cot){
    for(int i = 0; i < dong; i++){
        for(int j = 0; j < cot; j++){
            if(a[i][j] == a[j][i]){
                cout << a[i][j] << " ";
            }
        }
    }
}
void XuatCacPhanTuTrenDuongCheoPhu(int a[][MAX_COT], int dong, int cot){
    for(int i = 0; i < dong; i++){ // vi ma tran vuong dong = cot
        cout << a[i][dong - i - 1] << " ";
    }
}

int main(){
    //int a[MAX_DONG][MAX_COT];
    int a[MAX_DONG][MAX_COT];
    int n, m;  
    DocFile(a, n, m);
    Output(a, n, m);
    
    XuatPhanTuBien(a,n,m);

    system("pause");
    return 0;
} 
