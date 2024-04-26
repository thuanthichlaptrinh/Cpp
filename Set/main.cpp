#include <bits/stdc++.h>
#include <set>
using namespace std;

// set: O(logn)
// size
// insert
// find
// count
// erase
/*
dem so tu
5 
java
python
java
lap trinh
python

*/

// set: cac phan tu k trung nhau
// multiset: cac phan tu co the trung nhau
int main(){
    int n;
    cout << "Nhap so luong phan tu set: "; cin >> n; cin.ignore();
    set<string> s;
    for(int i = 0; i < n; i++){
        string x;
        cout << "Nhap x: "; getline(cin, x);
        s.insert(x);
    }
    cout << "So tu khac nhau: "<< s.size() << endl;
    for(auto x : s){
        cout << x << "  ";
    }
    cout << endl;
    //cout << *s.begin() << endl; // truy cập đến phần tử nhỏ nhất trong set
    //cout << *s.rbegin() << endl; // truy cập đến phần tử cuối cùng trong set

    system("pause");
    return 0;
}