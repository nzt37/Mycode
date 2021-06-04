#include <bits/stdc++.h>
using namespace std;

int n,m;

void solve()
{
    cin >> n >> m;
    string s;
    cout << string(m,'a');
    for(int i = 1; i <= (n-m); i++) {
        cout << (char)((i%3)+'a');
    }
    cout << endl;
}
int main(){
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}