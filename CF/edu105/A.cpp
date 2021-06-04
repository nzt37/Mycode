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
// char s[maxn];
void solve() {
	 string s;
	// scanf("%s",&s[1]);
	 cin >> s;
	// int n = s.size();
	// int flag = 1;
	// ()))((
	// ACCCAA
	// )())((
	// ACAACC
	for(int i = -1; i <= 1; i +=2 ) {
		// for(int j = -1; j <= 1; j += 2) {
			for(int k = -1; k <= 1; k += 2) {
				int ans = 0;
				int flag = 1;
				for(int l = 0; s[l]; l++) {
					if(s[l] == 'A') {
						ans += i;
						// cout << "A " << ans << "\n";
					}
					// if(s[l] == 'B') {
					// 	ans += j;
					// }
					if(s[l] == 'C') {
						ans += k;
						// cout << "C " << ans << "\n";
					}
					if(ans < 0) {
						flag = 0;
						break;
					}
				} 
				cout << "\n";
				//cout << ans << "\n";
				if(!flag) continue;
				if(ans != 0) continue;
				cout << "YES" << "\n";
				return;
			}
		// }
	}
	cout << "NO" << "\n";
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