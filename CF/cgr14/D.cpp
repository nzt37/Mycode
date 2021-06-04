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
	int l,r;
	cin >> n >> l >> r;
	std::vector<int> x(n);
	std::vector<int> y(n);
	for(int i = 0; i < n; i++) {
		int an;
		cin >> an;
		if(i < l) x[--an]++;
		else y[--an]++;
	}
	for(int i = 0; i < n; i++) {
		int m = min(x[i],y[i]);
		x[i] -= m;
		y[i] -= m;
	}
	int an1 = accumulate(all(x),0);
	int an2 = accumulate(all(y),0);
	if(an1 < an2) {
		swap(an1,an2);
		swap(x,y);
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		while(an1  > an2 && x[i] >= 2) {
			ans++;
			x[i] -= 2;
			an1 -= 2;
		}
	}
	ans += an1;
	cout << ans << "\n";

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