#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 6;
int n,m;
int a[maxn];
void solve()
{
    cin >> n >> m;
    memset(a,0,sizeof a);
    for(int i = 1; i <= n; i++) {
    	cin >> a[i];
    }
    int pos = 0;
    for(int i = n; i >= 1; i--) {
    	if(a[i] != i) {
    		pos = i;
    		break;
    	}
    }
    double pp = 0,ppp = 1;
    double ans = 0;
    while(m--) {
    	int k;
    	double p;
    	cin >> k >> p; 
    	if(k < pos) continue;
    	ans += ppp * (1-pp) * p;
        ppp *= (1-pp); 
         pp = p;
    }
    if(pos == 0) puts("1.000000");
    else
    cout << fixed << setprecision(6) << ans << endl;
}
int main(){
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}