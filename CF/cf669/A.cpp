#include <bits/stdc++.h>
//#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ls x*2

using namespace std;
const int maxn = 3e2+7;
int a[maxn],b[maxn];
void solve()
{
    int N;
    cin >> N;
    N /= 2;
    while(N--){
        int a, b;
        cin >> a >> b;
        cout << -b << " " << a << " " ;
    }
}
signed main() {
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}


