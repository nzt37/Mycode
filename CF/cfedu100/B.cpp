#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
void solve()
{
    cin >> n;
    std::vector<int> a(n+1);
    // int sum_0 = 0,sum_1 = 0,sum = 0;
    int sum[2] = {0,0};
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i&1] += a[i];
    }
    int l = (sum[0] > sum[1]);
    for(int i = 1; i <= n; i++) {
        printf("%d ",(i&1) == l ? 1 : a[i]);
    }
    cout << endl;
}
signed main(){
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}