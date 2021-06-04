#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;

signed main(){
   cin >> n;
   int cnt = 0;
   if(n%4 == 0) {
       cout << (n/4)*2 << endl;
   }
   else {
       if(n%4 == 1 || n % 4 == 3)
        cout << (n/4)*2+1 << endl;
        else {
             cout << (n/4)*2+2 << endl;
        }
   }
   
   return 0;
}