#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
using namespace std;

struct ChuyenBay{
    string maChuyenBay;
    string hoTenHanhKhach;
    string ngayBay; // VD: dd/mm/yyyy
    string gioBay; // VD: 20:39:67
    string noiDi;
    string noiDen;
}; typedef ChuyenBay value;

void chuanHoaChuoi(string& a) {
	// xoa khoang trang dau
	while (a[0] == ' ') { // neu ptu dau = ktrang
		a.erase(a.begin() + 0); // arese(): ham xoa ; begin(): bat dau + vi tri
	}
	// xoa ktrang cuoi
	while (a[a.length() - 1] == ' ') { // ptu o cuoi = 32
		a.erase(a.begin() + a.length() - 1);
	}
	// xoa o giua
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == ' ' && a[i + 1] == ' ') { // neu 2 ktrang lien tiep nhau
			a.erase(a.begin() + i);
			i--;
		}
	}
	// chuan hoa ki tu
	if (a[0] >= 97 && a[0] <= 122) { // thuong thanh hoa
		a[0] -= 32;
	}
	for (int i = 1; i < a.length(); i++) {
		if (a[i] == ' ') {
			i++;
			if (a[i] >= 97 && a[i] <= 122) {
				a[i] -= 32;
			}
		}
		else {
			if (a[i] >= 65 && a[i] <= 90) {
				a[i] += 32;
			}
		}
	}
}
// nhập 1 chuyến bay
void NhapChuyenBay(value &x){
    do{
        cout << "Nhap ma chuyen bay: "; fflush(stdin); getline(cin, x.maChuyenBay);
        if(x.maChuyenBay.length() > 5){
            cout << "Vui long nhap lai ma chuyen bay (toi da 5 ky tu)\n";
        }
    } while(x.maChuyenBay.length() > 5);

    do{
        cout << "Nhap ho ten hanh khach: "; getline(cin, x.hoTenHanhKhach); chuanHoaChuoi(x.hoTenHanhKhach);
        if(x.hoTenHanhKhach.length() > 30){
            cout << "Vui long nhap lai ho ten hanh khach (toi da 30 ky tu)\n";
        }
    } while(x.hoTenHanhKhach.length() > 30);

    cout << "Nhap ngay bay (dd/mm/yyyy): "; getline(cin, x.ngayBay);
    cout << "Nhap gio bay (h:min:s): "; getline(cin, x.gioBay);

    do{
        cout << "Nhap noi di: "; getline(cin, x.noiDi); chuanHoaChuoi(x.noiDi);
        if(x.noiDi.length() > 20){
            cout << "Vui long nhap lai noi di (toi da 20 ky tu)\n";
        }
    } while(x.noiDi.length() > 20);

    do{
        cout << "Nhap noi den: "; getline(cin, x.noiDen); chuanHoaChuoi(x.noiDen);
        if(x.noiDen.length() > 20){
            cout << "Vui long nhap lai noi den (toi da 20 ky tu)\n";
        }
    } while(x.noiDen.length() > 20);
}

// nhập danh sách n chuyến bay 
void NhapDanhSachChuyenBay(value ds[], int &n){
    cout << "Nhap so luong chuyen bay: "; cin >> n;
    for(int i = 0; i < n; i++){
        cout << "\n\t\tNhap chuyen bay thu " << i + 1 << "\n";
        NhapChuyenBay(ds[i]);
    }
}

//
void TextColor(int x){ //X là mã màu
    //Các hàm này là hàm thao tác API với windows bạn cứ coppy thôi không cần phải hiểu quá sâu
    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}

// Xuat cot
void XuatCot(){
    TextColor(2);
    cout << setw(18) << left << "Ma chuyen bay" << "\t"
         << setw(25) << left << "Ho va ten" << "\t" 
         << setw(15) << left << "Ngay bay" << "\t" 
         << setw(15) << left << "Gio bay" << "\t"
         << setw(20) << left << "Noi di" << "\t" 
         << setw(20) << left << "Noi den" << endl;
}

