#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int p = abs(a-c);
    int q = abs(b-d);
    if(p + q == 0) { puts("0"); }
    else if((p + q <= 3) || p == q) { puts("1"); }
    else if(p + q <= 6 || (p + q) % 2 == 0 || ((p - min(p,q)) + (q - min(p,q) ) <= 3)) {
        puts("2");
    }else { puts("3"); };
}
int main()
{
    int T = 1;
    while(T--) {
        solve();
    }
    return 0;
}       