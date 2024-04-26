#include <iostream>
#include <string>
using namespace std;

struct SinhVien{
    string hoTen;
    string maSo;
    float diemTB;
};

void nhapThongTin1SV(SinhVien &sv);
void xuatThongTin1SV(SinhVien sv);
void nhapDanhSachSV(SinhVien ds[], int &slsv);
void xuatDanhSachSV(SinhVien ds[], int slsv);
int inSinhVienTheoDiem(SinhVien ds[], int slsv);
void xuatSinhVienCoDtbThapNhat(SinhVien ds[], int slsv);
void menu();


int main(){
    menu();
    
    system("pause");
    return 0;
}

void nhapThongTin1SV(SinhVien &sv){
    do{ // bat dieu kien nhap ten
        fflush(stdin);
        cout << "Ho ten: "; getline(cin, sv.hoTen);
        if(sv.hoTen.length() > 30){
            cout << "Ho ten toi da 30 ki tu !\n";
        }
    }while((sv.hoTen.length() > 30));

    do{ // bat dieu kien nhap ms
        fflush(stdin);
        cout << "Ma so: "; getline(cin, sv.maSo);
        if(sv.maSo.length() > 10){
            cout << "Ma so toi da 10 ki tu !\n";
        }
    }while(sv.maSo.length() > 10);

    do{
        cout << "Diem trung binh: "; cin >> sv.diemTB;
        if(sv.diemTB < 0 || sv.diemTB > 10){
            cout << "Nhap dtb trong doan (0;10] !\n";
        }
    }while(sv.diemTB < 0 || sv.diemTB > 10);
}
void xuatThongTin1SV(SinhVien sv){
    cout << sv.hoTen << "       " << sv.maSo << "         " << sv.diemTB << endl;
}
void nhapDanhSachSV(SinhVien ds[], int &slsv){
    cout << "Nhap so luong sinh vien: "; cin >> slsv;
  
   for(int i = 0; i < slsv; i ++){
        cout << "\n\t\tNhap thong tin sinh vien thu " << i + 1 << endl;
        nhapThongTin1SV(ds[i]);
    }
}
void xuatDanhSachSV(SinhVien ds[], int slsv){
    for(int i = 0; i < slsv; i++){
        xuatThongTin1SV(ds[i]);
    }
}
int inSinhVienTheoDiem(SinhVien ds[], int slsv){
    int diemMax = ds[0].diemTB;
    for(int i = 0; i < slsv; i++){
        if(ds[i].diemTB > diemMax){
            diemMax = ds[i].diemTB;
        }
    }
    return diemMax;
}
void xuatSinhVienCoDtbThapNhat(SinhVien ds[], int slsv){
    // duyet va tim ra dtb thap nhat
    int diemMin = ds[0].diemTB;
    for(int i = 0; i < slsv; i++){
        if(ds[i].diemTB < diemMin){
            diemMin = ds[i].diemTB;
        }
    }
    //b2: 
    for(int i = 0; i < slsv; i++){
        if(ds[i].diemTB == diemMin){
            xuatThongTin1SV(ds[i]);
        }
    }
}

void menu(){
    SinhVien x; // 1 sv
    SinhVien ds[100]; // 100 sv
    int slsv, chucNang;
    while(true){
        system("cls");
        cout << "1. Nhap danh sach sinh vien\n";
        cout << "2. Xuat danh sach sinh vien\n";
        cout << "3. In sinh vien co dtb cao nhat\n";
        cout << "4. xuat ds sinh vien co dtb thap nhat\n";
        
        cout << "\nNhap chuc nang: "; cin >> chucNang;
        switch (chucNang){
        case 0:
            break;
        case 1: 
            nhapDanhSachSV(ds, slsv);
            break;
        case 2:
            xuatDanhSachSV(ds, slsv);
            system("pause");
            break;
        case 3:
            cout << "Sinh Vien co dtb cao nhat la: " << inSinhVienTheoDiem(ds, slsv) << endl;
            system("pause");
            break;
        case 4: 
        cout << "\n\t\tDanh sach sinh vien co dtb thap nhat" << endl;
            xuatSinhVienCoDtbThapNhat(ds, slsv);
            system("pause");
            break;
        default:
            cout << "Sai chuc nang. Vui long nhap lai!\n";
            system("pause");
            break;
        }
    }
}










