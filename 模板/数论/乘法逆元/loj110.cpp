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

ll n,m,p;
ll inv[maxn];
void inverse() {
	inv[1] = 1;
	for(int i = 2; i <= n; i++) {
		inv[i] = 1ll*(p-p/i)*inv[p%i]%p;
	}
}
int main() {
	cin >> n >> p;	
	inverse();
	for(int i = 1; i <= n; i++) {
		cout << inv[i] << "\n";
	}
	return 0;
}