#include <bits/stdc++.h>
#define mod 998244353
#define int long long
using namespace std;
const int maxn = 2e5 + 6;
int f[maxn];
int qpow(int a, int b)
{
    if(b == 0) return 1;
    int res = 1;
    while(b) {
        if(b&1) res = (res*a)%mod;
        a  = (a*a)%mod;
        b >>= 1;
    }
    return res%mod;
}
signed main()
{
    int n;
    cin >> n;
    f[1] = f[2] = 1;
    for(int i = 2; i <= n; i++) {
        f[i] = (f[i-1] + f[i-2]) % mod;
    }
    printf("%lld",(f[n]*qpow(qpow(2,n),mod-2)%mod)%mod);
    return 0;
}