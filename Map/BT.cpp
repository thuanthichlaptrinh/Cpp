#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t; cin >> t; cin.ignore();
    map<string, int> mp;
    while(t--){
        string username;
        getline(cin, username);
        if(mp.find(username) == mp.end()){
            cout << username << endl;
        }
        else{
            cout << username << mp[username] << endl;
        }
        mp[username]++;
    } 
    system("pause");
    return 0;
}