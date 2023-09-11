#include <iostream>
#include <cmath>
#define MAX_DONG 100
#define MAX_COT 100
using namespace std;

// ham nhap va xuat mang 2 chieu
void NhapMang2Chieu(int a[][MAX_COT], int &dong, int &cot){ // khong can truyen vao chi so dong
    do{
        cout << "Nhap so dong: "; cin >> dong;
        if(dong <= 0 || dong > MAX_DONG){
            cout << "So dong phai nam trong doan [1; " << MAX_DONG << "]\n"; 
        }
    }while(dong <= 0 || cot > MAX_DONG);
    do{ 
        cout << "Nhap so cot: "; cin >> cot;
        if(cot <= 0 || cot > MAX_COT){
            cout << "So cot phai nam trong doan [1; " << MAX_COT << "]\n"; 
        }
    }while(cot <= 0 || cot > MAX_COT);

    for(int i = 0; i < dong; i++){ // dieu khien chi so dong
        for(int j = 0; j < cot; j++){ // dieu khien chi so cot
            cout << "Nhap phan tu a[" << i << "][" << j << "] = ";
            cin >> a[i][j]; // nhap phan tu tai dong thu i va cot thu j
        }
    }
}
void XuatMang2Chieu(int a[][MAX_COT], int dong, int cot){ // khong can truyen vao chi so dong
    for(int i = 0; i < dong; i++){ // dieu khien chi so dong
        for(int j = 0; j < cot; j++){ // dieu khien chi so cot
            cout << a[i][j] << "  "; // nhap phan tu tai dong thu i va cot thu j
        }
        cout << endl;
    }
}

/*
1. Tinh tong cac so nguyen to trong ma tran
2. Tinh tong cac phan tu tren tung dong
3. Tinh tong cac phan tu tren tung cot
4. Xuat cac phan tu tren duong cheo chinh
5. Xuat cac phan tu tren duong cheo phu
*/
bool ktraSNT(int n){
    if(n <= 1){ 
        return false;
    }
    for(int i = 2; i <= sqrt(n); i++){ 
        if(n % i == 0){
            return false;
        }
    }
    return true;
}
int TinhTongSNT(int a[][MAX_COT], int dong, int cot){
    int sum = 0;
    // duyet tung phan tu trong mang 2 chieu
    for(int i = 0; i < dong; i++){ // duyet qua cac phan tu dong
        for(int j = 0; j < cot; j++){ // duyet qua cac phan tu cot
            if(ktraSNT(a[i][j]) == true){
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
void MENU(){
    int Array[MAX_DONG][MAX_COT];
    int dong, cot, ChucNang;
    while(true){
        system("cls");
        cout << "\n\t\t________________________________________________\n\n";
        cout << "\t\t1. Nhap mang 2 chieu\n";
        cout << "\t\t2. Xuat mang 2 chieu\n";
        cout << "\t\t3. Tinh tong cac so nguyen to trong ma tran\n";
        cout << "\t\t4. Tinh tong cac phan tu tren tung dong\n";
        cout << "\t\t5. Tinh tong cac phan tu tren tung cot\n";
        cout << "\t\t6. Xuat cac phan tu tren duong cheo chinh\n";
        cout << "\t\t7. Xuat cac phan tu tren duong cheo phu\n";
        cout << "\t\t0. Thoat chuong trinh\n";
        cout << "\t\t________________________________________________\n\n";

        cout << "Nhap chuc nang: "; cin >> ChucNang;
        if(ChucNang == 0){
            break;
        }
        else if(ChucNang == 1){
            NhapMang2Chieu(Array, dong, cot);
        }
        else if(ChucNang == 2){
            XuatMang2Chieu(Array, dong, cot);
            system("pause");
        }
        else if(ChucNang == 3){
            cout << "Tong cac so nguye to trong ma tran la: " << TinhTongSNT(Array, dong, cot) << endl;
            system("pause");
        }
        else if(ChucNang == 4){
            TinhTongCacPhanTuTrenTungDong(Array, dong, cot);
            system("pause");
        }
        else if(ChucNang == 5){
            TinhTongCacPhanTuTrenTungCot(Array, dong, cot);
            system("pause");
        }
        else if(ChucNang == 6){
            cout << "Cac phan tu tren duong cheo phu: ";
            XuatCacPhanTuTrenDuongCheoChinh(Array, dong, cot);
            system("pause");
        }
        else if(ChucNang == 7){
            cout << "Cac phan tu tren duong cheo phu: ";
            XuatCacPhanTuTrenDuongCheoPhu(Array, dong, cot);
            system("pause");
        }
        else{
            cout << "Sai chuc nang. Vui long nhap lai !\n";
            system("pause");
        }
    }
}
int main(){
    MENU();
    cout << "\n";
    system("pause");
    return 1;
}