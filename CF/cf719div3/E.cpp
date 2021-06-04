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
#define int long long
const int maxn = 1e6 + 10;

int n,m;
char s[maxn];
void solve() {
	cin >> n;
	// string s;
	cin >> s + 1;
	s[n+1] = '.';
	int flag = 1;
	int l = -1,r = -1;
	int an = 0;
	for(int i = 1; i <= n; i++) {
		if(s[i] == '*') an++;
	}
	int p = 0;
	for(int i = 1; i <= n; i++) {
		if(s[i] == '*') {
			p++;
			if(p == (an+1)/2) {
				l = i;
				break;
			}
		}
	}
	if(an == n) {
		cout << 0 << "\n";
		return;
	}
	r  = l;
	int an1 = 0,an2 = 0;
	for(int i = l; i >= 1; i--) {
		if(s[i] == '*') {
			an1 += l-i;
			l--;
		}
	}
	for(int i = r; i <= n; i++) {
		if(s[i] == '*') {
			an2 += i - r;
			r++;
		}
	}
	cout << an1 + an2 << "\n";

}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	int T;
	cin >> T;
	while(T--) {
		solve();
	}	
	return 0;
}	