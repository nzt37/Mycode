#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a,b;
    cin >> a >> b;
    string sum = "";
    int n = a.size(),m = b.size();
    int l = abs(n-m);
    if( n > m) {
        for(int i = 0; i < l; i++) {
            cout << a[i];
            b = " " + b;
            sum += a[i];
        }
    }
    else if( n < m) {
        for(int i = 0; i < l; i++) {
            cout << b[i];
            a = " " + a;
            sum += b[i];          
        }
    }
    int flag = 0;
    for(int i = l; i < max(a.size(),b.size()); i++) {
        int x = a[i] - 48;
        int y = b[i] - 48;
        int ok = 0;
        for(int i = 1; i <= 9; i++) {
            if(sum.find(i+48)!=-1){ 
               // cout << i << "dsadsad" << endl;
                ok = 1;
                break;
            }
        }
       // cout << sum << " ds" <<ok <<endl;
        if(!ok && (x + y) % 10 == 0) continue;
        cout << (x+y)%10;
        flag = 1;
        sum += '0' + (x+y)%10;
    }
    if(!flag) {
        cout << 0 << endl;
    }
    return 0;
}