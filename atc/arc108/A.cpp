#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main()
{
    int a,b;
    cin >> a >> b;
    for(int i = 1; i <= sqrt(b); i++) {
        int j = b/i;
        if(i+j == a) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;

}