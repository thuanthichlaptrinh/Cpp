#include <iostream>
#include <string>
using namespace std;

struct SinhVien{
    string maSo;
    string hoTen;
    int namSinh;
    float diemTrungBinh;
}; 
typedef SinhVien value;

struct Array{
    SinhVien *ds[100];
    int n;
};

void NhapThongTinSinhVien(value &x){
    cout << "Nhap ma so sinh vien: "; cin.ignore(); getline(cin, x.maSo);
    cout << "Nhap ho va ten: "; getline(cin, x.hoTen);
    cout << "Nhap nam sinh: "; cin >> x.namSinh;
    cout << "Nhap diem trung binh: "; cin >> x.diemTrungBinh;
}

void NhapDanhSachSinhVien(value ds[], int &n){
    cout << "Nhap so luong sinh vien: "; cin >> n; cin.ignore();
    for(int i = 0; i < n; i++){
        cout << "\n\t\tNHAP THONG TIN SINH VIEN THU " << i + 1 << endl;
        NhapThongTinSinhVien(ds[i]);
    }
}

void XuatThongTinSinhVien(value x){
    cout << "\n- Ma so sinh vien: " << x.maSo;
    cout << "\n- Ho va ten: " << x.hoTen;
    cout << "\n- Nam sinh: " << x.namSinh;
    cout << "\n- Diem trung binh: " << x.diemTrungBinh;
}

void XuatDanhSachSinhVien(value ds[], int n){
    for(int i = 0; i < n; i++){
        cout << "\n--------------- THONG TIN SINH VIEN THU " << i + 1 << " ---------------";
        XuatThongTinSinhVien(ds[i]);
    }
    cout << "\n\n";
}

void TimKiemSinhVienTheoDiem(value ds[], int n){
    float x;
    cout << "\nNhap diem can tim: "; cin >> x; cin.ignore();
    for(int i = 0; i < n; i++){
        if(ds[i].diemTrungBinh == x){
            cout << "\n\t\tTHONG TIN SINH VIEN CO DIEM " << x;
            cout << "\n--------------- THONG TIN SINH VIEN THU " << i + 1 << " ---------------";
            XuatThongTinSinhVien(ds[i]);
        }
    }
}

void ThemSinhVienVaoViTriBatKy(value a[], int &n){ 
    int vt; value x;
    cout << "Nhap vi tri can them: "; cin >> vt;
    NhapThongTinSinhVien(x);
    for(int i = n - 1; i >= n; i--){
        a[i + 1] = a[i];
    }
    a[vt] = x;
    n++;
}

void XoaSinhVienTheoDiem(value arr[], int &n, int vt){
    //int vt; 
    // cout << "Nhap vi tri can xoa: "; cin >> vt;
    for(int i = vt + 1; i < n; i++){
        arr[i - 1] = arr[i];
    }
    n--;
}

void XoaSinhVienDuoi5(value Array[], int &n){
    for(int i = 0; i < n; i++){
        if(Array[i].diemTrungBinh < 5){
            XoaSinhVienTheoDiem(Array, n, i);
            i--;
        }
    }
}

void swap(value &a, value &b){
    value temp = a;
    a = b; 
    b = temp;
}

void SapXepSinhVienTangdanTheoDiem(value Array[], int n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(Array[i].diemTrungBinh > Array[j].diemTrungBinh){
                swap(Array[i], Array[j]);
            }
        }
    }
}

void MENU(){
    value ds[100];
    int n, vt, ChucNang;
    float x;
    while(1){
        system("cls");
        cout << "1. Nhap danh sach thong tin sinh vien\n";
        cout << "2. Xuat danh sach thong tin sinh vien\n";
        cout << "3. Them sinh vien vao vi tri bat ky\n";
        cout << "4. Tim kiem sinh vien theo diem\n";
        cout << "5. Xoa sinh vien theo diem\n";
        cout << "6. Sap xep sinh vien theo diem\n";
        cout << "Nhap chuc nang: "; cin >> ChucNang; cin.ignore();
        if(ChucNang == 1){
            NhapDanhSachSinhVien(ds, n);
        }
        else if(ChucNang == 2){
            XuatDanhSachSinhVien(ds, n);
            system("pause");
        }
        else if(ChucNang == 3){
            ThemSinhVienVaoViTriBatKy(ds, n);
        }
        else if(ChucNang == 4){
            TimKiemSinhVienTheoDiem(ds, n);
            system("pause");
        }
        else if(ChucNang == 5){
            XoaSinhVienDuoi5(ds, n);
            XuatDanhSachSinhVien(ds, n);
            system("pause");
        }
        else if(ChucNang == 6){
            SapXepSinhVienTangdanTheoDiem(ds, n);
            XuatDanhSachSinhVien(ds, n);
            system("pause");
        }
        else{
            cout << "Sai chcu nang\n";
            system("pause");
        }
    }
}

int main(){
    MENU();
    system("pause");
    return 0;
}