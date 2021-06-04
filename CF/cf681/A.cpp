#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int m = n*4;
    for(int i = 1; i <= n; i++){
        cout << m <<" ";
        m -= 2;
    }
    cout << endl;
}
int main() {
    int T;
    cin >> T;
    while(T--){
        solve();
    }

    return 0;
}
