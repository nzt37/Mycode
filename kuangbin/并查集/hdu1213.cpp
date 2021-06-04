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
int f[maxn];
inline int find(int x) {
	if(f[x] == x ) return x;
	return f[x] = find(f[x]);
}
void merge(int x,int y) {
	int a = find(x);
	int b = find(y);
	if(a != b)  {
		f[a] = b;
	}
}
int main() {
	int T;
	cin >> T;
	while(T--) {
		cin >> n >> m;
		// std::vector<int> a(n);
		CLR(f,0);
		for(int i = 1; i <=  n; i++) f[i] = i;
		for(int i = 1; i <= m; i++) {
			int a,b;
			cin >> a >>  b;
			merge(a,b);
		}
		set<int> q;
		for(int i = 1; i <= n; i++) {
			int a = find(i);
			q.insert(a);
		}
		cout << q.size() << "\n";
	}
	return 0;
}