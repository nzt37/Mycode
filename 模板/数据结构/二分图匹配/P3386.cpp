#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+6;
int a[501][501],n,m,e,match[maxn],vis[maxn],ans;
bool dfs(int x)
{
	for(int i = 1 ; i <= m ; i++){
		if(!vis[i] && a[x][i]){
			vis[i] = 1;
			if(!match[i] || dfs(match[i])){
				match[i] = x;
				return 1;
			}		
		}
	}
	return 0;
}
int main()
{
	cin>>n>>m>>e;
	for(int i = 0 ; i < e ; i++){
		int u,v;
		cin>>u>>v;
		if (v <= m)
		 a[u][v] = 1;
	}
	for(int i = 1 ; i <= n ; i++){
		ans += dfs(i);
		memset(vis, 0, sizeof(vis));
	}
	cout<<ans;
	return 0;
}

