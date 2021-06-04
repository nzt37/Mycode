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
int a[maxn],b[maxn],c[maxn];
ll sum = 1;
void exgcd(int a,int b,ll &x,ll &y) {
	if(b == 0) {
		x = 1;
		y = 0;
		return;
	}
	exgcd(b,a%b,y,x);
	y -= (a / b) * x;
	return;
}
signed main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> b[i] >> a[i];
		sum *= b[i];
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		c[i] = sum / b[i];
		ll x = 0,y = 0;
		exgcd(c[i],b[i],x,y);
		// cout << x << '\n'; 
		ll t = b[i] / (__gcd(a[i],b[i]));
		x = (x % t +  t) % t;
		ans += c[i] * a[i] * x ;
	}
	cout << (ans % sum )<< "\n";
	return 0;
}