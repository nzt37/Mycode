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
int a[maxn];
void solve() {
	cin >> n;
	std::vector<int> v;
	std::vector<int> b;
	int an = 0;
	int flag = 0;
	for(int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		// cin >> a[i];
		if(x <= 0) {
			v.PB(x);
			an++;
		}
		else {
			b.PB(x);
			flag = 1;
		}
	}
	if(an)sort(all(v));
	// cout << "2e1" << "\n";
	int mx = INT_MAX;
	if(flag) sort(all(b));
	for(int i = 1; i < (int)v.size(); i++) {
	    mx = min(mx,abs(v[i] - v[i-1]));
	}
	// cout << mx << "\n";
	if(flag && mx >= b[0]) {
		an++;
	}
	cout << an << "\n";
	
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