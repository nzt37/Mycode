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
#define debug cout << "dsdsdsdsd" << "\n";
#define y1 yzang
using namespace std;
#define int long long
const int maxn = 2e6 + 10;

int n,m,k;
int a[maxn],b[maxn],c[maxn],lcm1,d[maxn],cnt,x,y;
bool check(int mid) {
	int ans = mid;
	for(int i = cnt; i >= 1; i--) {
		if(mid >= d[i]) {
			ans -= (mid-d[i])/lcm1 +1;
		}
	}
	return ans >= k;
}
int exgcd(int a,int b,int &x,int &y) {
	if(b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int g = exgcd(b,a%b,y,x);
	y -= (a / b) * x;
	return g;
}
int calc(int a1,int b1,int c1,int d1) {
	int b = -b1;
	int a  = a1;
	int c = d1 - c1; 
	int g = exgcd(a,b,x,y);
	if(c % g) return -1;
	b = abs(b);
	x *= c / g;
	x = (x % (b / g)+ (b / g)) % (b / g);
	int ans = x * a1 + c1;
	// cout << c1 << ans << "\n";
	ans = (ans%lcm1 + lcm1) %lcm1;
	return (ans == 0 ? lcm1 : ans);
}
void solve() {
	// k;
	cin >> n >> m >> k;
	lcm1 = n * m / (__gcd(n,m));
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		c[a[i]] = i;
	}
	for(int i = 1; i <= m; i++) {
		cin >> b[i];
		int p = c[b[i]];
		if(p) {
			int tmp = calc(n,m,c[b[i]],i);
			if(tmp != -1) {
				d[++cnt] = tmp;
			}
		}
	}
	cout << lcm1 << "\n";
	for(int i = 1; i <= cnt; i++) {
		cout << d[i] << "\n";
	}
	int l = 0,r = 1e18;
	while(l < r) {
		int mid = (l+r)/2;
		if(check(mid)) r = mid;
		else l = mid+1;
	}
	cout << l << "\n";

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