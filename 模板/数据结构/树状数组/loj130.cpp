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
const int maxn = 2e6 + 10;
int n,m,q;
int a[maxn],c[maxn];
int lowbit(int x) {
	return x & -x;
}
void add(int x,int k) {
	while(x <= n) {
		a[x] += k;
		x += lowbit(x);
	}
}
int sum(int x) {
	int ans = 0;
	while(x != 0) {
		ans += a[x];
		x -= lowbit(x);
	}
	return ans;
}
signed main() {
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> m;
		add(i,m);
	}
	while(q--) {
		int x,y,z;
		cin >> x >> y >> z;
		if(x == 1) {
			add(y,z);
		}
		else {
			cout << sum(z) - sum(y-1) << "\n";
		}
	}
	return 0;
}