#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define mid ((r+l)>>1)
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define BR printf("--------------------\n")
#define debug(x) std::cerr << #x << '=' << x << '\n'
#define y1 yzang
using namespace std;
#define int long long
const int maxn = 2e5 + 10;
const int p = 1e9 + 7;
int n,m;
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
void solve() {
    int k;
    cin >> n >> k;
    cout << qpow(n,k) % p << "\n";
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        solve();
    }    
    return 0;
}