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
#define BR printf("--------------------\n")
#define debug(x) std::cerr << #x << '=' << x << '\n'
#define y1 yzang
using namespace std;

const int maxn = 2e3 + 10;

int n,m;
int a[maxn],b[maxn][maxn],vis[maxn][maxn];
int main() {
	cin >> n;
	int mx = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		mx = max(mx,a[i]);
		for(int j = 1; j <= 10 * a[i]; j++) {
			vis[i][j] = 1;
		}
	}
	int p = -1,num = 1;
	for(int i = 1; i <= 10 * mx  ; i ++) {
		for(int j = 1; j <= n; j++) {
			if(vis[j][i]) {
				if(p != j) {
					b[j][i] = num++;
					p = j;
				}
				else {
					num++;
					b[j][i] = num++;
					p = j;
				}
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		cout << i << "\n";
		for(int j = 1; j <= 10 * a[i]; j++) {
			cout << b[i][j] << " \n"[j % 10 == 0];
		}
	}
	return 0;
}