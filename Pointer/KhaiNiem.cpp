#include <iostream>
using namespace std;

int main(){
    /* int a = 6;
    int *b; // con trỏ b chỉ trỏ đến các biến thuộc kiểu dữ liệu int
    // dấu & là toán tử địa chỉ
    b = &a; // cho con trỏ b trỏ đến biến a, con trỏ b đang giữ địa chỉ của biến a
    int *c;
    c = b; // con trỏ c đang trỏ đến biến b (ko cần & vì đây là 2 con trỏ)
    
    cout << "Gia tri cua bien a: " << a << endl;
    cout << "Dia chi cua bien a: " << &a << endl;
    //a++; // giá trị của a thay đổi thì giá trị của b cũng thay đổi theo
    (*b)++; // thay đổi giá trị biến b thì biến a cũng thay đổi theo
    // *b++ nếu k bỏ vào ngoặc thì nó sẽ tăng 1 ô nhớ của biến b lên 1 ô  
    cout << "\nGia tri cua con tro b: " << *b << endl; // * là toán tử lấy giá trị của con trỏ b
    cout << "Dia chi cua con tro b: " << &b << endl; // địa chỉ của biến b riêng biệt a
    cout << "Mien gia tri cua con tro b: " << b << endl; // miền giá trị của con trỏ b là địa chỉ của biến a

    cout << "\nGia tri cua con tro c: " << *c << endl; // * là toán tử lấy giá trị của con trỏ c
    cout << "Dia chi cua con tro c: " << &c << endl; // địa chỉ của biến c riêng biệt b
    cout << "Mien gia tri cua con tro c: " << c << endl; // miền giá trị của con trỏ c là địa chỉ của biến a
    */
    int *b; // khi khai báo con trỏ bộ nhớ chỉ cấp phát địa chỉ cho con trỏ mà ko có cấp phát vùng nhớ cho con trỏ
    cout << "\nKich thuoc: " <<sizeof(b);

    int a = 10;
    void *t; // con trỏ vô kiểu: trỏ đến mọi kiểu dữ liệu
    t = &a; 
    cout << "\nGia tri cua bien con tro: " << (int*)t; // phải ép kiểu cho con trỏ, có nghĩa là con trỏ đang trỏ đến biên int*

    return 0;
}