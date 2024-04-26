/*  ifstream: hỗ trợ đọc dữ liệu từ file về chương trình
    ofstream: hỗ trợ ghi dữ liệu từ chương trình vào file
    
    Cú pháp đọc file: 
    b1: khai báo biến
    ifstream f; 
   
    b2: mở file (ios_base::in)
    f.open("Ten duong dan", "che do lam viec")
    
    b3: xu ly file


    b4: dong file
    f.close();
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void docFileSoNguyen(ifstream &f){
    // b2: mo file
    f.open("INPUT.txt", ios_base::in);
    if(f.fail() == true){ // fail() == true: file k ton tai
        cout << "\nFILE khong ton tai !";
        return; // ket thuc chuong trinh
    }
    // b3: xu ly 
    int x;
    int y;
    f >> x; // doc du lieu tu file
    f >> y;
    cout << "tong = " << x + y << endl;
    // b4:
    f.close(); // dong file
}
void DocFile(int a[], int &n){
    ifstream f;
    f.open("INPUT.txt", ios_base::in);
    while(f.eof() == false){
        int x;
        f >> a[n];
        n++; 
    }
    f.close();
}
void GhiFile(ofstream &f){
    // b2: mo file
    f.open("OUTPUT.txt", ios_base::out);
    if(f.fail() == true){ // fail() == true: file k ton tai
        cout << "\nFILE khong ton tai !";
        return; // ket thuc chuong trinh
    }
    // b3: xu ly 
    int x;
    int y;
    f << x + y;
    
    // b4:
    f.close(); // dong file
}

int main(){
    ifstream f; // khai báo 1 cái biến f để đọc dữ liệu từ file
    ofstream fileIn;
    

    system("pause");
    return 0;
}