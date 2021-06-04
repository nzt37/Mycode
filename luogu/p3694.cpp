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

const int maxn = 2e5 + 10;

int n,m;
int a[maxn];
int f[1<<22];
int b[maxn],num[maxn],sum[maxn][50];
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		num[a[i]]++;
		for(int j = 1; j <= m; j++) {
			sum[i][j] = sum[i-1][j];
		}
		sum[i][a[i]]++;
	}
	// int ans = 0;
	CLR(f,0x3f);
	f[0] = 0;
	for(int i = 1; i < (1 << m); i++) {
		int len = 0;
		for(int j = 1; j <= m; j++) {
			if(i & (1 << (j-1))) {
				len += num[j];
			}
		}
		for(int j = 1; j <= m; j++) {
			if(i & (1 << (j-1)))
				f[i] = min(f[i],f[i ^ (1<<(j-1))] + num[j]-sum[len][j]+sum[len-num[j]][j]);
		}
	}
	cout << f[(1<<m)-1] << "\n";
	return 0;
}