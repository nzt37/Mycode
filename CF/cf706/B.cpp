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
#define int long long
int n,m;
int a[maxn];
void solve() {
	int k;
	cin >> n >> k;
	//CLR(a,0);
	set<int> q;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		q.insert(a[i]);
	}
	sort(a,a+n);
	int tmp = n;
	if(k == 0) {
		cout << q.size() << "\n";
		return;
	}
	for(int i = 0; i < n; i++) {
		if(a[i] != i) {
			// cout << a[i] << "\n";
			tmp = i;
			break;
		}
	}
	  // cout << tmp << "\n";
	if(tmp == n) {
		cout << q.size() + k << "\n";
	}
	else {
		int ans = 0;
		if(tmp == 0) {
			ans = (a[n-1] + 1) / 2;
		}
		else {
			ans = (a[n-1]+tmp+tmp-1)/tmp;
		}
		if(q.count(ans)) {
			cout << q.size() << "\n";
		}
		else {
			cout << q.size() + 1 << "\n";
		}
	}


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
/*
1 10000000
1
*/