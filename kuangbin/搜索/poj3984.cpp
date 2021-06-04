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

const int maxn = 20;
const int dx[5] = {0,1,0,-1,0};
const int dy[5] = {0,0,1,0,-1};

int n,m;
int mp[5][5];
struct node{
	int x,y;
}a[maxn],fa[maxn][maxn];
queue<node> q;
int vis[maxn][maxn],dep[maxn][maxn];
void print(node k) {
	std::vector<node> v;
	// v.emplace_back(k);
	while(1) {
		v.PB(k);
		if(dep[k.x][k.y] == 0) break;
		k = fa[k.x][k.y];
	}
	for(int i = (int)v.size()-1; i >= 0; i--) {
		printf("(%d, %d)\n",v[i].x,v[i].y);
	}
}
void bfs(){
	node m;m.x=0,m.y=0;
	q.push(m);
	vis[0][0] = 1;
	dep[0][0] = 0;
	while(!q.empty()) {
		node k = q.front();
		q.pop();
		if(k.x == 4 && k.y == 4) {
			// debug(1);
			print(k);
			return;
		}
		for(int i = 1; i <= 4; i++) {
			int x = k.x + dx[i];
			int y = k.y + dy[i];
			if(x>=0&&x<5&&y>=0&&y<5&&!vis[x][y]&&mp[x][y]==0) {
				dep[x][y] = dep[k.x][k.y] + 1;
				fa[x][y] = k;
				node m;m.x=x;m.y=y;
				q.push(m);
				vis[x][y] = 1;
			}
		}

	}
}
int main() {
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			cin >> mp[i][j];
		}
	}
	bfs();
	return 0;
}