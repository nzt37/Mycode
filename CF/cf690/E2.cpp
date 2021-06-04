#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int maxn = 2e5 + 6;
const int mod = 1e9+7;
int f[maxn],a[maxn];
int qpow(int a, int b)
{
    int ans = 1;
    a %= mod;
    while(b) {
        if(b&1) ans = ans * a % mod;
        b >>= 1;
        a = a*a % mod;
    }
    return ans % mod;
}
int C(int n,int m)
{
    if(n < m) return 0;
    return f[n] * qpow(f[m]*f[n-m],mod-2);
}
void solve()
{
    int k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    int ans = 0;
    for(int i = m; i <= n; i++) {
        int pos = lower_bound(a+1,a+1+n,a[i]-k) - a;
        int num = i - pos + 1;
        ans += C(num-1,m-1);
        ans %= mod;
    }
    cout << ans << endl;
}
signed main(){
    int T;
    f[0] = 1;
    for(int i = 1; i < maxn; i++) {
        f[i] = f[i-1] * i % mod;
    }
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
