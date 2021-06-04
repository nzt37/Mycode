#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;


int main() {
    double a,b;
    cin >> a >> b;
    double m = a/(pow(b,2));
    printf("%.1f\n",m);
    cout << (m > 25.0?"PANG":"Hai xing") ;

    return 0;
}
