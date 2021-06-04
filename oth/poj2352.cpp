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


const int maxn = 2e5 + 10;
const int maxm = 32010;

int n,m;
int c[maxn],a[maxn],b[maxn];
int ans[maxn];
int lowbit(int x) { return x & -x; }

void add(int x,int k) {
	for(int i = x; i <= maxm; i+=lowbit(i)) {
		c[i] += k;
	}
}
int que(int x) {
	int ans = 0 ;
	for(int i = x; i; i -= lowbit(i)) {
		ans += c[i];
	}
	return ans;
}
int main() {
	cin >> n;	
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		ans[que(a[i]+1)]++;
		add(a[i]+1,1);
	}
	for(int i = 0; i < n; i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}