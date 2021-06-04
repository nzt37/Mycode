#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;


int main() {
    int x,y;
    cin >> x >> y;
    int s1 = x*y/2;
    int s2 = (y+100)*(100-x)/2;
    cout << 5000-s1-s2;

    return 0;
}
