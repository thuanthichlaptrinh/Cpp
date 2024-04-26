#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

struct DATE{
    int ngay;
    int thang;
    int nam;
};
struct SinhVien{
    string mssv;
    string hoTen;
    string gioiTinh;
    string ngaySinh; // dd/mm/yyyy
    float diemTrungBinh;
    string hocLuc;

    void NhapSinhVien(){
        cout << "Nhap ma so sinh vien: "; cin.ignore(); (cin, mssv);
        cout << "Nhap ho va ten: "; getline(cin, hoTen);
        cout << "Nhap gioi tinh: "; getline(cin, gioiTinh);
        cout << "Nhap ngay sinh: "; getline(cin, ngaySinh);
        cout << "Nhap diem trung binh: "; cin >> diemTrungBinh;
    }
    void XuatSinhVien(){
        cout << "\nMa so sinh vien: " << mssv;
        cout << "\nho va ten: " <<hoTen;
        cout << "\nGioi tinh: " << gioiTinh;
        cout << "\nNgay sinh: " << ngaySinh;
        cout << "\nDiem trung binh: " << diemTrungBinh;
    }
};

void DocThongTinSinhVien(SinhVien ds[], int &n){
    ifstream f;
    f.open("QLSV_MANG.txt", ios_base::in);
    //f >> n; f.ignore();
    while(!f.eof()){
        //for(int i = 0; i < n; i++){
            SinhVien x;
            getline(f, x.mssv, ',');
            getline(f, x.hoTen, ',');
            getline(f, x.gioiTinh, ',');
            getline(f, x.ngaySinh, ',');
            f >> x.diemTrungBinh; cin.ignore();
            ds[n] = x;
            n++;
        //}
    }
    

    f.close();
}

int main(){
    SinhVien ds[100];
    int n = 0;
    DocThongTinSinhVien(ds, n);
    ds->XuatSinhVien();
    return 0;
}