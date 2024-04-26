#include <iostream>
using namespace std;

// cau 1: viet chuong trinh in ra cac so tu 1 den 10
void cau1for(){
    cout << "\nFor: ";
    for(int i = 1; i <= 100; i++){
        cout << i << " ";
    }
}
void Cau1while(){
    cout << "\nWhile: ";
    int i = 1;
    while(i <= 100){
        cout << i << " ";
        i++;
    }
}
// cau 2: viet chuong trinh nhap vao 1 so nguyen n, n > 0. tinh tong tu 1 den n
void cau2(int n){
    int sum = 0;
    do{ 
        cout << "Nhap gia tri n: "; cin >> n;
    }while(n < 0);
    for(int i = 1; i <= n; i++){
        sum += i;
    }
    cout << "Tong tu 1 -> " << n << " la: " << sum << endl;
}
void Cau2(int n){
   int sum = 0;
    do{ 
        cout << "Nhap gia tri n: "; cin >> n;
    }while(n < 0);

    int i = 1;
    while(i <= n){
        sum += i;
        i++;
    }
    cout << "Tong tu 1 -> " << n << " la: " << sum << endl;
}
// vong lap long nhau
void InBangCuuChuong(){
    for(int i = 2; i <= 10; i++){
        for(int j = 1; j <= 10; j++){
            cout << i << " x " << j << " = " << i * j << endl;
        }
        cout << "----------------------------------\n";
    }
    cout << endl;
}
/* ve hinh chu nhat
h = 3
* * * * *
* * * * *
* * * * *

*/
void VeHinhChuNhat(int h, int l){
    do{
    cout << "Nhap chieu ngang: "; cin >> l;
    cout << "Nhap chieu doc: "; cin >> h;
    }while(h < 0 || l < 0);
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= l; j++){
            cout << "* ";
        }
        cout << endl;
    }
}
void VeHCN(int h, int l){
    do{
    cout << "Nhap chieu ngang: "; cin >> l;
    cout << "Nhap chieu doc: "; cin >> h;
    }while(h < 0 || l < 0);

    int i = 1;
    while(i <= h){
        int j = 1;
        while(j <= l){
            cout << "* ";
            j++;
        }
        cout << "\n";
        i++;
    }
}
void KiemTraDoiXung(int &n){
    do{
        cout << "Nhap n: "; cin >> n;
        if(n < 0){
            cout << "Vui long nhap n > 0\n";
        }
    }while(n < 0);
    // b1: tim so dao nguoc
    // 123
    // ct: s = s * 10 + (n % 10) -> 123 = 321
    int s = 0;
    int temp = n;
    while(n != 0){
        s = s * 10 + (n % 10);
        n /= 10;
    }
    if(s == temp){
        cout << temp << " la so doi xung\n";
    }
    else{
        cout << temp << " k la so doi xung\n";
    }
}

void MENU(){
    int ChucNang, h, l, n;
    while(true){
        system("cls");
        cout << "\n\t\t================ VONG LAP ================\n";
        cout << "\t\t1. In cac so tu 1 den 100\n";
        cout << "\t\t2. Tinh tong tu 1 den n dieu kien n > 0\n";
        cout << "\t\t3. In bang cuu chuong\n";
        cout << "\t\t4. Ve hinh chu nhat\n";
        cout << "\t\t5. Kiem tra so doi xung\n";
        cout << "\t\t0. Thoat chuong trinh\n";
        cout << "\t\t==========================================\n";

        cout << "Nhap chuc nang: "; cin >> ChucNang; cin.ignore();
        if(ChucNang == 0){
            break;
        }
        else if(ChucNang == 1){
            cau1for();
            Cau1while();
            cout << "\n";
            system("pause");
        }
        else if(ChucNang == 2){
            Cau2(n);
            system("pause");
        }
        else if(ChucNang == 3){
            InBangCuuChuong();
            system("pause");
        }
        else if(ChucNang == 4){
            VeHCN(h, l);
            system("pause");
        }
        else if(ChucNang == 5){
            KiemTraDoiXung(n);
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
    system("pause");
    return 0;
}