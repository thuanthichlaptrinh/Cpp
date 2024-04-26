#include <iostream>
using namespace std;

/* KHUON MAU HAM (FUNCTION TEMPATE) */
template <class p1, class p2> // p1, p2 dang dai dien cho kieu du lieu tong quat
p1 TimMax(p1 x, p2 y){
    if(x > y){
        return x;
    }
    else if(x < y){
        return y;
    }
    return x;
}

int main(){
    int a = 5, b = 10;
    float x = 5.5, y = 10.3;

    cout << TimMax(a, b) << endl;
    cout << TimMax(x, y) << endl;

    system("pause");
    return 0;
}