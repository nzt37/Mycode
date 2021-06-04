#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 6;
#define int long long
int p;
int f[maxn];
int n,m;
int qpow(int a,int b)
{
    int ans = 1;
    a%=p;
    while(b) {
        if(b&1) ans = (ans*a)%p;
        b >>= 1;
        a = (a*a) % p;
    }
    return ans%p;
}
int C(int n,int m)
{
  if(m > n) return 0;
    return f[n]*(qpow(f[n-m]*f[m],p-2)) % p;
}
int lucas(int n,int m)
{
    if(m == 0) return 1;
    return (C(n%p,m%p)*lucas(n/p,m/p)) % p;
}
void solve()
{
    
    cin >> n >> m >> p;
    f[0] = 1;
    for(int i = 1; i <= p; i++) f[i] = (i*f[i-1])%p;
    cout << lucas(n+m,n)%p << endl;
}
signed main(){
   int T;
   cin >> T;
    

   while(T--) {
       solve();
   }
    return 0;
}