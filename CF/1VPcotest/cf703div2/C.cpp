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
// #define mid ((r+l)>>1)
// #define lson p<<1,l,mid
// #define rson p<<1|1,mid+1,r
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug cout << "dsdsdsdsd" << "\n";
#define y1 yzang
using namespace std;

const int maxn = 2e5 + 10;

int n,m;
void sc(int l,int r) {
	cout << "? " << l << " " << r << "\n";
	cout.flush();
}
void solve() {
	cin >> n;
	sc(1,n);
	int p;
	cin >> p;
	int l = 1,r = n;
	int x;
	if(p == 1) {
		l = 2,r = n;
	} else {
		sc(1,p);
		cin >> x;
		if(x == p) {
			l = 1,r = p-1;
		} else {
			l = p+1,r = n;
		}
	}
	if(l == p + 1) {
		while(l < r) {
			int mid = (l + r) >> 1;
			sc(p,mid);
			cin >> x;
			// sc(l,mid);
			// int y;
			// cin >> y;
			if(p == x) {
				r = mid;
			} 
			else {
				l = mid + 1;
			}
		}
	}
	else {
		while(l < r) {
			int mid = (l + r + 1) >> 1;
			sc(mid,p);
			cin >> x;
			if(x == p) l = mid;
			else {
				r = mid - 1;
			}
		}
	}
	// cout.flush();
	cout << "! " << l << "\n";
	cout.flush();
	return ;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	int T = 1;
	// cin >> T;
	while(T--) {
		solve();
	}	
	return 0;
}