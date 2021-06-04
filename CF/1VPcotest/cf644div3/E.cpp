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
string s[60];
int a[50][50],b[50][50];
void solve() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> s[i];
	}
	int flag = 1;
	CLR(a,0);
	CLR(b,0);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n-1; j++) {
			if(s[i][j] == '1' && s[i][j+1] == '0') {
				flag = 1;
				a[i][j] = 1;
				// break;
			}
		}
	
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n-1; j++) {
			if(s[j][i] == '1' && s[j+1][i] == '0') {
				flag = 1;
				b[j][i] = 1;
				// break;
			}
		}
		
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(a[i][j] && b[i][j]) {
				// cout << a[i][j] << " " << b[i][j] << "\n";
				cout << "NO" << "\n";
				return;
			}

		}
	}
	cout << "YES" << "\n";
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