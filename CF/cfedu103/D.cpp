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

const int maxn = 63e5 + 10;

int n,m;
int a[maxn];
char s[maxn];
int f[maxn][2],g[maxn][2];
void solve() {
	cin >> n;
	scanf("%s",s+1);
	CLR(f,0);
	CLR(g,0);
	// CLR(a,0);
	for(int i = 1; i <= n; i++) {
		if(s[i] == 'L') f[i][0] = f[i-1][1] + 1,f[i][1] = 0;
		else f[i][1] = f[i-1][0] + 1,f[i][0] = 0;
	}

	for(int i = n; i >= 1; i--)  {
		if(s[i] == 'R') g[i][0] = g[i+1][1] + 1,g[i][1] = 0;
		else g[i][1] = g[i+1][0] + 1,g[i][0] = 0;
	}
	for(int i = 0; i <= n; i++) {
		a[i] = f[i][0] + g[i+1][0]+1;
	}
	for(int i = 0; i <= n; i++) {
		cout << a[i]  << " ";
	}
	cout << "\n";
}
int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0),cout.tie(0);
	
	int T;
	cin >> T;
	while(T--) {
		solve();
	}	
	return 0;
}