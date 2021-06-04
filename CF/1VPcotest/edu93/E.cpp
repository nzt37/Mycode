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
#define debug cout << "dsdsdsdsd" << "\n";
#define y1 yzang
using namespace std;
// #define int long long
const int maxn = 2e3 + 10;

int n,m;
int a[maxn],b[maxn],c[maxn];
int dp[205][205][205];
bool cmp(int a,int b) { return a > b;}
void solve() {
	int B;
	// CLR(dp,0);
	cin >> n >> m >> B;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= m; i++) cin >> b[i];
	for(int i = 1; i <= B; i++) cin >> c[i];
	int ans = 0;
	sort(a+1,a+1+n,cmp);
	sort(b+1,b+1+m,cmp);
	sort(c+1,c+1+B,cmp);
	dp[1][1][0]=a[1]*b[1];
	dp[1][0][1]=a[1]*c[1];
	dp[0][1][1]=b[1]*c[1];
	// int ans = 0 ;
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= m; j++) {
			for(int k = 0; k <= B; k++) {
				if(!((i+j+k)&1) && (i+j>=k)&&i+k>=j&&j+i>=k) {
					if(dp[i-1][j-1][k]&&i&&j) {
						dp[i][j][k] = max(dp[i][j][k],dp[i-1][j-1][k] + a[i]*b[j]);
					}
					if(i&&k&&dp[i-1][j][k-1]) {
						dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k-1]+a[i]*c[k]);
					}
					if(dp[i][j-1][k-1]&&k&&j) {
						dp[i][j][k] = max(dp[i][j][k],dp[i][j-1][k-1]+b[j]*c[k]);
					}
					ans = max(ans,dp[i][j][k]);
				}
			}
		}
	}
	cout << ans << "\n";
 }
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	int T = 1;
	// cin >> T;
	while(T--) {
		solve();
	}	
	return 0;
}