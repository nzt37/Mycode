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
#define int long long
int n,m;
bool isprime(int n) {
	if(n <= 1) return false;
	if(n == 2 || n == 3) return true;
	if(n % 6 != 1 && n % 6 != 5) return false;
	for(int i = 5; i * i <= n; i += 6) {
		if(n % i == 0 || n % (i+2) == 0) return false;
	}
	return true;
}
signed main() {
	while(cin >> n)
	cout << (isprime(n) ? "Y" : "N") << "\n";
	
	return 0;
}