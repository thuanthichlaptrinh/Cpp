#include <iostream>
#define MAX 100
using namespace std;

// Nhập mảng 1 chiều
void nhapMang(int a[], int &n){
    do{
        cout << "Nhap so luong phan tu Array: "; cin >> n;
        if(n <= 0 || n > MAX){
            cout << "So luong phan tu mang khong hop le !\n";
        }
    }while(n <= 0 || n > MAX);

    for(int i = 0; i < n; i++){
        cout << "a[" << i << "] = "; cin >> a[i];
    }
}
// xuất mảng 1 chiều
void xuatMang(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
// sap xep tang dan
void SapMangXepTangDan(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] > a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
/* bài 1: Cho 2 mảng 1 chiều số nguyên. Viết chương trình trộn 2 mảng 
   lại với nhau thành 1 mảng được sắp xếp theo thứ tự tăng dần */ 
void Tron2Mang(int a[], int b[], int c[], int n, int m, int &l){
    // đổ hết tất cả các ptu mảng a vào mảng c
    for(int i = 0; i < n; i++){
        c[l] = a[i];
        l++;
    }
     // đổ hết tất cả các ptu mảng b vào mảng c
    for(int i = 0; i < m; i++){
        c[l] = b[i];
        l++;
    }
    SapMangXepTangDan(c, l);
}
int main(){
    int x[100], y[100], z[200];
    int c, d, e = 0;
    cout << "\n\t\tNHAP MANG A\n"; nhapMang(x, c); 
    cout << "Cac phan tu mang A: "; xuatMang(x, c);
    cout << "\n\t\tNHAP MANG B\n"; nhapMang(y, d); 
    cout << "Cac phan tu mang B: "; xuatMang(y, d);
    Tron2Mang(x, y, z, c, d, e);
    cout << "\n\t\tMANG SAU KHI TRON\n";
    cout << "Mang C: "; xuatMang(z, e);
    system("pause");
    return 0;
}