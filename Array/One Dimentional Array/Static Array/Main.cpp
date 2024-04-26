#include <iostream> 
#include <time.h>
#include <math.h>
using namespace std;
#define MAX 100
typedef int value;

void nhapMang(value a[], int &n);
void MangNgauNhien(value a[], int n);
void xuatMang(value a[], int n);
void ThemPhanTuVaoMang(value a[], int &n, int x, int vitri); // thêm
void XoaPhanTuTrongMang(int a[], int &n, int vitri);
bool KtraChuSoChan(int x); 
void LietKeCacPhanChanDauTien(value a[], int n);
bool KtraChuSoHangChuc(int x);
int tinhTongSoHangChuc(value a[], int n);
int demSoLanXuatHienX(value a[], int n, int x);
void timKiemGtriChanDauTien(value a[], int n);
void TimKiemGtriLeCuoiCung(value a[], int n);
void timKiemGtriLeCuoiCung(value a[], int n);
bool ktraSNT(int n);
int KtraMangTonTaiSNT(value a[], int n);
void SapMangXepTangDan(value a[], int n);
void SapMangXepGiamDan(value a[], int n);
int TimMax(int a[], int n);
int UCLN(int x, int y);
int Tim_UCLN_Trong_Mang(int a[], int n);
int BCNN(int x, int y);
int Tim_BCNN_Trong_Mang(int a[], int n);
void Tim_Gtri_Xa_X_Nhat(int a[], int n, int x);

void Array(){
    value a[MAX];
    int n, x, vitri, chucNang;
    bool KiemTra = true;

    while(KiemTra == true){
        system("cls");
        cout << "\n\t\t\t------------------------- Array -------------------------\n";
        cout << "\t\t\t1. Nhap mang so nguyen\n";
        cout << "\t\t\t2. Xuat mang so nguyen\n";
        cout << "\t\t\t3. Them 1 phan tu vao mang\n";
        cout << "\t\t\t4. Xoa 1 phan tu trong mang\n";
        cout << "\t\t\t5. Liet ke cac ptu co chu so dau tien la chu so chan\n";
        cout << "\t\t\t6. Tinh tong cac ptu co chu so hang chuc la chu so chan\n";
        cout << "\t\t\t7. Dem so lan xuat hien x\n";
        cout << "\t\t\t8. Tim so chan dau tien, so le cuoi cung\n";
        cout << "\t\t\t9. kiem tra mang co ton tai ptu là SNT hay khong\n";
        cout << "\t\t\t10. Sap xep mang tang, giam dan\n";
        cout << "\t\t\t11. Tim gia tri lon nhat\n";
        cout << "\t\t\t12. Tim UCLN, BCNN cua cac phan tu trong mang\n";
        cout << "\t\t\t0. Thoat chuong trinh\n";
        cout << "\t\t\t----------------------------------------------------------\n";

        cout << "\nNhap chuc nang: "; cin >> chucNang;
        switch (chucNang){
            case 0:{
                KiemTra = false;
                break;
            }
            case 1:{
                nhapMang(a, n);
                cout << "\n\t[!] Them phan tu vao mang thanh cong !\n";
                system("pause");
                break;
            }
            case 2:{
                cout << "\n[2]: Xuat mang:\n";
                xuatMang(a, n);
                system("pause");
                break; 
            }
            case 3:{
                cout << "Nhap gia tri can them: "; cin >> x;
                cout << "Nhap vi tri can them: "; cin >> vitri;
                ThemPhanTuVaoMang(a, n, x, vitri);
                cout << "Da them phan tu vao mang !\n";
                system("pause");
                break;
            }
            case 4:{
                cout << "Nhap vi tri can xoa: "; cin >> vitri;
                XoaPhanTuTrongMang(a, n, vitri);
                cout << "Da xoa phan tu trong mang !\n";
                system("pause");
                break;
            }
            case 5:{
                LietKeCacPhanChanDauTien(a, n);
                system("pause");
                break;
            }
            case 6:{
                cout << "Tong = " << tinhTongSoHangChuc(a, n) << endl;
                system("pause");
                break;
            }
            case 7:{
                cout << "Nhap gia tri x can dem: "; cin >> x;
                cout << "So lan xuat hien x: " << demSoLanXuatHienX(a, n, x) << endl;
                system("pause");
                break;
            }
            case 8:{
                timKiemGtriChanDauTien(a, n);
                timKiemGtriLeCuoiCung(a, n);
                system("pause");
                break;
            }
            case 9:{
                if(KtraMangTonTaiSNT(a, n) == 1){
                    cout << "Mang co ton tai phan tu la so nguyen to\n";
                }
                else{
                    cout << "Mang khong ton tai phan tu la so nguyen to\n";
                }
                system("pause");
                break;
            }
            case 10:{
                SapMangXepGiamDan(a, n); cout << "Mang giam dan: "; xuatMang(a, n);
                SapMangXepTangDan(a, n); cout << "Mang tang dan: "; xuatMang(a, n);
                system("pause");
                break;
            }
            case 11:{
                cout << "Max = " << TimMax(a, n) << endl;
                system("pause");
            }
            case 12:{
                cout << "UCLN = " << Tim_UCLN_Trong_Mang(a, n) << endl;
                cout << "BCNN = " << Tim_BCNN_Trong_Mang(a, n) << endl;
                system("pause");
            }
            case 13:{
                cout << "Nhap gia tri x: "; cin >> x;
                Tim_Gtri_Xa_X_Nhat(a, n, x);
                system("pause");
                break;
            }
            default:{
                cout << "Sai chuc nang, vui long nhap lai !\n";
                system("pause");
                break;
            }
        }
    }
}

