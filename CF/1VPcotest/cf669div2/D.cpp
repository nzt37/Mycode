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

const int maxn = 3e5 + 10;

int n,m;
int a[maxn],dp[maxn];
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	stack<int> p,q;
	CLR(dp,0x3f3f3f3f);
	dp[1] = 0;
	for(int i = 1; i <= n; i++) {
		dp[i] = min(dp[i],dp[i-1] + 1);
		while(!p.empty() && a[p.top()] > a[i]) {
			dp[i] = min(dp[i],dp[p.top()] + 1);
			p.pop();
		}
		if(!p.empty()) {
			dp[i] = min(dp[i],dp[p.top()] + 1);
		}
		if(!p.empty() && a[p.top()] == a[i]) {
			p.top() = i;
		}
		else
		p.push(i);
		while(!q.empty() && a[q.top()] < a[i]) {
			dp[i] = min(dp[i],dp[q.top()] + 1);
			q.pop();
		}
		if(!q.empty()) {
			dp[i] = min(dp[i],dp[q.top()] + 1);
		}
		if(!q.empty() && a[q.top()] == a[i]) {
			q.top() = i;
		}
		else
		q.push(i);
	}
	cout << dp[n] << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

	int T = 1;
	// cin >> T?;
	while(T--) {
		solve();
	}
	return 0;
}