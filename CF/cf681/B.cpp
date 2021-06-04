#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn = 1e5+6;
int len[maxn],v[maxn];
string s;
int a, b;
void solve() {
    cin >> a >> b;
    cin >> s;
    int cnt = 0;
    int n = s.size();
    for(int i = 0,j; i < n; i = j) {
        for(j = i; j < n && s[i] == s[j]; j++);
        len[cnt] = j - i;
        v[cnt] = s[i] - '0';
        cnt++;
    }
    int one_cnt = 0;
    vector<int > pp;
    for(int i = 0; i < cnt; i++) {
        if(v[i] == 1) {
            one_cnt++;
        }
        else {
            if(i != 0 && i + 1 < cnt)
                pp.push_back(len[i]);
        }
    }
    sort(pp.begin(), pp.end());
    long long an = 1e18;
    int sum = 0;
    for(int i = 0; i <= (int)pp.size(); i++){
        an = min(an,1ll*(one_cnt-i)*a + sum*b);
        if(i < (int)pp.size())
            sum += pp[i];
    }
    printf("%lld\n",an);
}
int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}
