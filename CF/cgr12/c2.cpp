#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int m,n;
string s[440];
void solve()
{
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int cnt[2][3] = {0};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(s[i][j] == 'O') {
                cnt[0][(i+j)%3]++;
            }
            if(s[i][j] == 'X') {
                cnt[1][(i+j)%3]++;
            }
        }
    }
    int x = 0;
    for(int i = 1; i < 3; i++) {
        if(cnt[0][i] + cnt[1][(i+1)%3] < cnt[0][x] + cnt[1][(x+1)%3]) {
            x = i;
        }    
    }
    int ii,jj;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(s[i][j] == 'O' && (i+j)%3 == x) {
                s[i][j] = 'X';
            }
            if(s[i][j] == 'X' && (i+j)%3 == (x+1)%3) {
                s[i][j] = 'O';
            }
        }
        cout << s[i] << endl;
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
