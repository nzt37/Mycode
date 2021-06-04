#include <bits/stdc++.h>

using namespace std;
char s[200005];
map<char,int> p;
void solve()
{

    scanf("%s",s);
    int cnt1 = 0,cnt2 = 0,ans = 0;
    for(int i = 0; i < strlen(s); i++) {
        if(s[i] == '[' ) {
            cnt1++;
        }
        else if(s[i] == '(') {
            cnt2++;
        }
        else if(s[i] == ']'){
            if(cnt1) {
                ans++;
                cnt1--;
            }
        }
        else if(s[i] == ')') {
            if(cnt2) {
                ans++;
                cnt2--;
            }
        }
    }
    cout << ans << '\n';
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