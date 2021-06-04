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

int n,m;
int a[maxn];
int main() {
	cin >> n;	
	for(int i = 1; i <= n ; i++) {
		cin >> a[i];
	}
	stack<int> q;
	q.push(a[1]);
	long long ans = 0;
	for(int i = 2; i <= n; i++) {	
		while(!q.empty() && q.top() <= a[i])  q.pop();
		if(!q.empty()) cout << i << " " << q.top() << "\n";
		ans += q.size();
		q.push(a[i]);
		// ans += q.size() - 1;
	}
	cout << ans << "\n";
	return 0;
}