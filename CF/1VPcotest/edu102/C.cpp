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
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("qqglb")
#define y1 yzang
using namespace std;

const int maxn = 2e5 + 10;

int n,m;
int a[maxn];
void solve() {
	cin >> n >> m;
	CLR(a,0);
	if(n == m) {
		for(int i = 1; i <= m; i++) {
			cout << i << " ";
		}
	}
	else {
		int cnt = 0;
	int p = n - m + 1;
	int j = 1;
	for(int i = p; i < m; i++) {
		a[++cnt] = j;
		j++;
	}
	j = m;
	for(int i = m; i <= n; i++) {
		a[++cnt] = j;
		j--;
	}
	for(int i = 1; i <= cnt; i++) {
		cout << a[i] << " ";
	}
	}
	cout << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	int T;
	cin >> T;
	while(T--) {
		solve();
	}	
}