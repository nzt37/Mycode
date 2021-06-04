#include <bits/stdc++.h>

using namespace std;
int b[350550];
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    int flag1 = 1,flag2 = 1;
    for(int i = 0; i < n; i++) b[i] = 0;
    for(int i = 0; i < n; i++) {
       if(s[i] == '>') flag1 = 0;
       if(s[i] == '<') flag2 = 0;
    }
    for(int i = 0; i < n; i++) {
        if(s[i] == '-' || s[(i+n-1)%n] == '-') b[i] = 1;
        else b[i] = flag2|flag1;
    }
    for(int i = 0; i < n; i++) {
        cnt += b[i];
    }
    cout << cnt << endl;
}
int main()
{
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}