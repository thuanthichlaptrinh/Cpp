#include <iostream>
using namespace std;

void nhapMang(int *a, int &n){ // *a hay a[] gì cũng đúng
    for(int i = 0; i < n; i++){
        cout << "a[" << i << "] = "; 
        cin >> a[i]; // *(a + i), a[i] gì cũng đúng
    }
}

void xuatMang(int *a, int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void CapPhatVungNho(int *&a, int vung_nho_moi, int vung_nho_cu){
    // Bước 1: tạo mảng temp chứa tất cả ptu của mảng a
    int *temp = new int[vung_nho_cu];
    for(int i = 0; i < vung_nho_cu; i++){
        temp[i] = a[i]; // lưu các phần tử mảng a sang cho mảng phụ
    }
    // Bước 2: giải phóng vùng nhớ của mảng a trước đó
    delete[] a;
    // Bước 3: cấp phát lại vùng nhớ mới cho mảng a sau này 
    a = new int[vung_nho_moi];
    // Bước 4: Lưu lại tất cả phần tử của mạng temp đó về lại mảng a sau này
    for(int i = 0; i < vung_nho_moi; i++){
        a[i] = temp[i];
    }
    delete[] temp; // giải phóng vùng nhớ của mảng temp
}

void MENU(int *&a, int &n){
    int ChucNang;
    while(true){
        system("cls");
        cout << "\t1. Nhap phan tu cho mang\n";
        cout << "\t2. Xuat mang\n";
        cout << "\t0. Thoat chuong trinh\n";

        cout << "Nhap chuc nang: "; cin >> ChucNang;
        if(ChucNang == 0){
            break;
        }
        else if(ChucNang == 1){
            int x;
            cout << "Nhap gia tri x: "; cin >> x;
            if(n == 0){
                a = new int;
            }
            else{
                CapPhatVungNho(a, n + 1, n);
            }
            a[n] = x;
            n++;
        }
        else if(ChucNang == 2){
            xuatMang(a, n);
            system("pause");
        }
        else{
            cout << "Sai chuc nang\n";
            system("pause");
        }
    }
}

int main(){
    int *a;
    int n = 0;
    MENU(a, n);
    return 0;
}