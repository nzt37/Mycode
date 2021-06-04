#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
int n;
struct edge
{
    int next,to;
} e[4000];
int head[4000],tot,dp[4000][2],ind[4000];
void add(int x,int y)
{
    e[++tot].next=head[x];
    head[x]=tot;
    e[tot].to=y;
}
void dfs(int x)
{
    dp[x][1]=1;
    for(int i=head[x]; i; i=e[i].next)
    {
        int v=e[i].to;
        dfs(v);
        dp[x][0]+=dp[v][1];
        dp[x][1]+=min(dp[v][0],dp[v][1]);
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        memset(head,0,sizeof(head));
        memset(ind,0,sizeof(ind));
        tot=0;
        for(int j=1; j<=n; j++)
        {
            int a,b;
            scanf("%d:(%d)",&a,&b);
            for(int i=1; i<=b; i++)
            {
                int c;
                scanf("%d",&c);
                ind[c]++;
                add(a,c);
            }
        }
        int rt;
        for(int i=0; i<=n; i++)
            if(!ind[i])
            {
                rt=i;
                break;
            }
        dfs(rt);
        cout << rt << "\n";
        printf("%d\n",min(dp[rt][1],dp[rt][0]));
    }
}