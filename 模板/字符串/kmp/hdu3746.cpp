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
char s[maxn];
int main() {
	int T;
	cin >> T;
	while(T--) {
		scanf("%s",s+1);
		int j = 0;
		int n = strlen(s+1);
		p[0] = p[1] = 0;
		for(int i = 2; i <= n; i++) {
			while(j && s[i] != s[j+1]) j = p[j];
			if(s[i] == s[j+1]) j++;
			p[i] = j;
		}
		int len = n - p[n];
		if(p[n] == 0) cout << n << "\n";
		else {
			if(n % len == 0) 	{
				cout << 0 << "\n";
			}
			else {
				cout << len - n % len << "\n";
			}

		}
	}	
	return 0;
}