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
const int inf=0x3f3f3f3f;
const int maxn = 2e3 + 10;
const int dx[5] = {0,1,0,-1,0};
const int dy[5] = {0,0,1,0,-1};
struct node {
	int x,y,t;
	 node(int X,int Y,int T)
    {
        x=X,y=Y,t=T;
    }
};
queue<node> q;
int t[maxn][maxn],vis[maxn][maxn],cnt[maxn][maxn];
int n,m;
char mp[maxn][maxn];
void bfs1() {
	while(!q.empty()) {
		node k = q.front();
		int x = k.x;
		int y = k.y;
		q.pop();
		// vis[x][y] = 1;
		for(int i = 1;  i <= 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if(t[xx][yy]==inf) {
				if(xx>=0&&xx<n&&yy>=0&&yy<m) {
					
					if(mp[xx][yy] == '.') {
						t[xx][yy] = (t[x][y] + 1);
						q.push(node{xx,yy,0});
					}
				}
			}
		}

	}
}
int sx,sy,ans[maxn][maxn],tot,flag;
void bfs2() {
	 while(!q.empty()) q.pop();
	CLR(vis,0);
	q.push(node{sx,sy,0});
	while(!q.empty()) {
		node k = q.front();
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		vis[x][y] = 1;
		if(x == n-1 || x == 0 || y == m-1 || y == 0) {
			cout << k.t + 1 << "\n";
			return;
		}
		for(int i = 1; i <= 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if(!vis[xx][yy]) {
				if(xx>=0&&xx<n&&yy>=0&&yy<m) 
				if(t[xx][yy]>k.t+1&&mp[xx][yy]!='#') {
					q.push(node{xx,yy,k.t+1});
					ans[xx][yy] = ans[x][y] + 1;
					vis[xx][yy] = 1;
					
				}
			}
		}
	}
	cout << "IMPOSSIBLE" << "\n";
}
int main() {
	int T;
	cin >> T;
	while(T--) {
		CLR(vis,0);
		flag = 0;
		cin >> n >> m;
		// for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) mp[i][j]=ans[i][j]=t[i][j]=0;
		CLR(t,inf);
		for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> mp[i][j];
			if(mp[i][j] == 'F') {
				q.push(node{i,j,0});
				t[i][j] = 0;
				
			}
				if(mp[i][j] == 'J') sx = i,sy = j;
			}
		}
		bfs1();
		bfs2();
	//DEBUG(1);
		// for(int i = 0; i < n; i++) {
		// 	for(int j = 0; j < m; j++) {
		// 		cout << t[i][j] << " ";
		// 	}
		// 	cout << "\n";
		// }

	}
	return 0;
}