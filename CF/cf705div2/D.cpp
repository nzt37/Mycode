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
#define BR printf("--------------------\n")
#define debug(x) std::cerr << #x << '=' << x << '\n'
#define y1 yzang
using namespace std;

const int maxn = 3e5 + 10;
const int mod= 1e9 + 7;
int n,m;
int a[maxn];
multiset<int> s[maxn];
map<int,int> f[maxn];
int p[maxn];
int ismp[maxn];
int pre[maxn];
int cnt = 0;
ll qpow(ll a, ll b) {
	ll ans = 1;
	while(b) {
		if(b & 1) ans = ans * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return ans;
}
int minprime[maxn];
void Prime(int x) {
	for(int i = 2; i <= x; i++) {
		if(!ismp[i]) p[++cnt] = i,ismp[i] = i;
		for(int j = 1; j <= cnt && i * p[j] <= x; j ++) {
			ismp[i*p[j]] = p[j];
			if(i % p[j] == 0) break;
		}
	}
}
int main() {
		ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	Prime(200000);
	for(int i = 1; i <= n; i++) {
		for(int j = 2; j * j <= a[i]; j++) {
			if(a[i] % j == 0) {
				int c = 0;
				while(a[i] % j == 0) {
					c++;
					a[i] /= j;
				}
				f[i][j] = c;
				s[j].insert(c);
			// cout << c << "cxac\n";
			}
		}
			if(a[i] > 1) {
				f[i][a[i]] = 1;
				s[a[i]].insert(1);
			}
	}
	ll g = 1;
	for(int i = 1; i <= cnt; i++) {
		int x = p[i];
		if(s[x].size() == n) {
			auto j = *s[x].begin();
			g = g * qpow(1ll*x,1ll*j) % mod;
			pre[x] = j; 
		}
	}	
	// cout << cnt << "\n";
	while(m--) {
		int id,x;
		cin >> id >> x;
		// cout << id << "fdsfds\n";
		for(int j = 1; p[j] * p[j] <= x && j <= cnt; j++) {
			if(x % p[j] == 0) {
				int c =0 ;
				while(x % p[j] == 0) {
					c++;
					x /= p[j];
				}
				// cout << x << " -4\n" ;
				// cout << c << "cascc\n";
				if(f[id].count(p[j])) {
					auto it = s[p[j]].find(f[id][p[j]]);
					// cout << -1 << "wer\n";
					s[p[j]].erase(it);
				}
				f[id][p[j]] += c;
				s[p[j]].insert(f[id][p[j]]);
				if(s[p[j]].size() == n) {
					auto it = *s[p[j]].begin();
					g = g * qpow(1ll*p[j],it - pre[p[j]]) % mod;
					// cout << g << " -1\n";
					pre[p[j]] = it; 
				}
				// cout << g << "csgfd\n";
			}
		}
				if(x > 1) {
					// cout << id << " " <<  x << " -4\n";
					if(f[id].count(x)) {
						auto it = s[x].find(f[id][x]);
						s[x].erase(it);
					}
					f[id][x] += 1;
					s[x].insert(f[id][x]);
					if(s[x].size() == n) {
						auto it = *s[x].begin();
						// cout << x << ' ' << pre[x] << "\n";
						g = g * qpow(1ll*x,it - pre[x]) % mod;
						// cout << g << " -2\n";
						pre[x] = it; 
					}
				}
		cout << g << "\n";
	}
	return 0;
}