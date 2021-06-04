#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 6;
const int mod = 998244353;
int n,m,cnt;
int f[maxn],in[maxn],head[maxn],num[maxn];

struct node {
	int u,v,w,next;
}edge[700005<<1];
stack<int> s;
void addedge(int u,int v)
{
	edge[++cnt].next = head[u];
	edge[cnt].v = v;
	edge[cnt].u = u;
	head[u] = cnt;
}
int ans,sum;
void topo() {
	while(s.size()) {
		int x = s.top();
		// cout << x << endl;
		s.pop();
		for(int i = head[x]; i ; i = edge[i].next) {
			int y = edge[i].v;
			--in[y];
			num[y] = (num[x] + num[y]) % mod;
			f[y] = (f[x] + f[y] + num[x]) % mod; 
			if(!in[y]) {
				s.push(y);
			}
		}
	}
	// cout << "ds" << endl;
	for(int i = 1; i <= n; i++) {
		ans =  (ans + num[i]) % mod;
		sum = (sum + f[i]) % mod;
	}
} 
int qpow(int a,int b)
{
	int ans = 1;
	a %= mod;
	while(b) {
		if(b & 1) ans = (ans * a) % mod;
		b >>= 1;
		a = (a * a) % mod;
	}
	return ans % mod;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
    	int u,v;
    	cin >> u >> v;
    	addedge(u,v);
    	in[v]++;
    }
	for(int i = 1; i <= n; i++) {
		num[i] = 1;
		if(!in[i] ) {
			s.push(i);
		}
	}
	//cout << "sds" << endl;
	topo();
	//cout << sum << ans << endl;
	cout << (sum * qpow(ans,mod-2)) % mod << endl;
    return 0;
}