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
bool issquare(int n) {
    int x = std::sqrt(n);
    return x * x == n;
}
int n,m;
set<int> s;
void solve() {
    std::cin >> n;
    if ((n % 4 == 0 && issquare(n / 4)) || (n % 2 == 0 && issquare(n / 2))) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	// int an1 = 2;
	// int an2 = 4;
	// while(an1 <= 1e9) {
	// 	s.insert(an1);
	// 	an1 *= 4;
	// }
	// while(an2 <= 1e9) {
	// 	s.insert(an2);
	// 	an2 *= 4;
	// }
	int T;
	cin >> T;
	while(T--) {
		solve();
	}
	return 0;
}