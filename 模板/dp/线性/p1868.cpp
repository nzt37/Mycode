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

const int maxn = 3e6 + 10;
int f[maxn];
int n,m;
int a[maxn],b[maxn];
int sum[maxn];
int main() {
	cin >> n ;
	int mx = -1;
	for(int i = 1; i <= n; i++) {
		int x,y;
		cin >> x >> y;
		b[x] = y;
		sum[x] = y - x + 1;
		mx = max(mx,y);

	}	
	for(int i = mx; i >= 1; i--) {
		if(sum[i])
			f[i] = max(f[i+1],f[b[i]+1]+sum[i]);
		else  f[i] = f[i+1];
	}
	cout << f[1] << "\n";
	return 0;
}