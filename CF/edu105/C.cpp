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

const int maxn = 2e5 + 10;

int n,m;
int a[maxn],b[maxn];
void solve() {
	cin >> n >> m;
	int cnt1 = 0,cnt2 = 0;
	queue<int> q;
	set<int> s;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] < 0) cnt1 = i;
	}
	for(int i = 1; i <= m; i++) {
		cin >> b[i];
		if(b[i] < 0) cnt2 = i;
		s.insert(b[i]);
	}
	for(int i = 1; i <= cnt1; i++) {
		if(s.find(a[i]) != s.end()) {
			ans++;
			vis[i] = 1;
		}
		else {
			vis[i] = 0;
		}
	}
	int ans = 0; 
	int cnt = 0;
	int last = cnt;
	for(int i = cnt2,j = cnt1; i >= 1; i--) {
		while( j && a[j] >= b[j]) {
			if(vis[j]) ans--;
			cnt++,j--;
		}
		while(b[i] + cnt-1 < b[last]) last--;
		ans = max(ans,last-i+1);
	}
	int ans1 = 0;
	for(int i = )
	cnt = 0;
	for(int i = cnt2 + 1,last = cnt2 + 1,j = cnt1 + 1; i <= m; i++) {
		while(j <= n && a[j] <= b[i]) cnt++,j++;
		while(last <= m && b[i]-cnt+1 > b[last]) last++;
		ans1 = max(ans1,i-last+1);
	}
	cout << ans+ans1 << "\n";

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	int T;
	cin >> T;
	while(T--) {
		solve();
	}	
	return 0;
}