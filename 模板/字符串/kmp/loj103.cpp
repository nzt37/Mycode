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

const int maxn = 1e6 + 10;

int n,m;
char s1[maxn],s2[maxn];
int p[maxn];
int main() {
	cin >> s1 + 1;
	cin >> s2 + 1;
	int l1 = strlen(s1+1);
	int l2 = strlen(s2+1);
	int j = 0;
	for(int i = 2; i <= l2; i++) {
		while(j && s2[i] != s2[j+1]) j = p[j];
		if(s2[i] == s2[j+1]) j++;
		p[i] = j;
	}
	j = 0;
	int ans = 0;
	for(int i = 1; i <= l1; i++) {
		while(j && s1[i] != s2[j+1]) j = p[j];
		if(s1[i] == s2[j+1]) j++;
		if(j == l2) {
			ans++;
			//j = 0;
		}
	}
	cout << ans << "\n";
	return 0;
}