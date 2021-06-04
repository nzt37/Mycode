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

const int maxn = 1e7 + 10;

int n,m;
int d[maxn];
int an[maxn];
void solve() {
	int n;
	cin >> n;
	cout << an[n] << "\n";
}int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

	for(int i = 1; i < maxn; i++) {
		for(int j = i; j < maxn; j += i) {
			d[j] += i;
		}
	}
	// map<int,int> mp;
	CLR(an,-1);
	for(int i = 1; i <= maxn; i++) {
		if(d[i] < maxn && an[d[i]] == -1) {
			an[d[i]] = i;
		}
	}
	
	int T;
	cin >> T;
	while(T--) {
		solve();
	}	
	return 0;
}