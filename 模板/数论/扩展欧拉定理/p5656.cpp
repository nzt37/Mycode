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

// int n,m;
int exgcd(int a,int b,int &x,int &y) {
	if(!b) {
		x = 1;
		y = 0;
		return a;
	}
	int d = exgcd(b,a%b,y,x);
	y -=  (a/b) * x;
	return d;
}
signed main() {
	int T;
	cin >> T;
	while(T--) {
		int a,b,c;
		cin >> a >> b >> c;
		int x,y;
		int d = exgcd(a,b,x,y);
		if(c % __gcd(a,b)) {
			cout  << -1 << "\n";
		}
		else {
			x *= c/d,y*=c/d;
			int p = b/d,q = a/d,k;
			if(x < 0) {
				k = ceil((1.0-x)/p);
				x += p * k;
				y -= q * k;
			}
			else if(x >= 0) {
				k = (x - 1) / p;
				x -= p * k;
				y += q * k;
			}
			if(y > 0) {
				cout << (y-1)/q+1 << " ";
				cout << x << " ";
				cout << (y-1)%q+1 << " ";
				cout << x + (y-1)/q*p << " ";
				cout << y << " ";
			}
			else {
				cout << x << " ";
				cout << (y+q*(ll)ceil((1.0-y)/q)) << " ";
			}
			cout << "\n";
		}


	}

	return 0;
}