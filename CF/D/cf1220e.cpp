#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn = 1000005;
int p[maxn];
void kmp(string s)
{
    s = ' ' + s;
    int n = s.size();
    int j = 0;
    p[0] = p[1] = 0;
    for(int i = 2; i <= n; i++) {
        while(j > 0 && s[i] != s[j+1]) j = p[j];
        if(s[i] == s[j+1]) j++;
        p[i] = j;
    }
}

int main() {
    int n;
    cin >> n;
    string ans,s;
    cin >> ans;
    for(int i = 2; i <= n; i++) {
        cin >> s;
        int m = min(s.size(),ans.size());
        string ss;
        ss = s + " $*&**&" + ans.substr(ans.size()-m,m);
        kmp(ss);
        for(int j = p[ss.size()]; j < s.size(); j++){
            ans += s[j];
        }
    }
    cout << ans;
    return 0;
}
