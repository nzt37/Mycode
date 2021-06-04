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

const int maxn = 1e6 + 10;

int n,m;
char s1[maxn],s2[maxn];
int p[maxn];
int main() {
	int T;
	cin >> T;
	while(T--) {
		cin >> s1 + 1;
		cin >> s2 + 1;
		int n1 = strlen(s1+1);
		int n2 = strlen(s2+1);
		// cout << n1 << " " << n2 << "\n";
		// CLR(p,0);
		int j = 0;
		p[1] = 0;
		for(int i = 2; i <= n1; i++) {
			while(j && s1[i] != s1[j+1]) j = p[j];
			if(s1[i] == s1[j+1]) j++;
			p[i] = j;
		}
		j = 0;
		// for(int i = 1; i <= n1; i++) cout << p[i] << "\n";
		int ans = 0;
		for(int i = 1; i <= n2; i++) {
			 while(s2[i] != s1[j+1] && j) j = p[j];
			if(s2[i] == s1[j+1]) j++;
			if(j == n1) ans++;
		}
		cout << ans << "\n";
	}	
	return 0;
}