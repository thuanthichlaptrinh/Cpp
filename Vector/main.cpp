#include <iostream>
#include <vector>
using namespace std;

void XuatMangVector(vector<int> Array){
    for(int i = 0; i < Array.size(); i++){ // duyệt qua tất cả các phần tử hiện có trong vector
        cout << Array.at(i) << " "; // hàm at(): tương đương Array[i]
    }
    cout << endl;
}

int main(){
    vector<int> Array; // khai báo mảng vector chứa các số nguyên
    for(int i = 1; i <= 5; i++){
        Array.push_back(i); // thêm phần tử i vào cuối mảng vector
    }
    /* ================= CÁC HÀM TRONG VECTOR =================
    Array.resize(5); // cấp phát cho mảng vector chứa 5 phần tử
    Array.resize(3); // co mảng vector lại còn 3 phần tử
    Array.resize(10); // dãn mảng vector ra thành 5 phần tử  
    Array.pop_back(); // xóa phần tử cuối cùng trong vector
    cout << "\nKich thuc cua vector: " << Array.capacity();
    cout << "\nSo luong phan tu vector chua duoc: " << Array.max_size();
    cout << "\nPhan tu dau tien trong vector: " << Array.front();
    cout << "\nPhan tu cuoi cung trong vector: " << Array.back(); 
    Array.clear(); // xóa hết tất cả phần tử hiện có trong vector */

    /* thêm xóa phần tử tại vị trí bất kỳ
    Array.erase(Array.begin() + 2); // xóa phần tử tại vị trí số 2
    Array.insert(Array.begin() + 2, 69); // thêm phần tử 69 vào vị trí số 2 */
    vector <int> x; // Khai báo mảng vector x
    for(int i = 6; i <= 10; i++){
        x.push_back(i);
    }

    cout << "\nvector array: "; XuatMangVector(Array);
    cout << "\nvector x: "; XuatMangVector(x);

    Array.swap(x); // hoán đổi 2 cái vector cho nhau
    cout << "\n\t\tSau khi hoan doi 2 vector\n";
    cout << "\nvector array: "; XuatMangVector(Array);
    cout << "\nvector x: "; XuatMangVector(x);
    system("pause");
    return 0;
}