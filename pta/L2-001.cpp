#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn = 6e5 + 6;
int dis[maxn],c[maxn],vis[maxn],head[maxn],pre[maxn],va[maxn],cnt,n,m,s,d;
int num[maxn];
struct node{
    int v,w,next; 
}edge[maxn];
struct Node{
    int dis,pos,val;
    bool operator <( const Node &x )const
    {
        if(dis == x.dis) return val < x.val;
        return x.dis < dis;
    }   
};

void addedge(int u,int v,int w)
{
    edge[++cnt].next = head[u];
    edge[cnt].v = v;
    edge[cnt].w = w;
    head[u] = cnt;
}
void dijkstra()
{
    //for(int i=0;i<=n;i++)	dis[i]=1e9;
    memset(dis,0x3f,sizeof(dis));
    memset(pre,-1,sizeof(pre));
    priority_queue<Node> q;
    dis[s] = 0;
    q.push((Node){0,s,c[s]});
    va[s] = c[s],num[s] = 1;
    while(!q.empty()){
        Node tmp = q.top();
        q.pop();
        int x = tmp.pos;
        if(vis[x]) continue;
        vis[x] = 1;
        for(int i = head[x] ;i; i = edge[i].next){
            int v = edge[i].v;
            if(dis[v] > dis[x] + edge[i].w){
                pre[v] = x;
                dis[v] = dis[x] + edge[i].w;
                va[v] = va[x] + c[v];
                num[v] = num[x];
                q.push((Node){dis[v],v,va[v]});
            }
            else if(dis[v] == dis[x] + edge[i].w){
                num[v] += num[x];
                if(va[v] < va[x] + c[v]){
                    pre[v] = x;
                    va[v] = va[x] + c[v];
                    q.push((Node){dis[v],v,va[v]});
                }
            }
        }
    }

}
void dfs(int u)
{
    if( pre[u]!=-1 )	dfs(pre[u]);
    cout << u ;
    if( u!=d )	cout << " ";
}
int main() {
    cin >> n >> m >> s >> d;
    for(int i = 0; i < n; i++) cin >> c[i];
    for(int i = 1; i <= m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        addedge(u,v,w);
        addedge(v,u,w);
    }
    dijkstra();
    cout << num[d] << " " << va[d] << endl;
    dfs(d);
    return 0;
}