int main(){
    Array();
    return 0;
}
 
// Nhập mảng 1 chiều
void nhapMang(value a[], int &n){
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

void saoChepMangMotChieu(int a[], int Array[], int n){
	for (int i = 0; i < n; i++){
		a[i] = Array[i]; // lưu giá trị của mảng a vào mảng Array
	}
}

// Sinh mảng 1 chiều ngẫu nhiên
void MangNgauNhien(value a[], int n){
	srand((unsigned)time(NULL));
	for(int i=0; i<n; i++){
		a[i] = rand() % 100 - rand() % 100;
    }
}

// xuất mảng 1 chiều
void xuatMang(value a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

//================== KĨ THUẬT THÊM ==================
// hàm có nhiệm vụ thêm 1 phần tử x vào vị trí k bất kì
void ThemPhanTuVaoMang(value a[], int &n, int x, int vitri){
    for(int i = n - 1; i >= vitri; i--){ // dịch các phần tử ở phía sau vị trí cần thêm
        a[i + 1] = a[i];
    }
    a[vitri] = x;
    n++;
}
void ThemVaoViTriBatKy(int a[], int &n, int vt, int x){
    cout << "Nhap vi tri can them: "; cin >> vt;
    cout << "Nhap gia tri can them: "; cin >> x;
    // Kiem tra kich thuoc cua mang
    int size = sizeof(x) / sizeof(a[0]);
    if(size == x){
        cout << "Khong the them vao mang !\n";
    }

    n++; // tăng giá trị n lên để dịch các phần tử ra sau
    for(int i = n - 1; i > vt; i--){ 
        a[i] = a[i - 1]; // dịch tất cả các phần tử phía sau k ra 1 đơn vị
    }
    a[vt] = x; // gán giá trị của biến cần thêm vào vị trí cần thêm
}

void ThemPhanTuVaoCuoiMang(value a[], int &n, int x){
    cout << "Nhap gia tri can them: "; cin >> x;
    int size = sizeof(x) / sizeof(a[0]); // kiem tra kich thuoc cua mang
    if(x == size){
        cout << "Khong the them vao mang\n";
    }
    a[n] = x;
    n++;
}

// ================== KĨ THUẬT XÓA ==================
void XoaPhanTuTrongMang(int a[], int &n, int vitri){
    for(int i = vitri; i < n - 1; i++){ // các ptu nằm trước vị trí cần xóa giữ nguyên
        a[i] = a[i + 1];
    }
    n--; // số lượng phần tử mảng trừ đi 1
}

// ================== KĨ THUẬT LIỆT KÊ ====================
// Bài 1: Viết hàm liệt kê các phần tử có chữ số đầu tiên là chữ số chẳn.
// ktra số đầu bằng cách / 10, VD: 123 / 10 = 12, 12 / 10 = 2 => 123 la so co chu so dau tien la chan
bool KtraChuSoChan(int x){
    while(x >= 10){ // chia đến khi x < 10 thì dừng
        x /= 10;
    }
    if(x % 2 != 0){
        return false;
    }
    return true;
}
void LietKeCacPhanChanDauTien(value a[], int n){
    for(int i = 0; i < n; i++){
        if(KtraChuSoChan(a[i]) == true){ 
            cout << a[i] << " ";
        }
    }
}

// ================== KĨ THUẬT TÍNH TỔNG ================== 
// Viết hàm tính tổng các phần tử có chữ số hàng chục là chữ số chẵn.
bool KtraChuSoHangChuc(int x){
    if(x >= 100){
        x = (x % 100) / 10; 
    }
    if(x % 2 != 0){
        return false;
    }
    return true;
}
int tinhTongSoHangChuc(value a[], int n){
    int tong = 0;
    for(int i = 0; i < n; i++){
        if(KtraChuSoHangChuc(a[i]) == true){
            tong += a[i];
        }
    }
    return tong;
}

// ================== KĨ THUẬT ĐẾM ================== 
// Viết hàm đếm số lần xuất hiện giá trị x trong mảng (x nhập từ phím)
int demSoLanXuatHienX(value a[], int n, int x){
    int cout = 0; // dùng để kiểm tra số lần xuất hiện của x
    for(int i = 0; i < n; i++){
        if(a[i] == x){
            cout++;
        }
    }
    return cout;
}
// Viết hàm đếm số lượng ptu là số đối xứng trong mảng
int demDoiXung(value a[], int n){

}

// ================== KĨ THUẬT TÌM KIẾM ================== 
// Bài 1: Viết hàm tìm giá trị chẵn đầu tiên trong mảng
// VD: 1 2 3 4 5 => chẵn đầu tiên là 2
void timKiemGtriChanDauTien(value a[], int n){
    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 0){
            cout << "Gia tri chan dau tien la: " << a[i] << endl;
            break; // thoat khoi vong lap
        }
    }
}
// Bài 2: Viết hàm tìm giá trị lẻ cuối cùng trong mảng
// VD: 1 2 3 4 5 => lẻ cuối cùng là 5
void TimKiemGtriLeCuoiCung(value a[], int n){
    int le = a[0]; // giả sử thằng đầu tiên là lẻ cuối cùng
    for(int i = 0; i < n; i++){
        if(a[i] % 2 != 0){ 
            le = a[i]; // cập nhật lại a[i] là thằng lẻ cuối cùng
        }
    }
    cout << "Gia tri le cuoi cung la: " << le << endl;
}
void timKiemGtriLeCuoiCung(value a[], int n){
    for(int i = n - 1; i < n; i--){
        if(a[i] % 2 != 0){
            cout << "Gia tri le cuoi cung la: " << a[i] << endl;
            break;
        }
    }
}

