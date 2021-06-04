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
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define BR printf("--------------------\n")
#define debug(x) std::cerr << #x << '=' << x << '\n'
#define y1 yzang
using namespace std;

const int maxn = 2e5 + 10;

int n,m;
int output(int l,int r) {
	cout << "? " << l + 1 << " " << r << endl;
	cout.flush();
	int an;
	cin >> an;
	return r - l - an;
}
void solve() {
	int t,k;
	cin >> n >> t;
	cin >> k;
	k--;
	int l = 0,r = n;
	while(r - l > 1) {
		int mid = (l + r) >> 1;
		if(output(0,mid) <= k) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
	cout << "! " << r << endl;
	return;

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