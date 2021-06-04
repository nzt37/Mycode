#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,k;
const int maxn = 505;
int a[maxn][maxn],b[maxn][maxn];
int f[maxn][maxn][11];
int main() {
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j < m; j++) {
			scanf("%d",a[i]+j);
		}
	}
	for(int i = 1; i < n; i++) {
		for(int j = 1; j <= m ; j++) {
			scanf("%d",b[i]+j);
		}
	}
	if(k & 1) {
		for(int i = 1; i <= n; i++,putchar('\n')) {
			for(int j = 1; j <= m; j++) {
				printf("-1 ");
			}
//			puts("");
		}
	}
	else {
		for(int c = 1; c <= k/2; c++) {
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= m; j++) {
					f[i][j][c] = INT_MAX;
					if(i > 1) {
						f[i][j][c] = min(f[i-1][j][c-1]+b[i-1][j],f[i][j][c]);
					}
					if(i < n) {
						f[i][j][c] = min(f[i+1][j][c-1]+b[i][j],f[i][j][c]);
					}
					if(j > 1) {
						f[i][j][c] = min(f[i][j-1][c-1]+a[i][j-1],f[i][j][c]);
					}
					if(j < m) {
						f[i][j][c] = min(f[i][j+1][c-1]+a[i][j],f[i][j][c]);
					}
				}
			}
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m ;j++) {
				printf("%d ",2*f[i][j][k/2]);
			}
			puts("");
		}
	}
	return 0;
	
}
