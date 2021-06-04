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
#define BR printf("--------------------\n")
#define debug(x) std::cerr << #x << '=' << x << '\n'
#define y1 yzang
using namespace std;

const int maxn = 2e5 + 10;

int n,m;
int a[101][101];
int an[101][101];
void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j =1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	for(int i = 1; i <= n; i++) {
		sort(a[i]+1,a[i]+1+m);
	}
	for(int i = 1; i <= m; i++) {
		int p = 0;
		for(int j = 1; j <= n; j++) {
			if(!p || a[p][1] > a[j][1]) p = j;
		}
		for(int j = 1; j <= n; j++) {
			if(p == j) an[i][j] = a[p][1];
			else an[i][j] = a[j][m-i+1]; 
		}
		for(int j = 1; j < m; j++) a[p][j] = a[p][j+1];
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cout << an[j][i] <<  " \n"[j == m];
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	int T;
	cin >> T;
	while(T--) {
		solve();
	}	
	return 0;
}	