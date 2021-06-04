#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn = 2e5 + 8;
int len[maxn];
void solve()
{
    int n;
    string s;
    cin >> n;
    cin >> s;
    int cnt = 0;
    for(int i = 0, j; i < n; i = j) {
        for(j = i; j < n && s[i] == s[j]; j++);
        len[++cnt] = j-i;
    }
    int q = 1;
    int flag = 0,ans = 0;
    //cout << len[1] << endl;
    for(int i = 1; i <= cnt; i++) {
        if(flag) {
            ans++,i++;
            continue;
        }
        if(len[i] >= 2) {
            ans++;
        } 
        else{
            while(q < i || (q <= cnt && len[q] < 2)) q++;
            if(q > cnt) {
                flag = 1;
                ans++;
                i++;
            }
            else{
                ans++;
                len[q]--;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}
