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

int main() {
	cin >> n >> m;
	int ans = 0;
	int cnt = -1;
	int flag = 0;
	for(int i = 1; i <= n; i++) {
		int v,p;
		cin >> v >> p;
		ans += v * p;
		if(ans > m  * 100) {
			cnt = i;
			cout << cnt << "\n";
			// flag = 1;
			return 0;
		}
	}	
	puts("-1");
	return 0;
}