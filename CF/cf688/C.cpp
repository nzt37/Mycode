#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
int n,m;
void solve()
{
    cin >> n;
    vector<string > s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int ans[10] = {0};
    auto work = [&]() {
        int u[10];
        fill(u,u+10,-1);
        for(int i = 0; i < n; i++) {
            int f[10];
            fill(f,f+10,-1);
            for(int j = 0; j < n; j++) {
                int x = s[i][j] - 48;
                if(f[x] == -1) {
                    f[x] = j;
                } else {
                    ans[x] = max(ans[x],(j-f[x]) * max(i,n-1-i));
                }
                if(u[x] == -1) {
                    u[x] = i;
                }
                else {
                    ans[x] = max(ans[x],(i-u[x]) * max(j,n-1-j));
                }
            }
        }
    };
    work();
    reverse(s.begin(),s.end());
    work();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            std::swap(s[i][j], s[j][i]);
        }
    }
    work();
    //for(int i = 0; i < n; i++) {
    //cout << s[i] << endl;;
    //}
    reverse(s.begin(),s.end());
    work();
    for(int i = 0 ;i <= 9; ++i) {
        cout << ans[i] << " \n"[i == 9];
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
