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
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("qqglb")
#define y1 yzang
using namespace std;

const int maxn = 2e5 + 10;
int ans[maxn];
int n,m;
struct node{
	int maxxx,minnn,w;
}a[maxn],b[maxn];
void solve() {
	cin >> n >> m;
	string s;
	cin >> s;
	// std::vector<node> a(n);
	int now = 0;
	int maxx = 0,minn = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == '-') now -= 1;
		if(s[i] == '+') now += 1;
		maxx = max(maxx,now);
		minn = min(minn,now);
		a[i].maxxx = maxx;
		a[i].minnn = minn;
		a[i].w = now;
	}
	// std::vector<node> b(n);
	// std::vector<int> ans(m);
	maxx = 0,minn = 0;
	now = 0;
	for(int i = n-1; i >= 0; i--) {
		if(s[i] == '-') now -= 1;
		if(s[i] == '+')now += 1;
		maxx = max(maxx,now);
		minn = min(minn,now);
		b[i].maxxx = now - minn;
		b[i].minnn = now - maxx;
		b[i].w = 0;
	}
	a[n].maxxx = a[n].minnn = 0;
	b[n].maxxx = b[n].minnn = 0;
	for(int i = 0; i < m; i++) {
		int l,r;
		maxx = 0,minn = 0;
		cin >> l >> r;
		l--,r--;
		l--,r++;
		if(l >= 0) {
			maxx = max(a[l].maxxx,(a[l].w + b[r].maxxx));
			minn = min(a[l].minnn,a[l].w + b[r].minnn);
		}
		else {
			maxx = b[r].maxxx;
			minn = b[r].minnn;
		}
		
		ans[i] = maxx-minn + 1;
	}
	for(int i = 0; i < m; i++) {
		cout << ans[i] << "\n";
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	int T;
	cin >> T;
	while(T--) {
		solve();
	}	
}