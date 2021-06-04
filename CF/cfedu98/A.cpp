#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int a,b;
    cin >> a >> b;
    int m = min(a,b);
    int cnt = 0;
    cnt += 2*m;
    if(b > m) {
        cnt += (b-m)*2-1;
    }
    if(a > m) {
        cnt += (a-m)*2 - 1;
    }
    cout << cnt << endl;

}
int main()
{
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}