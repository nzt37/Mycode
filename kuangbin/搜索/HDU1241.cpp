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

const int maxn = 2e5 + 10;
const int dx[10] = {0,1,0,-1,0,1,-1,1,-1};
const int dy[10] = {0,0,1,0,-1,1,-1,-1,1};
int n,m;
char mp[101][101],vis[101][101];
set<int> an;
queue<pair<int,int>> q;
int cnt;
void dfs(int x,int y) {
	if(x<0||x>=n||y<0||y>=m) return;
	// cnt++;
	mp[x][y] = '*';
	for(int i = 1; i <= 8; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(xx>=0&&xx<n&&yy>=0&&yy<m&&mp[xx][yy]=='@') {
			dfs(xx,yy);
		}
	}
}
void bfs(int i,int j){
	q.push(make_pair(i,j));
	vis[i][j] = 1;
	mp[i][j] = '*';	
	cnt++;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		mp[x][y] = '*';
		q.pop();
		for(int i = 1; i <= 8; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if(xx>=0&&xx<n&&yy>=0&&yy<m&&mp[xx][yy]=='@') {
				// cnt++;
				mp[xx][yy] = '*';
				q.push(make_pair(xx,yy));
				
				// vis[xx][yy] = 1;
				//cout << xx <<  " " << y << "\n";
 			} 
		}

	}
	// for(int i = 0; i < n; i++) {
	// 		for(int j = 0; j < m; j++) {
	// 			cout << mp[i][j];
	// 		}
	// 		cout << "\n";
	// 	}
}
int main() {
	while(cin >> n >> m) {
		CLR(vis,0);
		an.clear();
		if(n == 0 && m == 0) break;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cin >> mp[i][j];
			}
		}
		cnt = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(mp[i][j] == '@') {
					dfs(i,j);
					 cnt++;;
					//an.insert(cnt+1);
				}
			}
		}
		// for(int i = 0; i < n; i++) {
		// 	for(int j = 0; j < m; j++) {
		// 		cout << mp[i][j];
		// 	}
		// 	cout << "\n";
		// }
		cout << cnt << "\n";
	}
	return 0;
}