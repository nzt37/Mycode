#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e6 + 6;
int f[maxn];
const int p  = 20100403; 

int inv[maxn];
void init(int n)
{
	f[0] = 1;
	for(int i = 1; i <= n; i++) f[i] = (i* f[i-1]) % p;
	inv[1] = 1;
	for(int i = 2; i <= n; i++) {
		inv[i] = (p-p/i)*inv[p%i]%p;
	}
	for(int i = 2; i <= n; i++) {
		inv[i] = inv[i]*inv[i-1]%p;
	}
}
int qpow(int a,int b)
{
	int ans = 1;
	a %= p;
	while(b) {
		if(b&1) ans = (ans * a) % p;
		b >>= 1;
		a = (a * a) % p;
	}
	return ans % p;
}
int C(int n,int m)
{
	if(m == 0 || n == m) return 1;
	if(m < 0 || m > n) return 0;
	return f[n] * qpow(f[n-m]*f[m],p-2) % p;
}
int lucas(int n,int m)
{
	if(m == 0) return 1;
	return C(n%p,m%p) * lucas(n/p,m/p) % p;
}
void solve() {
	int n,m;
    cin >> n >> m;
    init(n+m);
	if(n<m||m+n==0){
		cout << 0;
		return ;
	} 
    // cout << lucas(n+m,n)%p << endl;
		// cout << (C(n+m,m) - C(n+m,n+1) + p) % p << "\n";
     cout << (lucas(n+m,m) - lucas(n+m,n+1) + p) % p << "\n";

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T = 1;
	// cin >> T;
    while(T--) {
    	solve();

    }
    return 0;
}