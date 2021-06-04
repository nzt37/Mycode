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
// #define mid ((r+l)>>1)
// #define lson p<<1,l,mid
// #define rson p<<1|1,mid+1,r
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug cout << "dsdsdsdsd" << "\n";
#define y1 yzang
using namespace std;

const int maxn = 2e5 + 10;

int n,m;
int a[maxn],c[maxn],sum[maxn],f[1<<20],dp[1<<20];
inline int check(int x, int cha) {
    int l = cha, r = m, mid;
    int ans =0 ;
    while(l <= r) {
      mid = (l + r) >> 1;
      if(sum[mid] - sum[cha - 1] <= x) {l = mid + 1; ans = mid;}
      else r = mid -1 ;
    }
    return ans;
}
int main() {
    cin >> n >> m;
    int tot = 0,ans = INT_MAX;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        tot += a[i];
    }
    for(int i = 1; i <= m; i++) {
        cin >> c[i];
        // if(i == 0) sum[i] = c[i];
         sum[i] = sum[i-1] + c[i];
    }
    for(int i = 0; i < (1 << n); i++) {
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                int x = (i ^ (1 << j));
                int an = check(a[j],dp[x]+1);
                if(an > dp[i]) {
                    dp[i] = an;
                    f[i] = f[x] + a[j];
                }
                if(dp[i] == m) {
                    ans = min(ans,f[i]);
                }
            }
        }
    }
    cout << (tot - ans < 0 ? -1 : tot - ans) << "\n";
    return 0;
}