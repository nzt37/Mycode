#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int a,b,c,x,y,z;

int main() {
    int n;
    cin >> n;
    cin >> a >> b >> c;
    cin >> x >> y >> z;
    int ans1 = 0,ans2 = 0;
    ans1 += (a <= x+z ? 0 : a-x-z);
    ans1 += (b <= y+x ? 0 : b-y-x);
    ans1 += (c <= z+y ? 0 : c-y-z);
    ans2 += (a > y ? y : a);
    ans2 += (b > z ? z : b);
    ans2 += (c > x ? x : c);
    cout << ans1 << " " << ans2 << endl;
    return 0;
}
