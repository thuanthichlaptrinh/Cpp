#include <bits/stdc++.h>
using namespace std;

struct SinhVien {
    string maSo;
    string hoTen;
    float KTLT, TRR, CTDL;
};

struct DanhSach {
    SinhVien *a[100];
    int n;
};

void NhapSinhVien(SinhVien &x){
    do{
        cout << "Nhap ma so sinh vien: "; fflush(stdin); getline(cin, x.maSo);
        if(x.maSo.length() > 20){
            cout << "Vui long nhap ma so khong qua 20 ki tu\n";
        }
    } while(x.maSo.length() > 20);

    do{
        cout << "Nhap ho ten: "; getline(cin, x.hoTen);
        if(x.hoTen.length() > 30){
            cout << "Vui long nhap ho ten khong qua 30 ki tu\n";
        }
    } while(x.hoTen.length() > 30);

    do{
        cout << "Nhap diem ky thuat lap trinh: "; cin >> x.KTLT;
        if(x.KTLT < 0 || x.KTLT > 10){
            cout << "Vui long nhap diem chinh xac !\n";
        }
    }while(x.KTLT < 0 || x.KTLT > 10);

    do{
        cout << "Nhap diem toan roi rac: "; cin >> x.TRR; 
        if(x.TRR < 0 || x.TRR > 10){
            cout << "Vui long nhap diem chinh xac !\n";
        }
    }while(x.TRR < 0 || x.TRR > 10);

    do{
        cout << "Nhap diem cau truc du lieu: "; cin >> x.CTDL; cin.ignore(); 
        if(x.CTDL < 0 || x.CTDL > 10){
            cout << "Vui long nhap diem chinh xac !\n";
        }
    }while(x.CTDL < 0 || x.CTDL > 10);
}

void XuatSinhVien(SinhVien x){
    cout << "\nMssv: " << x.maSo;
    cout << "\nHo ten: " << x.hoTen;
    cout << "\nDiem ky thuat lap trinh: " << x.KTLT;
    cout << "\nDiem toan roi rac: " << x.TRR;
    cout << "\nDiem cau truc du lieu: " << x.CTDL;
}

void NhapDanhSachSinhVien(DanhSach &ds){
    SinhVien *x = new SinhVien;
    NhapSinhVien(*x);
    ds.a[ds.n] = x;
    ds.n++;
}
void XuatDanhSachSinhVien(DanhSach ds){
    for(int i = 0; i < ds.n; i++){
        cout << "\nThong tin sinh vien thu " << i + 1;
        XuatSinhVien(*ds.a[i]);
    }
}

void GiaiPhongVungNho(DanhSach ds){
    for(int i = 0; i < ds.n; i++){
        delete ds.a[i];
    }
}

void Menu(DanhSach &ds){
    int choose;
    while(true){
        system("cls");
        cout << "\t\t1. Nhap danh sach sinh vien\n";
        cout << "\t\t2. Xuat danh sach sinh vien\n";
        cout << "\t\t0. Thoat chuong trinh\n";

        cout << "Nhap chuc nang: "; cin >> choose; cin.ignore();
        if(choose == 0){
            break;
        }
        else if(choose == 1){
            NhapDanhSachSinhVien(ds);
        }
        else if(choose == 2){
            XuatDanhSachSinhVien(ds);
            system("pause");
        }
        else{
            cout << "Sai chuc nang. Vui long nhap lai !\n";
            system("pause");
        }
    }
}

int main(){
    DanhSach ds;
    ds.n = 0;

    Menu(ds);
    GiaiPhongVungNho(ds);
    system("pause");
    return 0;
}