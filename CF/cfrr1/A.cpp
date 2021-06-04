#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int p = abs(a-c) + abs(b-d);
    if(a != c && b != d) {
        p += 2;
    }
    cout << p << endl;
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