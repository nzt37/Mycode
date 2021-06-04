#include <iostream>
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

const int maxn = 501;

int n,m;
int a[maxn][maxn],b[maxn][maxn];
void dfs(int x,int y,int k) {
	if(b[k][k] <= 1) return;
	if(y > 1 && !a[x][y-1]) {
		a[x][y-1] = a[k][k];
		--b[k][k];
		dfs(x,y-1,k);
	}
	else if(x < n && !a[x+1][y]) {
		a[x+1][y] = a[k][k];
		--b[k][k];
		dfs(x+1,y,k);
	}
	else  {
		b[k][k]--;
		a[x][y+1] = a[k][k];
		dfs(x,y+1,k);
	}
}
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i][i];
		b[i][i] = a[i][i];
	}
	for(int i = 1; i <= n; i++) {
		dfs(i,i,i);
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= i; j++) {
			cout << a[i][j] << " \n"[j == i];
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	int T = 1;
	// cin >> T;
	while(T--) {
		solve();
	}	
	return 0;
}