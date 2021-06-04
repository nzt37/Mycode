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

const int maxn = 1e4 + 10;

int n,m;
int vis[maxn][maxn];
const int dx[5] = {0,1,-1,0,0};
const int dy[5] = {0,0,0,1,-1};
struct node{
	int x,y,t;
};
// queue<node> q;
	int ans = 0;
int o = 3000;
void bfs() {
	queue<node> q;
	q.push(node{o,o,0});
	q.push(node{2020+o,11+o,0});
	q.push(node{11+o,11+o,0});
	q.push(node{2000+o,2000+o,0});
	ans = 4;
	while(!q.empty()) {
		node m = q.front();
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		cout << x << "\n";
		//if(vis[x][y]) continue;
		if(m.t == 2020) continue;
		for(int i = 1; i <= 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if(vis[xx][yy]) continue;
			ans++;
			q.push(node{xx,yy,m.t+1});
			vis[xx][yy] = 1;
		}
	}
}
int main() {


	vis[0+o][0+o] = 1;
	vis[2020+o][11+o]  =1;
	vis[11+o][14+o] = 1;
	vis[2000+o][2000+o] = 1;
	bfs();
	int an = 0;
	for(int i = 1; i <= 2020; i++) {
		for(int j = 1; j <= 2020; j++) {
			if(vis[i][j]) an++;
		}
	}
	cout << ans << "\n";
	return 0;
}
// 4080400