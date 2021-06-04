#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
int f[maxn][35],a[maxn],lg[maxn]={-1};
int n,m;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
    while (isdigit(ch)){x=x*10+ch-48;ch=getchar();}
    return x*f;
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        a[i] = read();
        lg[i] = lg[i/2] + 1;
        f[i][0] = a[i];
    }
    for(int j = 1; j <= lg[n]; j++) {
        for(int i = 1; i+(1<<j)-1 <= n; i++) {
            f[i][j] = max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
    for(int i = 1; i <= m; i++) {
        int l,r;
        l = read(),r = read();
        int len = lg[r - l + 1 ];
        printf("%d\n",max(f[l][len],f[r-(1<<(len))+1][len]));  
    }
    return 0;
}