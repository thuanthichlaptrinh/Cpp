#include <iostream>
using namespace std;

/* ================ NẠP CHỒNG HÀM (FUNCTION OVERLOADING) ================ */
int TimMax(int x, int y){ // ham tim gia tri lon nhat cua 2 so nguyen
    if(x > y){
        return x;
    }
    else if(x < y){
        return y;
    }
    return x;
}
float TimMax(float x, float y){ // ham tim gia tri lon nhat cua 2 so thuc
    if(x > y){
        return x;
    }
    else if(x < y){
        return y;
    }
    return x;
}

/* ===================== HAM XU LI CHINH ===================== */
int main(){
    int x = 5.3, y = 10.4;
    float a = 5.3, b = 10.4;
    cout << "Max so nguyen: " << TimMax(x, y) << endl;
    cout << "Max so thuc: " << TimMax(a, b) << endl;

    system("pause");
    return 0;
}