// ================== KĨ THUẬT ĐẶT CỜ HIỆU ================== 
// Bài 1: viết hàm ktra mảng có tồn tại ptu là số nguyên tố hay không? nếu có trả về 1, ngược lại trả về 0
bool ktraSNT(int n){
    if(n <= 1){ // nếu n <= 1 thì không phải số nguyên tố
        return false;
    }
    for(int i = 2; i <= sqrt(n); i++){ // duyệt ktra nếu n mà % i thì => k phải số nguyên tố
        if(n % i == 0){
            return false;
        }
    }
    return true;
}
int KtraMangTonTaiSNT(value a[], int n){
    // đặt cờ hiệu biến kt
    bool kt = false; // giả sử mảng không có tồn tại phần tử số nguyên tố
    for(int i = 0; i < n; i++){
        if(ktraSNT(a[i]) == true){ // nếu ktraSNT == true => giả sử sai
            kt = true; // cập nhật lại mảng có tồn tại số SNT
            break; // chỉ cần ktra 1 phần tử
        }
    }
    return kt;
}

// ================== KỸ THUẬT ĐẶT LÍNH CANH ==================
// Bài 1: Tìm phần tử lớn nhất trong mảng
int TimMax(int a[], int n){
    int max = a[0]; // giả sử phần tử đầu tiên là phần tử lớn nhất
    for(int i = 1; i < n; i++){ // duyệt qua các phần tử còn lại
        if(a[i] > max){ // nếu phần tử a[i] trong mảng lớn hơn max
            max = a[i]; // cập nhật lại max = a tại vị trí thứ i đó
        }
    }
    return max; // trả về phần tử lớn nhất vừa tìm
}

// Bài 2: Tìm UCLN của các phần tử trong mảng
int UCLN(int x, int y){ // thuật toán euclid
    while(x != y){
        if(x > y){
            x -= y;
        }
        else{
            y -= x;
        }
    }
    return x;
}
int Tim_UCLN_Trong_Mang(int a[], int n){
    int x = a[0]; // cho giá trị UCLN là thằng đầu tiên
    for(int i = 1; i < n; i++){
        x = UCLN(x, a[i]); // tìm UCLN của từng phần tử trong mảng bắt đầu tử thằng thứ 1 trở về n - 1 với x
    }
    return x;
}

// Bài 3: Tìm BCNN của các phần tử trong mảng
int BCNN(int x, int y){
    return (x * y) / UCLN(x, y);
}
int Tim_BCNN_Trong_Mang(int a[], int n){
    int x = a[0]; // cho giá trị BCNN là thằng đầu tiên
    for(int i = 1; i < n; i++){
        x = BCNN(x, a[i]); // tìm BCNN của từng phần tử trong mảng
    }
    return x;
}

/* Bài 4: tìm giá trị trong mảng các số nguyên xa giá trị x nhất 
   (x nhập từ phím).
VD:
+ 24 -45 23 13 43 -12
   9 60  8  2  28  27
   x = 15
   => giá trị trong mảng xa x nhất là : 45
*/
void Tim_Gtri_Xa_X_Nhat(int a[], int n, int x){
    int max = abs(a[0] - x); // lấy giá trị tuyệt đối vì có trường hợp ra số âm
    int j = 0; // Lưu lại vị trí của phần tử xa x nhất
    for(int i = 1; i < n; i++){
        if(abs(a[i] - x) > max){
            max = abs(a[i] - x); // cập nhật lại khoảng cách tại a vị trí thứ i đó là max
            j = i; // gán chỉ số của ptu có kc xa x nhất cho j
        }
    }
    cout << "Gia tri trong mang xa x nhat la: " << a[j] << endl; // xuất phần tử a[j]
}

// ================== KĨ THUẬT SẮP XẾP ================== 
// sap xep tang dan
void SapMangXepTangDan(value a[], int n){
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
// sap xep giam dan
void SapMangXepGiamDan(value a[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] < a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
// ================== BÀI TẬP ==================
