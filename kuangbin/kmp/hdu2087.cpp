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
char s1[maxn],s2[maxn];
int main() {
	while(~scanf("%s",s1)&& s1[0] != '#') {
		cin >> s2;
		int n1 = strlen(s1);
		int n2 = strlen(s2);
		int j = 0;
		p[0] = 0;
		for(int i = 1; i < n2; i++) {
			while(j && s2[i] != s2[j]) j = p[j-1];
			if(s2[i] == s2[j]) j++;
			p[i] = j;
		}
		j = 0;
		int ans = 0;
		for(int i = 0; i < n1; i++) {
			while(j && s1[i] != s2[j]) j = p[j-1];
			if(s1[i] == s2[j]) j++;
			if(j == n2) {
				j = 0;
				ans++;
			}
		}
		cout << ans << "\n";
	}|
+	return 0;
}