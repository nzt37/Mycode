#include <bits/stdc++.h>
using namespace std;
string s[400];
int n,m;
void solve()
{
    cin >> n;
    int cnt[3] = {0};
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(s[i][j] == 'X') {
                cnt[(i+j)%3]++;
            }
        }
     }
    int val = min_element(cnt,cnt+3) - cnt;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(s[i][j] == 'X' && (i+j)%3 == val)
            s[i][j] = 'O';
        }
    }
    for(int i = 0; i < n; i++) {
        cout << s[i] << endl;
    }
}
int main(){
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}