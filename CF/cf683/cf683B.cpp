#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int a;
void solve()
{
    int n, m;
    cin >> n >> m;
    int cnt = 0,sum = 0,minn = 220;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a;
            if(a <= 0) {
                cnt++;
            }
            sum += abs(a);
            minn = min(minn,abs(a));
        }
    }
    cout << endl;
    //cout << sum << " " <<  minn << endl;
    if(cnt&1) {
        cout << sum - 2*minn << endl;
    }
    else {
        cout << sum << endl;
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
/*
   7 3
   -6 1 -4
   -84 -39 12
   -55 34 -77
   54 -100 -3
   -58 50 37
   16 68 78
   -38 -36 87 */
