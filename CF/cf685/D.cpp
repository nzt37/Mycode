#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;
const int maxn = 5050;

void solve()
{
    int n,k;
    cin >> n >> k;
    int p = 0,q = 0;
    int cnt = 1;
    while(p*p+q*q <= n*n){
        if(cnt&1) {
            p += k;
            cnt++;
        }
        else {
            q += k;
            cnt++;
        }
        
    }
    if(cnt&1) {
        cout << "Ashish" << endl;
    }
    else {
        cout << "Utkarsh" << endl;
    }
}
signed main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}