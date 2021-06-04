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
const int mx = 10000001;
int n,m;
int s[mx+1];
int a[maxn];
void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	set<int> q;
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(q.count(s[a[i]])) {
			ans++;
			q.clear();
		}
		q.insert(s[a[i]]);
	}
	cout << ans+1 << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	for(int i = 0;i < mx ;i++) s[i] = i;

	for(int i = 2; i * i <= mx; i++) {
		for(int j = i*i; j < mx; j += i * i) {
			while(s[j] % (i * i) == 0) {
				s[j] /= (i * i);
			}
		}
	}
	int T;
	cin >> T;
	while(T--) {
		solve();
	}	
	return 0;
}