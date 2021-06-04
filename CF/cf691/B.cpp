#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
void solve()
{
    cin >> n;
    int f[1001];
    f[1] = 4,f[2] = 4,f[3] = 12;
    int cnt = 2,cnt1 = 2;
    for(int i = 2; i <= n; i++) {
        if(i&1) {
            f[i] = f[i-2] + 4*(cnt1);
            cnt1++;
        }
        else {
            f[i] = cnt*cnt;
            cnt++;
        }
    }
   cout << f[n] << endl;
}
signed main(){
    int T = 1;
    while(T--) {
        solve();
    }
    return 0;
}