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
int exgcd(int a,int b,int &x,int &y) {
	if(!b) {
		x = 1;
		y = 0;
		return a;
	}
	int d = exgcd(b,a%b,y,x);
	y -= (a/b)*x;
	return d;
}
signed main() {
	int a,b;
	cin >> a >> b;	
	int x,y;
	exgcd(a,b,x,y);
	// cout << x << " "<<  y<< "\n";
	int xx = (x % b + b) % b;
	int yy = (y % a + a) % a;
	cout << (a*(xx-1) + b * (yy-1) -1) << "\n";
	return 0;
}