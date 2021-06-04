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

int n,m;
void dfs(U LL ans,int n,int step) {
	if(n == 0) exit(0);
	if(m == 0) return;
	if(step >= 20) return;
	if(ans % n == 0) {
		m = 0;
		cout << ans << "\n";
		return;
	}
	dfs(ans * 10,n,step + 1);
	dfs(ans * 10 + 1,n,step + 1);
	
}
int main(){
   while(~scanf("%d",&n)) {
   	m = 1;
   		// cin >> m;
   		dfs(1,n,1);
   }  
    return 0;
}