// xuất 1 chuyến bay
void XuatChuyenBay(value x){
    cout << setw(18) << left << x.maChuyenBay << "\t";
    cout << setw(25) << left << x.hoTenHanhKhach << "\t";
    cout << setw(15) << left << x.ngayBay << "\t";
    cout << setw(15) << left << x.gioBay << "\t";
    cout << setw(20) << left << x.noiDi << "\t";
    cout << setw(20) << left << x.noiDen << endl;
}

// xuất danh sách n chuyến bay
void xuatDanhSachChuyenBay(value ds[], int n){
    XuatCot();
    for(int i = 0; i < n; i++){
        //cout << "\n-------------- THONG TIN CHUYEN BAY THU " << i + 1 << " --------------";
        XuatChuyenBay(ds[i]);
    }
}

// Xóa chuyến bay có mã số bất kỳ
void XoaViTriBatKy(value ds[], int &n, int vt){
    for(int i = vt; i < n - 1; i++){ // các ptu nằm trước vị trí cần xóa giữ nguyên
        ds[i] = ds[i + 1];
    }
    n--; // số lượng phần tử mảng trừ đi 1
}
void XoaChuyenBayCoMaSoBatKy(value ds[], int &n){
    string x;
    do{
        cout << "Nhap ma chuyen bay can xoa: "; fflush(stdin);getline(cin, x);
        if(x.length() > 5){
            cout << "Vui long nhap lai ma chuyen bay (toi da 5 ki tu)\n";
        }
    }while(x.length() > 5);

    for(int i = 0; i < n; i++){
        if(ds[i].maChuyenBay == x){
            true;
            XoaViTriBatKy(ds, n, i);
        }
    }
}

// thêm thông tin chuyến bay vào vị trí bất kỳ
/*void ThemChuyenBay(value ds[], int &n, int vt, value x){
    for(int i = n - 1; i >= vt; i--){
        ds[i + 1] = ds[i];
    }
    ds[vt] = x;
    n++;
}*/

// Thêm thông tin chuyến bay vào cuối mảng
void ThemChuyenBayVaoCuoi(value ds[], int &n){
    ChuyenBay x;
    cout << "\n\t\tNhap thong tin chuyen bay can them\n";
    NhapChuyenBay(x);

    ds[n] = x; // thêm chuyến bay x vào cuối mảng
    n++; // tăng số lượng phần tử mảng lên 1
}

// Chức nang 5: Sắp xếp chuyến bay tăng dần theo năm
int YearFlight(string x){
    string year;
    for(int i = x.length() - 1; i >= 0; i--){
        if(x[i] != '/'){
            year.insert(year.begin() + 0, x[i]);
        }
        else{
            break;
        }
    }
    int nam = atoi((char*)year.c_str());
    return nam;
}
int YearDay(string x){
    string day;
    for(int i = 0; i < x.length(); i++){
        if(x[i] != '/'){
            day.insert(day.begin() + 0, x[i]); // 19/05/2004
        }
        else{
            break;
        }
    }
    int ngay = atoi((char*)day.c_str());
    return ngay;
}

void HoanVi(ChuyenBay &a, ChuyenBay &b){
    ChuyenBay temp = a;
    a = b;
    b = temp;
}
void SapXepChuyenBayTangDanTheoNam(value ds[], int &n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(YearFlight(ds[i].ngayBay) > YearFlight(ds[j].ngayBay)){
                HoanVi(ds[i], ds[j]);
            }
        }
    }
}

void TimChuyenBayTheoMaBatKy(value ds[], int n){
    bool KiemTra = false;
    string x;
    do{
        cout << "Nhap ma chuyen bay can tim: "; getline(cin, x);
        if(x.length() > 5){
            cout << "Vui long nhap ma toi da 5 ki tu !\n";
        }
    }while(x.length() > 5);
    
    for(int i = 0; i < n; i++){
        if(ds[i].maChuyenBay == x){
            XuatChuyenBay(ds[i]);
            KiemTra = true;
            break; 
        }
    }
    if(KiemTra == false){
        cout << "Khong tim thay ma chuyen bay " << x << " can tim !\n";
    }
}

