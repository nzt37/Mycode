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
void solve()  {
	cin >> n;
	string s;
	cin >> s;
	std::vector<int> p[2];
	std::vector<int> an(n+1);
	p[s[0]-'0'].PB(1);
	an[0] = 1;
	int ans = 1;
	for(int i = 1; i < n; i++) {
		if(p[(s[i]-'0')^1].empty()) {
			an[i] = ++ans;
			p[(s[i]-'0')].PB(ans);
		}
		else {
			int tmp = p[(s[i]-'0')^1][p[(s[i]-'0')^1].size()-1];
			an[i] = tmp;
			p[(s[i]-'0')^1].pop_back();
			p[(s[i]-'0')].PB(tmp);
		}
	}
	cout << ans << "\n";
	for(int i = 0; i < n; i++) {
		cout << an[i] << " \n"[i==n-1];
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
	return 0;
}