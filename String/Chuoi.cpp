#include <iostream>
#include <string>
using namespace std;

// xóa kí tự tại vị trí bất kì
void xoaViTri(string &s, int vt){
    int len = s.length();
    for(int i = vt; i < len - 1; i++){
        s[i] = s[i + 1];
    }
    s[len - 1] = '\0'; // độ dài của chuỗi trừ đi 1
}

// xóa all khoảng trắng đầu
void xoaDau(string &s){
    while(true){ // lap vo tan dem khi s[o] khac khoang trang thi dung
        if(s[0] == 32){ // xoa ki tu tai vi tri dau 
            xoaViTri(s, 0);  
        }
        else{ // <=> if(s[i] != 32)
            break;
        }
    }
}
//xóa all khoảng trắng ở cuối
void xoaCuoi(string &s){
    int len = s.length();
    while(true){
        if(s[len - 1] == 32){ // xoa ki tu tai vi tri cuoi chuoi
            xoaViTri(s, (len - 1));
        }
        else{
            break;
        }
    }
}
// xóa khoảng trắng ở giữa
void xoaGiua(string &s){
    for(int i = 0; i <  s.length(); i++){
        if(s[i] == 32 && s[i + 1] == 32){ // neu ki tu dau = 32 or ki tu ke tiep = 32
            xoaViTri(s, i);
            i--;
        }
    }
}

void vietHoaChuDau(string &s){
    int len = s.length();
    for(int i = 0; i < len; i++){
        if(i == 0 || (i > 0 && s[i - 1] == 32)){ // th1: no la la chu cai dau tien
            if(s[i] >= 97 && s[i] <= 122){       // th2: no k phai la chu cai dau tien va truoc no la khoang trang
                s[i] -= 32;
            }
        }
    }
}

void XoaKhoangTrang(string &s){
    int len = s.length();
    for(int i = 0; i < len; i++)
		if(s[i]== ' ' && s[i + 1]== ' '){
			xoaViTri(s, i);
			i--;
		}
        // nếu s tại vị trí đầu tiên là khoảng trắng => xóa
    if(s[0] == ' '){
		xoaViTri(s, 0);
    }
    if(s[len - 1] == ' '){ // nếu s tại vị trí cuối cùng là khoảng trăng => xóa
		xoaViTri(s, len - 1);
    }
}
void vietThuong(string &s){
    for(int i = 0; i < s.length(); i++){
        if(s[i] >= 65 && s[i] <= 90){ // 65 - 90 la chu hoa
            s[i] += 32;
        }
    }
}
void vietHoa(string &s){
    for(int i = 0; i < s.length(); i++){
        if(s[i] >= 97 && s[i] <= 122){ // 97 - 122 la chu thuong
            s[i] -= 32;
        }
    }
}
void chuanHoaChuoi(string& a) {
	// xoa khoang trang dau
	while (a[0] == ' ') { // neu ptu dau = ktrang
		a.erase(a.begin() + 0); // arese(): ham xoa ; begin(): bat dau + vi tri
	}
	// xoa ktrang cuoi
	while (a[a.length() - 1] == ' ') { // ptu o cuoi = 32
		a.erase(a.begin() + a.length() - 1);
	}
	// xoa o giua
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == ' ' && a[i + 1] == ' ') { // neu 2 ktrang lien tiep nhau
			a.erase(a.begin() + i);
			i--;
		}
	}
	// chuan hoa ki tu
	if (a[0] >= 97 && a[0] <= 122) { // thuong thanh hoa
		a[0] -= 32;
	}
	for (int i = 1; i < a.length(); i++) {
		if (a[i] == ' ') {
			i++;
			if (a[i] >= 97 && a[i] <= 122) {
				a[i] -= 32;
			}
		}
		else {
			if (a[i] >= 65 && a[i] <= 90) {
				a[i] += 32;
			}   
		}
	}
}

int main(){
    string s = " Ky    tHUat      lap    trInh            c \n";
    cout << "Chuoi ban dau:" << s << endl;
    chuanHoaChuoi(s);
    cout << "Chuoi sau khi xoa: " << s << endl;
    
    return 0;
}