#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
#define int long long
const int maxn = 2e5+5;
int a[maxn],sum,n,k;

void solve(){
    cin >> n >> k;
    for(int i = 1; i <= n*k; i++) {
        cin >> a[i];
    }
    int temp = n / 2;
    //cout << temp << " dsf " << endl;
    sum = 0;
    for(int i = n*k - temp, j = k; j > 0; i -= temp,j-- ) {
        //cout << i << " i " << endl;
        sum += a[i];
        --i;
    }
    cout << sum << endl;
}

signed main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}
//7 2
//8 23 29 31 39 40 44 48 54 56 66 76 84 93
//8 29 31 39 40 44 48
//23 54 56 66 76 84 83
// 44 48 54 56
