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

const int maxn = 2e6 + 10;

int n,m;
char s[maxn];
int f[maxn];
int main() {
	cin >> s+1;
	int n = strlen(s+1);
	int l = 0,r = 0,ans = 0;
	for(int i = 2; i <= n; i++) {
		if(s[i] == ')' || s[i] == ']') {
			if((s[i] == ')' && (s[i-f[i-1]-1] == '(')) || (s[i] == ']' && (s[i-f[i-1]-1] == '[')) ) {
				f[i] = f[i-1]+2 + f[i-f[i-1]-2];
				if(f[i] > ans) {
					// cout << f[i] << "\n";
					l = i - f[i] + 1;
					r= i;
					ans = f[i];
				}	
			}
		}
	}
	for(int i = l; i <= r; i++) {
		cout << s[i];
	}

	return 0;
}