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
int p[maxn];
int main() {
	cin >> n;
	cin >> s + 1;
	int j = 0;
	for(int i = 2; i <= n; i++) {
		while(j && s[i] != s[j+1]) j = p[j];
		if(s[i] == s[j+1]) j++; 
		p[i] = j;
	}
	cout << n - p[n] << "\n";
	return 0;
}