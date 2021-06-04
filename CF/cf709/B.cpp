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
void solve() {
	cin >> n;
	int f1 = 0,f2 = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] < a[i-1] && i != 1) {
			f1 = 1;
		}
		if(a[i] > a[i-1] && i != 1) {
			f2 = 1;
		}
	}
	// cout << f1 << f2 << "\n";
	if(!f1 && !f2) {
		cout  << 0 << "\n";
		return;
	}
	if(!f1 && f2) {
		int m = a[2] - a[1];
		for(int i = 2; i <= n; i++) {
			if(a[i] - a[i-1] != m) {
				cout << -1 << "\n";
				return;
			}
		}
		cout << 0 << "\n";
		return;
	}
	if(f1 && !f2) {
		int m = a[2] - a[1];
		for(int i = 2; i <= n; i++) {
			if(a[i] - a[i-1] != m) {
				cout << -1 << "\n";
				return;
			}
		}
		cout << 0 << "\n";
		return;
	}
	if(f1 && f2) {
		int m = 0,x = -1;
		for(int i = 2; i <= n; i++) {
			if(a[i] > a[i-1] ) {
				if(m == 0) m = a[i] - a[i-1];
				else {
					if(m != a[i] - a[i-1]) {
						cout << -1 << "\n";
						return;
					}
				}
			}
			else{
				if(x == -1) {
					x = a[i-1] - a[i];
				}
				else {
					if(a[i-1] - a[i] != x) {
						cout << -1 << "\n";
						return;
					}
				}
			}
		}
		// int ans = 0,t = 0;
		for(int i = 2; i <= n; i++) {
			if(a[i] < a[i-1]) {
				if((a[i-1]+m-a[i]) >= *max_element(a+1,a+1+n)){
					cout << (a[i-1]+m-a[i]) << " " << m << "\n";
					return;
				}
				else {
					cout << "-1" << "\n";
					return;
				}
			}
		}
		
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