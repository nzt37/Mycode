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

const int maxn = 2e5 + 10;

int n,m;
void solve() {
	cin >> n >> m;
	std::vector<std::vector<int> > a(m);
	std::vector<int> cnt(n);
	std::vector<int> an(m);
	int mx = (m + 1) / 2;
	for(int i = 0; i < m; i++) {
		int k;
		cin >> k;
		a[i].resize(k);
		for(int j = 0; j < k; j++) {
			cin >> a[i][j];
			a[i][j]--;
		}
		if(k == 1) {
			cnt[a[i][0]]++;
			an[i] = a[i][0];
		}
	}
	if(*max_element(all(cnt)) > mx) {
		cout << "NO" << "\n";
		return;
	}
	for(int i = 0; i < m; i++) {
		if(a[i].size() >= 2) {
			for(auto j : a[i]) {
				if(cnt[j] < mx) {
					cnt[j]++;
					an[i] = j;
					break;
				}
			}
		}
	}
	cout << "YES" << "\n";
	for(int i = 0; i < m; i++) {
		cout << an[i]+1 << " \n"[i==m-1];
	}

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