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
void solve() {
	int x;
	cin >> n >> m >> x;
	std::vector<int> h(n);
	std::vector<int> a(m);
	set<pii> p;
	for(int i = 0; i < m; i++) {
		p.emplace(0,i);
	}
	for(int i = 0; i < n; i++) {
		cin >> h[i];
	}
	std::vector<int> an(n);
	for(int i = 0; i < n; i++) {
		auto [v,j] = *p.begin();
		p.erase(*p.begin());
		an[i] = j;
		a[j] += h[i];
		p.emplace(a[j],j);
	}
	cout << "YES" << "\n";
	for(int i = 0; i < n; i++) {
		cout << an[i] + 1 << " \n"[i == n-1];
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