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
const int maxn = 1000007;

int n,m;
ll visit[maxn];
ll prime[maxn],cnt;
void Prime(){
    for (ll i = 2;i <= maxn; i++) {
        if (!visit[i]) {
            prime[++prime[0]] = i;
        }
        for (ll j = 1; j <= prime[0] && i*prime[j] <= maxn; j++) {
            visit[i*prime[j]] = 1;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
}
void solve() {
	
	int d;
	cin >> d;
	n = 1 + d;
	ll m = lower_bound(prime + 1, prime + 1  + prime[0], n) - prime;
	// cout << prime[2] << "\n";
	ll k = prime[m];
	m = upper_bound(prime+1,prime+1+prime[0],k)-prime;
	while(prime[m] - k < n-1	) m++;
	// cout << m << "\n";
	cout << prime[m] * k << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	Prime();
	int T;
	cin >> T;
	while(T--) {
		solve();
	}	
	return 0;
}