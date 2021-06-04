#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main() {
    double a,b,c,d;  
    cin >> a >> b >> c >> d;
    // 1 1 7 2
    double m = (a*d + b*c) / (b + d);
    cout << fixed <<  setprecision(10) << (m) << endl;

    return 0;
}
