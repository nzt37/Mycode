#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define mid ((r+l)>>1)
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug cout << "dsdsdsdsd" << "\n";
#define y1 yzang
using namespace std;

const int maxn = 2e5 + 10;

int n,m;
char s[maxn],s1[maxn];
int f[3500][3500];
int main() {
	cin >> s + 1;
	cin >> s1 + 1;
	int n = strlen(s+1);
	int m = strlen(s1+1);
	for(int i = 1; i <= m; i++) {
		f[0][i] = i;
	}
	for(int i = 1; i <= n; i++) {
		f[i][0] = i;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(s[i] == s1[j]) {
				f[i][j] = f[i-1][j-1];
			}
			else {
				f[i][j] = min(f[i-1][j]+1,min(f[i-1][j-1]+1,f[i][j-1]+1));
			}
		}
	}
	cout << f[n][strlen(s1+1)] << "\n";
	return 0;
}