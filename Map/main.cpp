#include <iostream>
#include <set>
#include <map>
using namespace std;

// key không được trùng nhau
// (key, value)

    /* dem so lan xuat hien cac phan tu trong mang, sau do in ra kem theo tan suat cua no
    8
    1 1 2 1 3 5 1 -4
    Output: 
     1 xuất hiện 4 lần
     2 xuất hiện 1 lần
     3 xuất hiện 1 lần
    -4 xuất hiện 1 lần
     5 xuất hiện 1 lần */


int main(){
    /* map<int, int> mp; // map <kiểu dữ liệu cho key, kiểu dữ liệu cho value> mp
    mp[100] = 200; // thêm (100, 200) vào trong map
    mp[200] = 300; // thêm (200, 300) vào trong map
    mp.insert({400 , 500});  // thêm (400, 500) vào trong map

    // duyệt maps
    // cách 1:
    for(pair<int, int> x : mp){
        cout << x.first << " " << x.second << endl; // first = key; second = value
    }
    
    if(mp.find(100) != mp.end()){
        cout << "YES\n";
    }
    else{ // trả về mp.end() => không tìm thấy
        cout << "NO\n";
    }


    mp.erase(100);
    cout << "\nSau khi xoa: \n";
    for(pair<int, int> x : mp){
        cout << x.first << " " << x.second << endl; // first = key; second = value
    } */

    map<int, int> mp;
    cout << "\nNhap so luong phan tu: ";
    int n; cin >> n; 

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        mp[x]++;
    }

    for(pair<int,int> x : mp){
        cout << x.first << "\t" << x.second << endl;
    }
    return 0;
}