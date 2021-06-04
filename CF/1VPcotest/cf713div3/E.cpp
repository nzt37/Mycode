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
int a[maxn];
int pre[maxn],suf[maxn];
void solve() {
	int l,r,s;
	cin >> n >> l >> r >> s;
	for(int i = 1; i <= n; i++) {
		pre[i] = pre[i-1] + i;
	}
	for(int i = n; i >= 1; i--) {
		suf[n-i+1] = suf[n-i] + i;
	} 
	int p = r - l + 1;
	if(s < pre[p] || s > suf[p]) {
		cout << -1 << "\n";
		return;
	}
	map<int,int> mp;
	int m = s - pre[p];
	// cout << m << "\n";
	int an = m / (r - l + 1);
	int cnt = 1;
	for(int i = l; i <= r; i++) {
		a[i] = cnt + an;
		cnt++;
		mp[a[i]] = 1;
	}
	if(m % (r-l+1)) {
		int p = m % (r-l+1);
		for(int i = r,j = p; i >= l,j > 0; i--,j--) {
			mp[a[i]] = 0;
			a[i] += 1;
			mp[a[i]] = 1;
			// cout << a[i] << "das\n";
		}
	}
	for(int i = 1; i < l; i++) {
		for(int j = 1; j <= n; j++) {
			if(!mp[j]) {
				cout << j << " ";
				mp[j] = 1;
				break;
			}
		}
	}
	for(int i = l; i <= r; i++) {
		cout << a[i] << " ";
	}
	for(int i = r+1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(!mp[j]) {
				cout << j << " ";
				mp[j] = 1;
				break;
			}
		}
	}
	cout << "\n";
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
// 2 1 1 2