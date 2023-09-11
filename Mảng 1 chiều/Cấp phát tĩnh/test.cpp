#include <iostream>
#include <fstream>
using namespace std;

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

void XuatMang(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << "  ";
    }
}

int main(){
    int a[10];
    int n = 0;
    DocFile(a, n);
    XuatMang(a, n);
    return 0;
}