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

const int maxn = 2e6 + 10;

int n,m;
int a[maxn];
int main() {
	while(cin >> n) {
		map<int,int> mp;
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
			mp[a[i]]++;
			if(mp[a[i]] >= (n+1)/2) {
				ans = a[i];
			}
		}
		cout << ans << "\n";
	}
	return 0;
}