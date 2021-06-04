#include <bits/stdc++.h>
using namespace std;

int n,m;

void solve()
{
    int a,b,c;
    cin >> a >> b >> c;
    int sum = a+b+c;
    int cnt  = sum/9;
    if(sum%9 == 0 && (a >= cnt && b >= cnt && c >= cnt)) {
        cout << "YES" << "\n";
    }
    else {
        cout << "NO" << "\n";
    }
}
int main(){
    int T;
    cin >> T;
    while(T--) {
        solve(); 
    }
    return 0;
}