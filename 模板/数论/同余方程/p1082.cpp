#include <bits/stdc++.h>
#define int long long
using namespace std;
int x,y,a,b;

void exgcd(int a,int b,int &x,int &y)
{
    if(!b) {
        x = 1;
        y = 0;
        return;
    }
    exgcd(b,a%b,y,x);
    y = y - a / b * x;
}
signed main()
{
    int a,b;
    cin >> a >> b;
    exgcd(a,b,x,y);
    x = (x % b + b) % b;
    cout << x << endl;
    return 0;
}
