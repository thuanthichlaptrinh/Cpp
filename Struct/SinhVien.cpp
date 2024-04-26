/* thiết kế chương trình lưu trữ thông tin sinh viên biết:
    - mã số, họ tên, năm sinh, điểm trung bình

*/
#include <iostream>
#include <string>
using namespace std;


struct SinhVien{
    string maSo;
    string hoTen;
    int namSinh;
    float diemTb;
};
typedef SinhVien SV;

// nhap thong tin sinh vien
void nhapThongTin1SV(SV &sv){
    fflush(stdin);
    cout << "Ma so: "; getline(cin, sv.maSo);
    cout << "Ho ten: "; getline(cin, sv.hoTen);
    cout << "Nam sinh: "; cin >> sv.namSinh;
    cout << "Diem trung binh: "; cin >> sv.diemTb;
}

// xuat tt 1 sv
void xuatThongTin1SV(SV sv){
    cout << sv.maSo << "          " << sv.hoTen << "                    " << sv.namSinh << "          " << sv.diemTb << endl;
}

// nhap ds sv
void nhapDanhSachSV(SV ds[], int &slsv){
    do{
        cout << "Nhap so luong sinh vien: "; cin >> slsv;
    }while(slsv < 0);

    for(int i = 0; i < slsv; i ++){
        cout << "\n\t\tNhap thong tin sinh vien thu " << i + 1 << endl;
        nhapThongTin1SV(ds[i]);
    }
}

// xuat ds sv
void xuatDanhSachSV(SV ds[], int slsv){
    cout << "\n\t\tDanh sach sinh vien hien tai" << endl;
    for(int i = 0; i < slsv; i ++){
        xuatThongTin1SV(ds[i]);
    }
}


// tim sinh vien dua vao diem
void xuatSinhVienTheoDiem(SV ds[], int slsv, float dtb){
    cout << "Nhap diem can tim: " << endl; cin >> dtb;

    for(int i = 0; i < slsv; i++){
        if(ds[i].diemTb == dtb){
            cout << "\n\t\tThong tin sinh vien theo diem" << endl;
            xuatThongTin1SV(ds[i]);
        }
    }
}

// them vao vtri bat ky
void themSinhVienVaoViTriBatKy(SV ds[], int &slsv, int vt, SV x){
    for(int i = slsv - 1; i >= vt; i--){
        ds[i + 1] = ds[i];
    }
    ds[vt] = x;
    slsv++;
}

// xoa sinh vien 
void xoaThongTinSinhVien(SV ds[], int &slsv, int vt){
    for(int i = vt + 1; i < slsv; i++){
        ds[i - 1] = ds[i];
    }
    slsv--;
}

//  xoa sinh vien co dtb duoi 5
void xoaSinhVienDuoi5(SV ds[], int &slsv){
    for(int i = 0; i < slsv; i++){
        if(ds[i].diemTb < 5){
            xoaThongTinSinhVien(ds, slsv, i);
        }
    }
}


// sap xep ds sv tang dan theo dtb
void sapXepTangDan(SV ds[], int slsv){
    for(int i = 0; i < slsv - 1; i++){
        for(int j = i + 1; j < slsv; j++){
            if(ds[i].diemTb > ds[j].diemTb){
                SV temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}

int main(){
    SV ds[100], x;
    int slsv, vt;
    float dtb;
    nhapDanhSachSV(ds, slsv);

    sapXepTangDan(ds, slsv);
    xuatDanhSachSV(ds, slsv);

    system("pause");
    return 0;
}