#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define mid ((r+l)>>1)
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug cout << "dsdsdsdsd" << "\n";
#define y1 yzang
using namespace std;
const int inf = 999999999;
const int maxn = 5005;

int n,m;
double x[maxn],y[maxn],dis[maxn],ans;
int vis[maxn];
double calc(double x1,double x2,double y,double yy) {
	return (x1-x2) * (x1-x2) + (y-yy) * (y-yy);
}
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
	}
	 memset(dis,0x7f,sizeof(dis));
	dis[1] = 0;
	// cout << dis[2] << " csa\n";
	for(int i = 1; i <= n; i++) {
		int k = 0;
		for(int j = 1; j <= n; j++) {
			if(!vis[j] && dis[j] < dis[k]) k = j;
		}
		vis[k] = 1;
		for(int j = 1; j <= n; j++) {
			if(!vis[j] && calc(x[k],x[j],y[k],y[j]) < dis[j]) {
				dis[j] = calc(x[k],x[j],y[k],y[j]);
			}
		}
	}
	for(int  i = 1; i <= n; i++) ans += sqrt(dis[i]);
	printf("%.2lf",ans);
	return 0;
}