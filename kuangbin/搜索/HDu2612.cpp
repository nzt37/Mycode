#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define Re register
#define LL long long
#define U unsigned
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;

const int maxn = 2e2 + 10;
const int dx[5] = {0,1,0,-1,0};
const int dy[5] = {0,0,1,0,-1};
int n,m;
char mp[maxn][maxn];
int sx,sy,wx,wy;
int s[maxn][maxn],w[maxn][maxn];
int vis[maxn][maxn];
void bfs1() {
	CLR(vis,0);
	queue<pair<int,int>> q;
	q.push(make_pair(sx,sy));
	vis[sx][sy] = 1;
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i = 1; i <= 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if(xx >= 0 && xx < n && yy >= 0 && yy < m && !vis[xx][yy] && mp[xx][yy] != '#') {
				s[xx][yy] = s[x][y] + 1;
				vis[xx][yy] = 1;
				q.push(make_pair(xx,yy));
			}
		}
	}
}
void bfs2() {
	CLR(vis,0);
	queue<pair<int,int>> q;
	q.push(make_pair(wx,wy));
	vis[wx][wy] = 1;
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i = 1; i <= 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if(xx >= 0 && xx < n && yy >= 0 && yy < m && !vis[xx][yy] && mp[xx][yy] != '#') {
				w[xx][yy] = w[x][y] + 1;
				vis[xx][yy] = 1;
				q.push(make_pair(xx,yy));
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	// cin >> T;
	while(cin >> n >> m) {
		CLR(s,0);
		CLR(w,0);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cin >> mp[i][j];
				if(mp[i][j] == 'Y') sx = i,sy = j;
				if(mp[i][j] == 'M') wx = i,wy = j;
			}
		}
		bfs1();
		bfs2();
		int ans = INT_MAX;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++ ) {
				if(mp[i][j] == '@' && (s[i][j] && w[i][j])) {
					ans = min(ans,(s[i][j] + w[i][j]) * 11);
				}
			}
		}
		cout << ans << "\n";
	}	
	return 0;
}