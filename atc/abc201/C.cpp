#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
ll n;
const int N = 410;
ll F[N], invn[N], invF[N], bit[N];

void init() {
    bit[1] = F[0] = F[1] = invn[0] = invn[1] = invF[0] = invF[1] = 1;
    for(int i = 2;i < N; i++){
        F[i] = F[i - 1] * i % mod;
        invn[i] = (mod - mod / i) * invn[mod % i] % mod;
        invF[i] = invF[i - 1] * invn[i] % mod;
        bit[i] = bit[i - 1] * 2 % mod;
    }
}
init
ll C(ll m, ll n) {
    if(m < 0 || n < 0 || n > m)
        return 0;
    ll ans = F[m];
    ans = ans * invF[n] % mod;
    ans = ans * invF[m - n] % mod;
    return ans;
}

void solve() {
	init();
    string s;
    cin >> s;
    int a= 0 ,b = 0,c = 0;
    for(int i = 0; i < 10; i++) {
    	if(s[i] == 'o') a++;
    	else if(s[i] == '?') b++;
    	else c++; 
    }
    if(a > 4) {
    	cout << 0 << "\n";
    	return;
    }
    if(a == 4) {
    	cout << 1 << "\n";
    }
    ll ans = C(4,a);
    for(int i = 1; i <= min(b,3); i++) {
    	ans += C(4,i);
    	// cout << ans << "\n";
    }
    if(b > 4) {
    	ans *= C(b,4);
    }
    cout << ans << "\n";
}

signed main() {
    solve();
}
