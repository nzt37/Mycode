#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
void solve()
{
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int sum = 0;
    int an = INT_MAX;
    for(int i = 0 ;i < n; i++) {
        int flag = 0,cnt = 0,ans = 0;
        sum += a[i];
        for(int j = 0; j < n; j++) {
            if(ans) {
                cnt++;
            }
            ans += a[j];
            if(ans > sum) {
                flag = 1;
                break;
            }
            else if(ans == sum) {
                ans = 0;
            }
        }
        if(!flag && ans == 0) {
            an = min(an,cnt);
        }
    }
    cout << an << endl;
}
signed main(){
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}