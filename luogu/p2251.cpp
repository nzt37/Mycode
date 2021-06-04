#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6 + 7;
int f[maxn][50],lg[maxn] = {-1};
int a[maxn],n,m;
void build()
{
   for(int j = 1; j <= lg[n]; j++) {
       for(int i = 1; i + (1 << j)-1 <= n; i++) {
           f[i][j] = min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
       }
   }
}
int pcm(int l,int r){
	int m=r-l+1;
	int w=lg[m];
	return min(f[l][w],f[r-(1<<w)+1][w]);
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        lg[i] = lg[i/2] + 1;
    }
    for(int i = 1; i <= n; i++) {
        cin >> f[i][0];
    }
    build();
    for(int i = 1; i <= n - m + 1; i++) {
        int ans = min(f[i][lg[m]],f[i + m - 1 -(1<<lg[m])+1][lg[m]]);
        printf("%d\n",ans);
    }
    return 0;
}

