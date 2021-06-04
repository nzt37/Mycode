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
int a[maxn],f[maxn],dp[maxn];
inline int calc(int x) {
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(x & (1 << i)) {
			ans++;
		}
	}
	return ans;
}
int main() {
	cin >> n >> m;	
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		
	}
	int ans = 0;
	for(int i = 0; i < (1<<n); i++) {
		if(calc(i) == n-m) {
			bitset<2020> s;
			s[0] = 1;
			for(int j = 0; j < n; j++) {
				if(i & (1 << j)) {
					s = s | s << a[j];
				}
			}
			ans = max(ans,(int)s.count());
		}
	}
	cout << ans - 1<< "\n";
	return 0;
}