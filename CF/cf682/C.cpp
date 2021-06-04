#include <bits/stdc++.h>

using namespace std;
const int maxn = 120;
int a[maxn][maxn];

void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if((i+j)&1) {
                if(a[i][j]%2 == 0) ++a[i][j];
            }
            else {
                if(a[i][j]%2 != 0) {
                    ++a[i][j];
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}
