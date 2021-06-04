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
char s[1000][maxn];
void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		scanf("%s",s[i]+1);
	}
	if(m % 2 == 1) {
		cout << "YES" << "\n";
		for(int i = 0; i <= m; i++) {
			cout << (i % 2 + 1) << " \n"[i==m];
		}
		return;
	}
	else {
		if(n == 2) {
			if(s[1][2] != s[2][1]) {
				cout << "NO" << "\n";
				return;
			}
			else {
				cout << "YES" << "\n";
				for(int i = 0; i <= m; i++) {
					cout << (i % 2 + 1) << " \n"[i==m];
				}
				return;
			}
		}
		int x = 0,y = 0,z = 0;
		if(s[1][2] == s[2][3]) x = 2, y = 1,z = 3;
		if(s[1][2] == s[3][1]) x = 1,z = 2,y = 3;
		if(s[2][3] == s[3][1]) z = 1,y = 3,x = 2;
		cout << "YES" << "\n";
		if(m % 3 == 0) {
			for(int i = 0; i < m / 3; i++) {
				// a b a a b a
				cout << x << " " << z << " " << y << " ";  
			}
			cout << x << "\n";
		} 
		if(m % 3 == 1) {
			// cout << z << " ";
			for(int i = 0; i < (m-1)/3; i++) {
				// b a a b a a b a
				cout << z << " " << y << " " << x << " ";
			}
			cout << z << " " << y << "\n";

		}
		if(m % 3 == 2) {
			// a a b a a b a a
 			
 			for(int i = 0; i <= (m-2)/3; i++) {
 				cout << x << " " << y << " " << z << " ";
 			}
 			cout << "\n";
		}
	}
}
int main() {

	
	int T;
	cin >> T;
	while(T--) {
		solve();
	}	
	return 0;
}