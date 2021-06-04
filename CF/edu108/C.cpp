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

const int maxn = 2e5 + 10;


void solve() {
    int N;
    cin >> N;
    vector<int> U(N);
    vector<int64_t> S(N);
 
    for (auto &u : U) {
        cin >> u;
        u--;
    }
    for (auto &s : S)
        cin >> s;
 
    int64_t sum = accumulate(S.begin(), S.end(), 0LL);
    vector<vector<int64_t>> c(N + 1);
 
    for (int i = 0; i < N; i++)
        c[U[i]].push_back(S[i]);
 
    for (int u = 0; u < N; u++)
        sort(c[u].begin(), c[u].end());
 
    vector<vector<int64_t>> b(N + 1);
 
    for (int u = 0; u < N; u++) {
        int len = int(c[u].size());
 
        if (b[len].empty())
            b[len].assign(len + 1, 0);
 
        int64_t partial = 0;
 
        for (int i = 0; i < len; i++) {
            partial += c[u][i];
            b[len][i + 1] += partial;
        }
    }
 
    vector<int64_t> l(N + 1, 0);
    for (int len = 1; len <= N; len++)
        if (!b[len].empty())
            for (int k = 1; k <= N; k++)
                l[k] += b[len][len % k];
 
    for (int k = 1; k <= N; k++)
        cout << sum - l[k] << (k < N ? ' ' : '\n');
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	int T;
	cin >> T;
	while(T--) {
		solve();
	}	
	return 0;
}