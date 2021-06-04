#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
#define int long long 
const int maxn = 2e5 + 9;
int a[maxn], b[maxn],f[maxn],c[maxn],n;
void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    vector<pair<int ,int > > pp;
    for(int i = 1; i <= n; i++){
        pp.push_back(make_pair(a[i],b[i]));
    }
    sort(pp.begin(),pp.end());
    long long an = 1e18;
    long long sum = 0;
    for(int i = n; i >= 0; i--){
        an = min(an,max(sum, i > 0 ? pp[i-1].first : 0LL));
        if(i > 0)
            sum += pp[i-1].second;
    }
    printf("%lld\n",an);
}

signed main() {
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
