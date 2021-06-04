// 求 1 ~ n mod p的逆元,阶乘
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 3e6+5;
ll f[maxn],c[maxn],inv[maxn];
int n,p;
void init(int n)
{
    f[0] = 1;
    for(int i = 1; i <= n; i++) f[i] = (i* f[i-1]) % p;
    inv[1] = 1;
    for(int i = 2; i <= n; i++) {
        inv[i] = (p-p/i)*inv[p%i]%p;
    }
    for(int i = 2; i <= n; i++) {
        inv[i] = inv[i]*inv[i-1]%p;
    }
}
ll qpow(ll a,ll b)
{
    if(b == 0) {
        return 1;
    }
    ll res = 1;
    while(b) {
        if(b & 1) {
            res = ( res * a)%p;
        }
        a  = (a*a)%p;
        b >>= 1;
    }
    return res%p;
}
int main()
{
    cin >> n >> p;
    c[0] = 1;
    for(int i = 1; i <= n; i++) {
        c[i] = (i*c[i-1])%p;
    }
    f[n] = qpow(c[n],p-2)%p;
    for(int i = n-1; i >= 1; i--) {
        f[i] = (f[i+1]*(i+1))%p;
    }
    for(int i = 1; i <= n; i++) {
        printf("%lld\n",(f[i]*c[i-1]%p));
    }
    return 0;
}