#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define Re register
#define LL long long
#define U unsigned
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;

const int maxn = 2e3 + 10;

int n,m,tot;
int x[maxn],y[maxn];
double f[maxn][maxn];
double cal(int i,int j)
{
	double xx=x[i]-x[j],yy=y[i]-y[j];
	return sqrt(xx*xx+yy*yy);
}
int main() {
	while((cin >> n)&&n) {
		// memset(f,0x7f,sizeof(f));
		CLR(f,0);
		for(int i = 1; i <= n; i++) {
			cin >> x[i] >> y[i];
		}
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				f[i][j] = cal(i,j);
				f[j][i] = cal(i,j);
			}
		}

		for(int k = 1; k <= n; k++) {
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= n; j++) {
					f[i][j] = min(f[i][j],max(f[i][k],f[k][j]));
				}
			}
		}
		tot++;
		printf("Scenario #%d\nFrog Distance = %.3lf\n\n",tot,f[1][2]);
	}	
	return 0;
}