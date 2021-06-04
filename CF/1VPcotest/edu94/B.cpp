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
	int p,f,cnts,cntw,s,w;
	cin >> p >> f;
	cin >> cnts >> cntw;
	cin >> s >> w;
	if(s > w) swap(s,w),swap(cnts,cntw);
	int ans = 0;
	for(int i = 0; i <= cnts; i++) {
		if(i * s > p) break;
		int cnt = 0,s1 = cnts,w1 = cntw;
		cnt += i,s1 -= i;
		int k = min((p-i*s)/w,w1);
		cnt += k,w1 -= k;
		int x = min(f/s,s1);
		cnt += x,s1 -= x;
		int y = min((f-x*s)/w,w1);
		cnt += y,w1 -= y;
		ans = max(ans,cnt);
		}
		cout << ans << "\n";
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