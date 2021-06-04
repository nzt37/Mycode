#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn = 2e5 + 6;
int a[maxn];
void solve() 
{
    int n;
    cin >> n;
    int _n = n;
    int max_x = 0, maxp = 1;
    for(int p = 2; p*p <= n; p++) {
        if(n % p == 0) {
            int cnt = 0;
            while(n % p == 0) {
                cnt++;
                n /= p;
            }
            if( cnt > max_x) {
                max_x = cnt;
                maxp = p;
            }
        }
    }
    if(n > 1 && max_x < 1) {
        max_x = 1;
        maxp = _n;
    }
    cout << max_x << endl;
    for(int i = 0; i + 1 < max_x ; i++) {
        printf("%d ",maxp);
        _n /= maxp;
    }
    cout << _n << endl;
}
signed main()
{
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}