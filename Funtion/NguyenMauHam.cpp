#include <iostream>
using namespace std;

/* KHAI BAO NGUYEN MAU HAM */
int UCLN(int a, int b);
int BCNN(int a, int b);

/* HAM XU LI CHINH */
int main(){
    int a = 5, b = 7;
    cout << "BCNN: " << BCNN(a, b);
    
    system("pause");
    return 0;
}

/* DINH NGHIA - CAI DAT CODE XU LI */
// ham tim UCLN
int UCLN(int a, int b){
    while(a != b){
        if(a > b){
            a -= b;
        }
        else{
            b -= a;
        }
    }
    return a;
}
// ham tim BCNN
int BCNN(int a, int b){
    return (a * b) / UCLN(a, b);
}












