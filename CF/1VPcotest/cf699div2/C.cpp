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

const int maxn = 4e5 + 5;

int n,m;
int a[maxn],b[maxn],c[maxn];
vector<int> e[maxn],ans;
void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) e[i].clear();
	ans.clear();
	for(int i = 1; i <= n; i++) {cin >> a[i];}
	for(int  i = 1; i <= n ;i++) {
		cin >> b[i]; 
	}
	for(int i = 1; i <= m; i++) {
		cin >> c[i];
	}
	int k = 0;
	for(int i = 1; i <= n; i++) {
		if(b[i] == c[m]) { k = i; break;}
	}
	if(k == 0) { cout << "NO" << "\n";}
	else {
		int cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] != b[i]) {
			e[b[i]].PB(i);
			cnt++;
		}
	}
	for(int i = m; i > 0;i--) {
		if(e[c[i]].empty()) {
			if(i == m) ans.PB(k);
			else ans.PB(ans[0]);
			continue;
		}
		ans.PB(e[c[i]].back());
		e[c[i]].pop_back();
		cnt--;
	}
	if(cnt) cout << "NO" << "\n";
	 else{ 
            cout<<"YES\n";
            reverse(ans.begin(),ans.end());
            for(auto&v:ans){ 
                cout<<v<<" ";
            }
            cout<<"\n";
        }
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