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
void solve() {
	cin >> n;
	if(n == 2) {
		cout << 0 << "\n";
		return;
	}
	if(n % 2 == 0) {
		for(int i = 1; i < n + 1; i++) {
			for(int j = i + 1; j < n+1; j++) {
				if(i + j == n + 1) cout << 0 << " ";
				else if(((i+j) % 2 == 1 && i + j < n + 1) || ((i+j) % 2 == 0 && i + j > n + 1))
					cout << 1 << " ";
				else {
					cout << -1 << " ";
				}
			}
		}
	}
	else {
		for(int i = 1; i < n + 1; i++) {
			for(int j = i+1; j < n + 1; j++) {
				if((i + j) % 2 == 1) {
					cout << 1 << " ";
				}
				else {
					cout << -1 << " ";
				}
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