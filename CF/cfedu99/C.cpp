#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--) {
        int a,b;
        cin >> a >> b;
        b += 1;
        if(a == 0) {
            cout << 0 << " " << b;
            break;
        }
        if(b == 0) {
            cout << a-1 << " " << 0;
            break;
        }
        cout << a - 1 << " " << b-1 << endl;
        }
    return 0;
}