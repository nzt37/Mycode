#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn = 3e4+5;
int a[maxn],ans[maxn];

void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        ans[i] = a[i]-a[i-1];
    }
    int sum = 0;
    for(int i = 2; i <= n; i++) {
        if(ans[i] < 0) {
            sum += ans[i];
        }
    }
    if(-sum <= a[1]) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}
