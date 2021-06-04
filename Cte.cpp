#include <bits/stdc++.h>

using namespace std;
const int maxn=200000+10;
int n,m,r,mod;
int e,beg[maxn],nex[maxn],to[maxn],w[maxn],wt[maxn];
int a[maxn<<2],laz[maxn<<2],maxx[maxn];
int son[maxn],id[maxn],fa[maxn],cnt,dep[maxn],siz[maxn],top[maxn],deep[maxn],head[maxn]; 
int res=0;
struct node{
    int v,nxt;
}edge[maxn<<2];

void addedge(int u,int v)
{
    edge[++e].nxt = head[u];
    edge[e].v = v;
    head[u] = e;
}
inline void pushup(int p) {
     a[p] = (a[p << 1] + a[p << 1 | 1]) ;
     maxx[p] = max(maxx[p<<1],maxx[p<<1|1]);
}
inline void build(int p,int l,int r) {
    if(l == r) {
        a[p] = wt[l];
        maxx[p] = wt[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1,mid+1,r);
    pushup(p);
}
inline int query(int p,int l,int r,int L,int R) {
    int ans = -INT_MAX;
    if(L <= l && r <= R) {
        return maxx[p];
    }
   
        int mid = (l + r) >> 1;
        if(L <= mid) ans = max(ans,query(p<<1,l,mid,L,R));
        if(R > mid) ans = max(ans,query(p<<1|1,mid+1,r,L,R));
            maxx[p] = max(maxx[p<<1],maxx[p<<1|1]);
            a[p] = a[p<<1] + a[p<<1|1]; 
        return ans;
    
}
inline int QMAX(int x,int y) {
    int ans = -INT_MAX;
    while(top[x] != top[y]) {
        if(deep[top[x]] < deep[top[y]]) swap(x,y);
        ans = max(ans,query(1,1,n,id[top[x]],id[y]));
        x = fa[top[x]];
    }
    if(deep[x] < deep[y]) swap(x,y);
    ans = max(ans,query(1,1,n,id[x],id[y]));
    return ans;
}
void dfs1(int p,int fath,int dep)
{
    siz[p] = 1;
    deep[p] = dep;
    fa[p] = fath;
    int maxson = -1;
    for(int i = head[p]; i ; i = edge[i].nxt) {
        int v = edge[i].v;
        if(v == fath) {
            continue;
        }
        dfs1(v,p,dep+1);
        siz[p] += siz[v];
        if(siz[v] > maxson) {
            son[p] = v;
            maxson = siz[v];
        }
    }
}
void dfs2(int x,int topf)
{
    id[x] = ++cnt;
    wt[cnt] = w[x];
    top[x] = topf;
    if(!son[x]) return;
    dfs2(son[x],topf);
    for(int i = head[x]; i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(v == fa[x] || v == son[x]) continue;
        dfs2(v,v);
    }
}
int main()
{
    cin >> n ;
   
    for(int i = 1; i < n; i++) {
        int a,b;
        cin >> a >> b;
        addedge(a,b);
        addedge(b,a);
    }
    for(int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    dfs1(1,0,1);
    dfs2(1,1);
    build(1,1,n);
    // for(int i = 1; i <= n; i++) {
    //     cout << a[i] << " " << maxx[i] << "\n";
    // }
    cin >> m;
    string s;
    while(m--) {
        int x,y;
        cin >> s >> x >> y;
        //cout << "fsd" << "\n";
        if(s[1] == 'M') {
        //  cout << "fsdf" << "\n";
            cout << QMAX(x,y) << "\n";
            //cout << "fds" << "\n";
            
        }
       
    }
    return 0;
}