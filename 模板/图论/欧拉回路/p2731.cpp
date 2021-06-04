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

const int maxn = 2e3 + 10;

int n,m;
int e[maxn][maxn];
int in[maxn];
stack<int> sa;
void f(int u) {
	for(int i = 1; i <= 500; i++) {
		if(e[u][i]) {
			e[u][i]--;
			e[i][u]--;
			f(i);
		}
	}
	sa.push(u);
}
int main() {
	cin >> n;
	int mi = INT_MAX;
	for(int i = 1; i <= n; i++) {
		int u,v;
		cin >> u >> v;
		e[u][v]++;
		e[v][u]++;
		in[u]++;
		in[v]++;
		mi = min(mi,u);
		mi = min(mi,v);
	}
	int s = -1;
	for(int i = 1; i <= n; i++) {
		if(in[i] & 1) {
			s = i;
			break;
		}
	}
	if(s == -1) {
		f(mi);
	}
	else {
		f(s);
	}
	while(!sa.empty()) {
		cout << sa.top() << "\n";
		sa.pop();
	}
	return 0;
}