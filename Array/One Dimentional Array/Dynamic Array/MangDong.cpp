#include <iostream>
#include <cmath>
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

void Them(int *&a, int &n, int vt, int x){ 
    // trước khi thêm 1 phần tử cần phải nới rộng ra 1 ô nhớ
    CapPhatVungNho(a, n + 1, n);
    // Thực hiện thêm phần tử vào mảng
    n++;
    for(int i = n - 1; i > vt; i--){
        a[i] = a[i - 1];
    }
    a[vt] = x;
}

void Xoa(int *&a, int &n, int vitri){
    for(int i = vitri; i < n - 1; i++){ // các ptu nằm trước vị trí cần xóa giữ nguyên
        a[i] = a[i + 1];
    }
    n--; // số lượng phần tử mảng trừ đi 1
    // sau khi xóa 1 phần tử cần phải thu hẹp về 1 ô nhớ
    CapPhatVungNho(a, n, n);
}

bool KiemtraSoDoiXung(int n){
    // Bước 1: đảo ngược số ban đầu
    int daonguoc = 0;
    int temp = n;
    while(n != 0){
        daonguoc = (daonguoc * 10) + (n % 10);
        n /= 10;
    }
    if(temp == daonguoc){
        return true;
    }
    return false;
}

int TinhTongSoDoiXung(int *a, int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(KiemtraSoDoiXung(a[i]) == true){
            sum += a[i];
        }
    }
    return sum;
}

void XoaCacSoDoiXung(int *&a, int &n){
    for(int i = 0; i < n; i++){
        if(KiemtraSoDoiXung(a[i]) == true){
            Xoa(a, n, i); // xóa tại vị trí thứ i
            i--; // kiểm tra lại phần tử tại vị trí vừa xóa trước đó
        }
    }
}

void ThemPhanTu0VaoSauSoLe(int *&a, int &n){
    for(int i = 0; i < n; i++){
        if(a[i] % 2 != 0){
            Them(a, n, i, 0);
            i++;
        }
    }
}

bool KiemTraSoNguyenTo(int n){
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


void XuatCacSoNguyenTo(int *a, int n){
    for(int i = 0; i < n; i++){
        if(KiemTraSoNguyenTo(a[i]) == true){
            cout << a[i] << "  ";
        }
    }
}

void HoanVi(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void SapXepSNTTangDan(int *&a, int n){
    for(int i = 0; i < n; i++){
        if(KiemTraSoNguyenTo(a[i]) == true){ // lấy a[i] nào là snt để ktra với a[j] nào là snt
            for(int j = i + 1; j < n; j++){
                if(KiemTraSoNguyenTo(a[j]) == true){ 
                    if(a[i] > a[j]){
                        HoanVi(a[i], a[j]);
                    }
                }
            }
        }
    }
}

void TimGiaTriLeCuoiCung(int *a, int n){
    bool KiemTra = false;
    for(int i = n - 1; i > 0; i--){
        if(a[i] % 2 != 0){
            cout << "Phan tu le cuoi cung: " << a[i];
            KiemTra = true;
            break;
        }
    }
    if(KiemTra == false){
        cout << "Mang toan phan tu chan !\n";
    }
}

bool KiemTraMangToanChan(int *a, int n){
    bool KT = true; // giả sử mảng toàn phần tử chẳn
    for(int i = 0; i < n; i++){
        if(a[i] % 2 != 0){
            KT = false; // giả sử ban đầu là sai => cập nhật giả sử mảng có phần tử lẻ
            break;
        }
    }
    return KT;
}

/* Số armstrong là số mà từng chữ số trong số đó lũy thừa với số chữ số của nó bằng chính nó
    n = 1023
    => 1^4 + 0^4 + 2^4 + 3^4 so sánh với 1023

    1023 % 10 = 3
    1023 / 10 = 102
 */
bool KiemTraSoAmstrong(int n){ // so amstrong: n = 153 <=> 1^3 + 5^3 + 3^3
    // Bước 1: đi tìm số lượng chữ số <=> bậc k
    int k = 0;
    int temp = n; 
    while(n != 0){
        k++;
        n /= 10;
    }
    n = temp;
    // Bước 2: Tính tổng lũy thừa bậc k của từng chữ số
    int sum = 0;
    while(n != 0){
        sum += (pow(n % 10, k));
        n /= 10;
    }
    n = temp;
    if(n == sum){
        return true;
    }
    return false;
}

void XuatSoAmstrong(int *a, int n){
    for(int i = 0; i < n; i++){
        if(KiemTraSoAmstrong(a[i]) == true){
            cout << a[i] << "  ";
        }
    }
}

void MENU(int *&a, int &n){
    int ChucNang;
    while(1){
        system("cls");
        cout << "\n\t\t----------------- Mang Dong -----------------\n";
        cout << "\t\t1. Nhap mang\n";
        cout << "\t\t2. Xuat mang\n";
        cout << "\t\t3. Xoa cac phan tu la so doi xung\n";
        cout << "\t\t4. Them phan tu 0 vao sau cac so le\n";
        cout << "\t\t5. Tinh tong cac so doi xung\n";
        cout << "\t\t6. Xuat cac so nguyen to\n";
        cout << "\t\t7. Sap xep cac so nguyen to tang dan\n";
        cout << "\t\t8. Tim gia tri le cuoi cung trong mang\n";
        cout << "\t\t9. Kiem tra mang co toan ptu chan hay khong\n";
        cout << "\t\t10. Dem so luong cac gia tri khac nhau\n";
        cout << "\t\t11. Tinh tong cac gia tri khac nhau\n";
        cout << "\t\t0. Thoat chuong trinh\n";
        cout << "\t\t---------------------------------------------\n";

        cout << "\nNhap chuc nang: "; cin >> ChucNang;
        switch (ChucNang){
        case 0:{
            delete[] a;
            return;
        }
        case 1:{
            do{
                cout << "Nhap so luong phan tu mang: "; cin >> n;
            }while(n <= 0);
            a = new int[n];
            nhapMang(a, n);
            break;
        }
        case 2:{
            xuatMang(a, n);
            system("pause");
            break;
        }
        case 3:{
            XoaCacSoDoiXung(a, n);
            cout << "\n\t[3]: Xoa cac so doi xung thanh cong !\n";
            system("pause");
            break;
        }
        case 4:{
            int x; cout << "Nhap gia tri can them: "; cin >> x;
            int vt; cout << "Nhap vi tri can them: "; cin >> vt;
            Them(a, n, vt, x);
            system("pause");
            break;
        }
        case 5:{
            cout << "Tong cac so doi xung: " << TinhTongSoDoiXung(a, n) << endl;
            system("pause"); 
            break;
        }
        case 6:{
            cout << "Cac so nguyen to la: ";
            XuatCacSoNguyenTo(a, n);
            system("pause");
            break;
        }
        case 7:{
            SapXepSNTTangDan(a, n);
            cout << "\n\t[7]: Sap xep cac so nguyen to thanh cong !\n";
            system("pause");
            break;
        }
        case 8:{
            TimGiaTriLeCuoiCung(a, n);
            system("pause");
            break;
        }
        case 9:{
            if(KiemTraMangToanChan(a, n) == true){
                cout << "Mang toan phan tu chan !\n";
            }
            else{
                cout << "Mang co ton tai phan tu le !\n";
            }
            system("pause");
            break;
        }
        default:{
            cout << "Sai chuc nang. Vui long nhap lai !\n";
            system("pause");
            break;
        }
        } 
    }
}

int main(){
    int *a = NULL;
    int n = 0;
    MENU(a, n);

    system("pause");
    return 0;
}