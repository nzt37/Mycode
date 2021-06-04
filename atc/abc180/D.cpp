#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main()
{
    int x,y,a,b;
    cin >> x >> y >> a >> b;
    int cnt = 0;
    while(x < y/a && x < (x+b)/a) {
        x *= a;
        cnt++;
    }
    cout << (y-1-x)/b + cnt << endl;
    return 0;
}