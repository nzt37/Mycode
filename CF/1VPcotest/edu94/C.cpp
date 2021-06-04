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
	string s;
	cin >> s;
	int x;
	cin >> x;
	string w = "";
	n = s.size();
	for(int i = 0; i < n; i++) {
		w += '1';
	}
	for(int i = 0; i < n; i++) {
		if(s[i] == '0') {
			if(i-x >= 0) w[i-x] = '0';
			if(i+x < n) w[i+x] = '0';
		}
	}
	bool f1 = 0,f2 = 0;
	for(int i = 0; i < n; i++) {
		f1 = 0,f2 = 0;
		if(s[i] == '1') {
			if(i - x >= 0) {
				f1 = (w[i-x] == '1');
			}
			if(i + x < n) {
				f2 = (w[i+x] == '1');
			}
			if(!f1 && !f2) {
				cout << -1 << "\n";
				return;
			}
		}
	}
	cout << w << "\n";
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