#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7+6;
const int INF = 0x3f;
int head[10005],vis[10005],dis[10005],n,m,ans,cnt,k;
struct node{
	int v,w,next;
}edge[maxn];
void addedge(int u,int v,int w)//链式前向星存图 
{
	edge[++cnt].next = head[u];
	edge[cnt].v = v;
	edge[cnt].w = w;
	head[u] = cnt;
}

typedef pair<int,int> p;//第一个变量指距离,第二个为节点 
priority_queue<p,vector<p>,greater<p> >q;//优先队列 

void prim()
{
	q.push(make_pair(0,1));
	dis[1] = 0;
	while(!q.empty()&&k<n)
	{
		int l = q.top().first;
		int m = q.top().second;
		q.pop();
		if(vis[m]) continue;
		k++;
		ans += l;
		vis[m] = 1;
		for(int i = head[m] ; i!=-1 ; i = edge[i].next)
		{
			if(dis[edge[i].v] > edge[i].w){
				dis[edge[i].v] = edge[i].w;
				q.push(make_pair(dis[edge[i].v],edge[i].v));
			}
			
		}
		
	}
}
int main()
{
	cin>>n>>m;
	memset(head,-1,sizeof(head));
	memset(dis,127,sizeof(dis));
	for(int i = 1 ; i <= m ; i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		addedge(u,v,w);
		addedge(v,u,w);
	}
	prim();
	cout<<ans;
	return 0;
}

