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
string a[maxn];
bool judge() {
	// int flag = 1;
	for(int i = 1; i < n; i++) {
		int ans = 0;
		for(int j = 0; j < m; j++) {
			if(a[0][j] != a[i][j]) {
				ans++;
			}
			if(ans > 1) {
				return false;
			}
		}
	}
	return true;
}
void solve() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if(judge()) {
		cout << a[0] << "\n";
		return;
	}
	else {
		for(int i = 0; i < m ;i++) {
			char s = a[0][i];
			for(char j = 'a'; j <= 'z'; j++) {
				a[0][i] = j;

				if(judge()) {
					// cout << "YES" << "\n";
					cout << a[0] << "\n";
					return; 
				}
				else a[0][i] = s;
			}
		}
	}
	cout << "-1" << "\n";
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