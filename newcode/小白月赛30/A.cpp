#include<bits/stdc++.h>
using namespace std;
struct Edge
{
	int u,v,w;
}edge[200005];
int f[250505],n,m,ans,cnt;
bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}
int find(int x)
{
    if(f[x]==x)
    return x;
    else return f[x] = find(f[x]);
}
void kruskal()
{
     //将边的权值排序
    for(int i = 1 ; i <= m ; i++)
    {
    	if(find(edge[i].u) != find(edge[i].v))
    	{
    		cnt++;
    		ans += edge[i].w;
    		f[find(edge[i].u)] = find(edge[i].v);
		}
		if(cnt == n-1)
		break;
	}
}
int main()
{
    cin>>n>>m;
    for( int i = 1 ; i <= n ; i++)
    {
        f[i]=i;
    }
    //初始化并查集
    for( int i = 1 ; i <= m ; i++)
    {
        cin>>edge[i].u>>edge[i].v>>edge[i].w;
    }
    sort(edge+1,edge+m+1,cmp); 
    kruskal();	
    if(cnt != n-1) {
        cout << -1 << endl;
    }
    else
    printf("%d",ans);
    return 0;
}
