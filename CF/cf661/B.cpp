#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;
int n,m;
void solve()
{
    cin >> n;
    vector<int> a(n),b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    } 
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int cnt1 = *min_element(a.begin(),a.end());
    int cnt2 = *min_element(b.begin(),b.end());
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += max(a[i] - cnt1,b[i] - cnt2);
    }
    cout << ans << "\n";
}

signed main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}
