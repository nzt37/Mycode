#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn = 5e5 + 6;
int depth[maxn],vis[maxn],fa[maxn][22];//deep[]记录深度 ,fa[i][j]表示i的2^j级祖先
int head[maxn],cnt,lg[maxn];//lg2数组记录log2(i) 
int n,m,s;
struct node{
    int v,w,next;
}edge[maxn << 1];

void addedge(int u,int v)
{
    edge[++cnt].next = head[u];
    edge[cnt].v = v;
    head[u] = cnt;
}
void dfs(int pos,int f)
{
    if(vis[pos]) return;
    vis[pos] = 1;
    depth[pos] = depth[f] + 1;
    fa[pos][0] = f;
    for(int i = 1; i <= lg[depth[pos]]; i++){
        fa[pos][i] = fa[fa[pos][i-1]][i-1];
    }
    for(int i = head[pos]; i ; i = edge[i].next){
        dfs(edge[i].v,pos);
    }
}
int LCA(int a,int b)
{
    if(depth[a] < depth[b]){
        swap(a,b);
    }
    while(depth[a] > depth[b]){
        a = fa[a][lg[depth[a]-depth[b]]-1];
    }
    if(a == b) return a;
    for(int k = lg[depth[a]] - 1; k >= 0 ; k--){
        if(fa[a][k] != fa[b][k]){
            a = fa[a][k];
            b = fa[b][k];
        }
    }
    return fa[a][0];
}
int main() {
    cin >> n >> m >> s;
    for(int i = 1; i <= n; ++i)
        lg[i] = lg[i-1] + (1 << lg[i-1] == i);
    for(int i = 1; i <= n-1; i++){
        int u,v;
        cin >> u >> v;
        addedge(u,v);
        addedge(v,u);
    }
    dfs(s,0);
    for(int i = 1; i <= m; i++){
        int a,b;
        cin >> a >> b;
        cout << LCA(a,b) << endl;
    }

    return 0;
}

