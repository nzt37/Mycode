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

int n,m,p[maxn];
string s1,s;
void init() {
	s1 += "~#";
	for(int i = 0; i < (int)s.size(); i++) {
		s1 += s[i];
		s1 += '#';
	}
	s1 += '#';
}
int main() {
	int an =0 ;
	while(cin >> s) {
		if(s == "END") break;
		s1 = "";
		init();
		int ans = 0; 
		CLR(p,0);
		for(int i = 1,mid = 1,r = 1; i < s1.size(); i++) {
			if(i < r) p[i] = min(p[(mid<<1)-i],r-i);
			while(s1[i-p[i]] == s1[i+p[i]]) ++p[i];
			if(p[i] + i > r) {
				r = p[i] + i;
				mid = i;
			}
			ans = max(ans,p[i]-1);
		} 
		printf("Case %d: %d\n",++an,ans);
	}
	return 0;
}