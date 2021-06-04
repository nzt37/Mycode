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
int p[maxn];
string s[maxn];
string s1;
void init(string s2) {
	s1 = "~#";
	for(int i = 0; i < (int)s2.size(); i++) {
		s1 += s2[i];
		s1 += '#';
	}
	s1 += '$';
}
bool manacher(string ss) {
	CLR(p,0);
	init(ss);
	int r  = 1;
	int mid = 1;
	int ans = 0;
	for(int i = 1; i < (int)s1.size(); i++) {
		if(i < r) p[i] = min(p[(mid<<1)-i],r-i);
		while(s1[i-p[i]] == s1[i+p[i]]) ++p[i];
		if(p[i] + i > r) {
			 r = p[i] + i;
			 mid = i;
		}
		ans = max(ans,p[i] - 1);
	}
	// cout << ans << " " << s1<<  "\n";
	if(ans == (int)ss.size()) {
		return true;
	}
	return false;
}
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> m >> s[i];
	}	
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			string ss = s[i] + s[j];
			if(manacher(ss)) {
				cnt++;
			}
		}
	}
	cout << cnt << "\n";
	return 0;
}