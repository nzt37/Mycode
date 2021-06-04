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

const int maxn = 1e5+10;
const int inf = 0x3f3f3f3f;
int n;
struct node{
	int v,w,next;
}e[10 * maxn];
int a[1005];
char str[1005][105];
int head[1005],dis[1005],vis[1005],cnt;
void add(int u,int v,int w) {
	e[++cnt].next = head[u];
	e[cnt].v = v;
	e[cnt].w = w;
	head[u] = cnt;
}
void dijisktra() {
	priority_queue<pii,vector<pii>,greater<pii> > q;
	dis[1] = 0;
	q.push(make_pair(0,1));
	while(!q.empty()) {
		int x = q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x] = 1;
		for(int i = head[x]; i ; i = e[i].next) {
			int v = e[i].v;
			if(dis[v] > dis[x] + e[i].w) {
				dis[v] = dis[x] + e[i].w;
				q.push(make_pair(dis[v],v));
			} 
		}
	}
}
bool judge(int i, int j) 
{
    int len=strlen(str[i]);
    if(str[i][len-1] == str[j][3] && str[i][len - 2] == str[j][2] && str[i][len-3] == str[j][1] && str[i][len-4] == str[j][0]) {
        return true;
    }
    return false;
}
void solve() {
    CLR(dis,inf);
    CLR(head,0);
    CLR(vis,0);
    cnt = 0;
    for(int i = 1; i <= n; i++) {
      cin >> a[i] >> str[i];
    }
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        if(i == j) continue;
        if(judge(i,j)) {
          add(i,j,a[i]);
          // cout << i << " " << j << "\n";
        }
      }
    }
   dijisktra();
   if(dis[n] == inf) {
    cout << -1 << "\n";
  }
  else {
    cout << dis[n] << "\n";
  }
}
int main()
{
   while(scanf("%d",&n)!=EOF)
   {
       if(n==0)
       {
           break;
    }
    solve();
  }
   return 0;
}