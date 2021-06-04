#include <bits/stdc++.h>
#define ll long long
#define int long long 
using namespace std;
const int mod = 1e9 + 7,N = 1010;
int n, x, pos;
int fac[1010],inv[1010];
inline ll _pow(ll x,ll p){
    ll ans=1;
    while(p){
        if(p&1) ans=ans*x%mod;
        p>>=1; x=x*x%mod;
    }
    return ans;
}
signed main()
{
    cin >> n >> x >> pos;
    int l = 0, r = n;
    int x1=0, x2=0, mid;
    while(l < r){
        mid = (l + r) >> 1;
        if(mid <= pos){
            l = mid + 1;
            x1 += (mid < pos);
        }else{
            r = mid;
            x2++;
        }
    }
    //cout << x1 << "ds" << x2 << endl;
    fac[0] = 1, inv[0] = 1;
    for(int i = 1 ; i <= n ; i++){
        fac[i] = (1ll*i*fac[i-1])%mod;
    }
    for(int i = 1 ; i <= n ; i++){
        inv[i] = _pow(fac[i],mod-2);
    }
    if(x - 1 < x1 || n - x < x2 || n - 1 - x1 - x2 < 0){
        cout << 0 << endl;
    }
    else{
        ll ans = fac[x-1]*_pow(fac[x-1-x1],mod-2)%mod*fac[n-x]%mod*_pow(fac[n-x-x2],mod-2)%mod*fac[n-1-x1-x2];
        cout << ans%mod << endl;
    }
    return 0;
}
