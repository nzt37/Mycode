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
#define int long long
const int maxn = 2e5 + 10;

int n,m;
void solve() {
	int r1,r2,l1, l2;
	int k;
	cin >> n >> k >> l1 >> r1 >> l2 >> r2;
	if(l2 < l1) { swap(l1,l2); swap(r1,r2);}
	if(r1 >= r2) {
		k -= (r2-l2) * n;
	}
	else if(l2 <= r1) {
		k -= (r1-l2) * n;
	}
	if(k <= 0 ) {cout << 0 << "\n"; return;}
	if(r1 >= r2) {
		int len = r1-r2 + l2-l1;
		if(len * n >= k) { cout << k << "\n"; return;}
		else {
			k -= n*len;
			cout << (k * 2 + n * len) << "\n";
			return; 
		}
	}
	else if(l2 <= r1) {
		int len = l2-l1+r2-r1;
		if(len * n >= k) { cout << k << "\n"; return;}
		else {
			k -= n*len;
			cout << (k * 2 + n * len) << "\n";
			return; 
		}	
	}
	else {
		int len = r2 - l1,cost = l2 - r1;
		if(n * len >= k) {
			int res = 1e18;
			for(int i = 1; i <= n; i++) {
				if(k < i * len) break;
				else {
					res = min(res,(cost+len)*i+(k-i*len)*2);
				}
			}
			 res=min(res,k+((k-1)/len+1)*cost);
			cout << res << "\n";
		}
		else {
			int res = 1e18;
			res = min(res,n*(len+cost)+2*(k-n*len));
			cout << res << "\n";
		}
		
	}

}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	int T;
	cin >> T;
	while(T--) {
		solve();
	}	
	return 0;
}