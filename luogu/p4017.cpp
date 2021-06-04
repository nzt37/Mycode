#include <bits/stdc++.h>
using namespace std;
#define mod 80112002
const int maxn = 5e5+ 6;
int head[maxn],ind[maxn],cnt,d[maxn],c[maxn];
int n,m,f;
int ans;
struct node{
    int v,w,next;
}edge[maxn];

void addedge(int u,int v,int w)
{
    edge[++cnt].next = head[u];
    edge[cnt].v = v;
    edge[cnt].w = w;
    head[u] = cnt;
}
queue<int > q;
void tp()
{
    for(int i = 1; i <= n; i++) {
        if(ind[i] == 0) {
            q.push(i);
            d[i]++;
        }
    }
    while(!q.empty()) {
        int m = q.front();
        q.pop();
       // ans = (ans+1)%mod;
        for(int i = head[m]; i ;i = edge[i].next) {
            int v = edge[i].v;
            d[v] = (d[v] + d[m]) % mod;
            ind[v]--;
            if(ind[v] == 0) {
                q.push(v);
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u,v;
        cin >> u >> v;
        addedge(u,v,1);
        ind[v]++;
        c[u]++;
    }
    tp();
    for(int i = 1; i <= n; i++) {
        if(c[i] == 0) {
            ans = (ans+d[i])%mod;
        }
    }
    cout << ans << endl;
    return 0;
}