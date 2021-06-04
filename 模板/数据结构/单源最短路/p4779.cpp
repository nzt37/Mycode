#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+6;
int head[maxn],cnt,n,m,s,dis[maxn];
bool vis[maxn];
struct Node{
	int v,w,next;
}edge[maxn<<1];
void addedge(int u,int v,int w)
{
	edge[++cnt].next = head[u];
	edge[cnt].v = v;
	edge[cnt].w = w;
	head[u] = cnt;
}
typedef pair<int,int> P;//第一个变量指距离,第二个为节点 
priority_queue< P, vector<P>, greater<P> > q;//按first从小到大出队
void dijkstra()
{
	memset(dis,inf,sizeof(dis));
	dis[s] = 0;//从s点出发 
	q.push(make_pair(0,s));
	while(!q.empty()){
		int b = q.top().second;
		q.pop();
		if(vis[b]) continue;
		vis[b] = 1;
		for(int i = head[b] ; i ; i = edge[i].next){
			int v = edge[i].v;
			if(dis[v] > dis[b] + edge[i].w){
				dis[v] = dis[b] + edge[i].w;
				q.push(make_pair(dis[v],v));
			}
		}	
	}	
}
int main()
{
	int t;
	cin>>n>>m>>s>>t;
	for(int i = 1 ; i <= m ; i++){
		int u,v,w;
		cin>>u>>v>>w;
		addedge(u,v,w);
	}
	dijkstra();
	for( int i = 1; i <= n; i++ )
        printf( "%d ", dis[i] );
	return 0;
} 

