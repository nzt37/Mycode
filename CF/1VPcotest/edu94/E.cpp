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
#define int long  long
using namespace std;

const int maxn = 2e5 + 10;

int n,m;
int a[maxn];
int f(int l,int r)
{
	if(l>r)return 0;
	if(l==r)return min(a[l],1ll);
	int k=2e9,x;
	for(int i=l;i<=r;i++)if(k>a[i])k=a[i],x=i;
	for(int i=l;i<=r;i++)a[i]-=k;
	return min(r-l+1,f(l,x-1)+f(x+1,r)+k);
}
void solve() {
	cin >> n;
	for(int i = 1; i <= n ;i++) {
		cin >> a[i];
	}
	cout << f(1,n) << "\n";
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	int T = 1;
	// cin >> T;
	while(T--) {
		solve();
	}	
	return 0;
}