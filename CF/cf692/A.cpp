#include <bits/stdc++.h>
using namespace std;

int n,m;
void solve()
{
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for(int i = n-1; i >= 0; i--) {
        if(s[i] != ')') break;
        else cnt++;
    }
   // cout << cnt << endl;
    if(cnt > n/2) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}