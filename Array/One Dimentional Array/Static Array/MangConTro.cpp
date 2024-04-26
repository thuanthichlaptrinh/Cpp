#include <bits/stdc++.h>
using namespace std;

void NhapMang(int *&a, int &n){
    cout << "Nhap so luong phan tu mang: "; cin >> n;
    a = new int[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap a[" << i << "] = "; 
        cin >> a[i];
    }
}
void XuatMang(int *a, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", &a[i]);
    }
}
void TimMax(int *a, int n){
    int *max = &a[0]; //tạo con trỏ max trỏ tới địa chỉ của giá trị đầu tiên trong mảng
    for(int i = 1; i < n; i++){
        if(*max < a[i]){  // * là toán tử lấy giá trị của con trỏ
            *max = a[i];
        }
    }
    cout << "\nMax: " << *max; 
    cout << "\nDia chi cua max: " << &max;
}

void NhapChuoi(char *s){
    printf("Nhap chuoi s: "); gets(s);
}
void XuatChuoi(char *s){
    printf("Chuoi vua nhap: %s\n", s);
}
void XuatTungKiTu(char *s){
    printf("Cac ki tu trong chuoi s: ");
    for(int i = 0; i < strlen(s); i++){
        char *x = &s[i];
        if(s[i] != ' '){
            printf("%c ", *x);
        }
    }
}

int main(){
     // int x = 10, y = 15;
    // int *a = &x;
    // int *b = &y;
    // cout << *a << " " << *b << endl;

    // int *a = NULL;
    // int n = 0;
    // NhapMang(a, n);
    // TimMax(a, n);
    
    char *s;
    NhapChuoi(s);
    XuatChuoi(s);
    XuatTungKiTu(s);

    //delete a;
    system("pause");
    return 0;
}