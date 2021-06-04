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

const int maxn = 2e3 + 10;

int n,m;
char a[maxn][maxn];
int q,w,e,r;
void solve() {
	cin >> n;
	int flag = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if(a[i][j] == '*') {
				if(flag) {
					q = i;
					w = j;
					flag = 0;
				}
				else {
					e = i;
					r = j;
				}
			}
		}
	}
	// cout << q << w << e << r << "\n";
	if(w == r) {
		if(w != 1) {
			a[q][w-1] = '*';
			a[e][w-1] = '*';
		}
		else {
			a[q][w+1] = '*';
			a[e][w+1] = '*';

		}
	}
	if(q == e) {
		if(q != 1) {
			a[q-1][w] = '*';
			a[q-1][r] = '*';
		}
		else {
			a[q+1][w] = '*';
			a[q+1][r] = '*';

		}
	}
	else {
		a[q][r] = '*';
		a[e][w] = '*';
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cout << a[i][j] ;
		}
		cout << "\n";
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