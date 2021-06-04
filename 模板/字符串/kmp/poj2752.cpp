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
char s[maxn];
int p[maxn];
int main() {
	while(cin >> s + 1) {
		int j = 0;
		n = strlen(s+1);
		p[0] = p[1] = 0;
		for(int i = 2; i <= n; i++) {
			while(j && s[i] != s[j+1]) j = p[j];
			if(s[i] == s[j+1]) j++;
			p[i] = j;
		}
		// sort(p,p+1+n);
		std::vector<int> ans;
		std::vector<int> :: iterator it;
		ans.push_back(n);
		while(p[n]) {
			ans.push_back(p[n]);
			n = p[n];
		}
		sort(ans.begin(),ans.end());
		for(it = ans.begin(); it != ans.end(); it++){
			cout << (*it) << " ";
		}
		cout << "\n";
	}
	return 0;
}