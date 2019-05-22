#include <iostream>
#include <string> 
using namespace std;
 
void swp(string& a, string& b){
    string t;
    t = a;
    a = b;
    b = t;
}
 
string add(string a, string b){
     
    if(a.length() < b.length()){
        swp(a, b);
    }
     
    int del = a.length() - b.length();
    for(int i = 0; i < del; i++){
        b = '0' + b;
    }
     
    int len = a.length();
    int tmp = 0;
    for(int i = len - 1; i >= 0; i--){
        int ta = a[i] - '0';
        int tb = b[i] - '0';
        tmp += ta + tb;
        a[i] = '0';
        a[i] += tmp%10;
        tmp /= 10;
    }
     
    if(tmp > 0){
        a = char(tmp + '0') + a;
    }
    return a;
}
 
string sub(string a, string b){
    int flag = 0;
    if(a.length() < b.length()){
        swp(a, b);
        flag = 1;
    }
    if(a.length() == b.length() && a[0] < b[0]){
        swp(a, b);
        flag = 1;
    }
     
    int del = a.length() - b.length();
    for(int i = 0; i < del; i++){
        b = '0' + b;
    }
     
    int len = a.length();
    for(int i = len - 1; i >= 0; i--){
        int ta = a[i] - '0';
        int tb = b[i] - '0';
        if(ta < tb){
            a[i-1]--;
            ta += 10;
        }               
        a[i] = '0';
        a[i] += ta - tb;        
    }
     
    int p = 0;
    while(a[p++] == '0');
    a = a.substr(p-1);
     
    if(flag){
        a = '-' + a;
    }
    return a;
}
 
string mul(string a, string b){
    string ans = "0";
     
    if(a.length() < b.length()){
        swp(a, b);
    }
     
    if(b.length() == 1 && b[0] == '0'){
        return ans;
    }
     
    int lenb = b.length();
    int lena = a.length();
    string zer = "";
    for(int i = lenb-1; i >= 0; i--){
        string str = "";
        int tmp = 0;
        int tb = b[i] - '0';
        for(int j = lena-1; j >= 0; j--){
            int ta = a[j] - '0';
            tmp += ta * tb;
            str = char('0' + tmp%10) + str;
            tmp /= 10;          
        }
        if(tmp > 0){
            str = char(tmp + '0') + str;
        }       
        str += zer;
        zer += "0";
        ans = add(ans, str);
    }
     
    return ans;
}
 
 
int main(){
     
    string a, b;
    cin >> a >> b;
    //cout << add(a, b);
    //cout << sub(a, b);
    cout << mul(a, b);
     
    return 0;
}
