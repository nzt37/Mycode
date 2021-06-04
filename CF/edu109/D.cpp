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

const int maxn = 2e5 + 10;

int n,m;
int dp[1001][1001];
int a[maxn];
int cnt1[maxn],cnt2[maxn];
void solve() {
	cin >> n;
	int an1 = 0,an2 = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[0][i] = 0;
		if(a[i] == 1) {
			cnt1[++an1] = i;
		}
		else {
			cnt2[++an2] = i;
		}
	}
	CLR(dp,0);
	for(int i = 1; i <= an1; i++) {
		for(int j = min(i,an2); j >= 1; j--) {
			dp[i][j] = min(dp[i][j-1],dp[i-1][j-1]+abs(cnt1[i] - cnt2[j]));
		}
	}
	cout << dp[an1][an2] << "\n";

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	int T = 1;
	// cin >> T;
	while(T--) {
		solve();
	}	
	return 0;
}