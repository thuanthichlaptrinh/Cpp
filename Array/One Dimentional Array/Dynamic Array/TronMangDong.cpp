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

void ThemVaoViTriBatky(int *&a, int &n, int vt, int &x){ 
    // trước khi thêm 1 phần tử cần phải nới rộng ra 1 ô nhớ
    CapPhatVungNho(a, n + 1, n);
    // Thực hiện thêm phần tử vào mảng
    n++;
    for(int i = n - 1; i > vt; i--){
        a[i] = a[i - 1];
    }
    a[vt] = x;
}

void XoaPhanTuTrongMang(int *&a, int &n, int vitri){
    for(int i = vitri; i < n - 1; i++){ // các ptu nằm trước vị trí cần xóa giữ nguyên
        a[i] = a[i + 1];
    }
    n--; // số lượng phần tử mảng trừ đi 1
    // sau khi xóa 1 phần tử cần phải thu hẹp về 1 ô nhớ
    CapPhatVungNho(a, n, n);
}

int main(){
    int n;
    cout << "Nhap so luong phan tu mang a: "; cin >> n;
    int *a = new int[n]; // cấp phát vùng nhớ cho con trỏ a <=> tạo mảng động có n ô nhớ
    nhapMang(a, n);
    cout << "Mang a: "; xuatMang(a, n);

    int m;
    cout << "Nhap so luong phan tu mang b: "; cin >> m;
    int *b = new int[m];
    nhapMang(b, m);
    cout << "Mang b: "; xuatMang(b, m);

    int k = 0;
    int *c = new int[n + m];
    // lưu tất cả các phần tử của mảng a sang cho mảng c
    for(int i = 0; i < n; i++){
        c[k] = a[i];
        k++;
    }
    // lưu tất cả các phần tử của mảng b sang cho mảng c
    for(int i = 0; i < m; i++){
        c[k] = b[i];
        k++;
    }
    cout << "Mang c: "; xuatMang(c, k);

    // giải phóng vùng nhớ
    delete[] a; 
    delete[] b;
    delete[] c;
    system("pause");
    return 0;
}