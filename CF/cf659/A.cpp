#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];
int n,m;

void solve()
{
    cin >> n;
    string str(200,'a');
    cout << str << endl;
    for(int i = 0; i < n; i++) {
        int p;
        cin >> p;
        str[p] =  str[p] == 'a' ? 'b':'a';
        cout << str << endl;
    }
}
int main(){
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}