void TimChuyenBayTheoKhoang(value ds[], int n){
    string x, y;
    cout << "Nhap khoang thoi gian X (dd/mm/yyyy): "; getline(cin, x);
    cout << "Nhap khoang thoi gian Y (dd/mm/yyyy): "; getline(cin, y);
    XuatCot();
    for(int i = 0; i < n; i++){
        if(YearDay(ds[i].ngayBay) >= YearDay(x) && YearDay(ds[i].ngayBay) <= YearDay(y) && YearFlight(ds[i].ngayBay) >= YearFlight(x) && YearFlight(ds[i].ngayBay) <= YearFlight(y) 
        
        ){
            XuatChuyenBay(ds[i]);
        }
    }
}

void MENU(){
    value ds[100];
    int n, x, ChucNang;
    while(true){
        system("cls");
        TextColor(3);
        cout << "\n\t\t=================== QUAN LI CHUYEN BAY ===================\n";
        cout << "\t\t1. Nhap danh sach thong tin chuyen bay\n";
        cout << "\t\t2. Xuat danh sach thong tin chuyen bay\n";
        cout << "\t\t3. Xoa chuyen bay co ma chuyen bay bat ky\n";
        cout << "\t\t4. Them chuyen bay moi vao danh sach\n";
        cout << "\t\t5. Sap sap danh sach chuyen bay tang dan theo nam bay\n";
        cout << "\t\t6. Tim kiem cac chuyen bay co ngay bay bat ky\n";
        cout << "\t\t7. Tim kiem cac chuyen bay co ma chuyen bay bat ky\n";
        cout << "\t\t8. Tim kiem cac chuyen bay trong khoang thoi gian (X, Y)\n";
        cout << "\t\t9. Tim kiem chu cai trung trong sau ho ten khach hang\n";
        cout << "\t\t0. Thoat chuong trinh\n";
        cout << "\t\t==========================================================\n\n"; 
        TextColor(7); 
        cout << "Nhap chuc nang: "; cin >> ChucNang; cin.ignore();
        if(ChucNang == 0){
            break;
        }
        else if(ChucNang == 1){
            NhapDanhSachChuyenBay(ds, n);
            cout << "\n\t\t[1]: Nhap thong tin chuyen bay thanh cong !\n";
            system("pause");
        }
        else if(ChucNang == 2){
            cout << "\n[2]: Xuat danh sach chuyen bay\n\n";
            xuatDanhSachChuyenBay(ds, n);
            system("pause");
        }
        else if(ChucNang == 3){
            XoaChuyenBayCoMaSoBatKy(ds, n);
            cout << "\n\t\t[3]: Xoa thanh cong !\n";
            system("pause");
        }
        else if(ChucNang == 4){
            ThemChuyenBayVaoCuoi(ds, n);
            cout << "\n\t\t[4]: Them thong tin chuyen bay thanh cong !\n";
            system("pause");
        }
        else if(ChucNang == 5){
            SapXepChuyenBayTangDanTheoNam(ds, n);
            cout << "\n\t\t[5]: Sap xep chuyen bay thanh cong !\n";
            system("pause");
        }
        else if(ChucNang == 7){
            cout << "\n\t\t[7]: Tim chuyen bay theo ma bat ky\n\n";
            TimChuyenBayTheoMaBatKy(ds, n);
            system("pause");
        }
        else if(ChucNang == 8){
            TimChuyenBayTheoKhoang(ds, n);
            system("pause");
        }
        else{
            cout << "Chuc nang khong hop le. Vui long nhap lai !\n";
            system("pause");
        }
    }
}

int main(){
    MENU();
    system("pause");
    return 0;
}