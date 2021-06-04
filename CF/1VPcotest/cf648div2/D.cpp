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

const int maxn = 50 + 10;

int n,m;
char s[maxn][maxn];
int a[maxn][maxn];
int vis[maxn][maxn];
const int dx[5] = {0,1,-1,0,0};
const int dy[5] = {0,0,0,1,-1};
void bfs(int x,int y) {
	vis[x][y] = 1;
	for(int i = 1; i <= 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(xx<1||yy>m || yy < 1 || xx > n || vis[xx][yy] || a[xx][yy] == 1) continue;
		bfs(xx,yy);
	}
}
void solve() {
	cin >> n >> m;
	std::vector<pii>  q,p;
	CLR(vis,0);
	CLR(a,0);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> s[i][j];
			if(s[i][j] == '.') {
				a[i][j] = 0;
			}
			if(s[i][j] == '#') a[i][j] = 1;
			if(s[i][j] == 'G') {
				p.PB(make_pair(i,j));
				a[i][j] = 2;
			}
			if(s[i][j] == 'B') {
				q.PB(make_pair(i,j));
				a[i][j] = 3;
			}
		}
	}
	// int flag = 1;
	if(!p.size()) {
		cout << "YES" << "\n";
		return;
	}
	// cout << q.size() << "\n";
	for(int i = 0; i < (int)q.size(); i++) {
		int x = q[i].first;
		int y = q[i].second;
		// cout << x << " " << y << "\n";
		for(int j = 1; j <= 4; j++) {
			int xx = x + dx[j];
			int yy = y + dy[j];
			if(a[xx][yy] == 2)  {
				cout << "NO" << "\n";
				// cout << 1 << "\n";
				return;
			}
			if(a[xx][yy] == 0) a[xx][yy] = 1;
		}
	}
	if(a[n][m]) {
		cout << "NO" << "\n";
		// cout << 1 << "\n";
		return;
	}
	bfs(n,m);
	for(int i = 0 ;i < (int)p.size(); i++) {
		if(!vis[p[i].first][p[i].second]) {
			cout << "NO" << "\n";
			// cout << 1 << "\n";
			return;
		}
	}
	cout << "YES" << "\n";

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