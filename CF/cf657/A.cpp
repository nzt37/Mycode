#include <bits/stdc++.h>
using namespace std;

int n,m;
string t = "abacaba";

bool check(string s,int k)
{
    for(int i = 0; i < 7; i++) {
        if(s[k+i] == '?') {
            s[k+i] = t[i];
        }
        else if(s[k+i] != t[i]) {
            return false;
        }
    }
    int cnt = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s.substr(i,7) == t) {
            cnt++;
        }
    }
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '?') {
            s[i] = 'z';
        }
    }
    if(cnt == 1) {
        cout << "YES" << '\n' << s << '\n';
        return true;
    }
    return false;
}
void solve()
{
    cin >> n;
    string s;
    vector<char> a(27);
    cin >> s;
    int cnt = 0;
    int flag = 0;
    for(int i = 0; i < n - 6; i++) {
        if(check(s,i)) {
            flag = 1;
            break;
        }
    }
    if(!flag) {
        cout << "NO" << '\n'; 
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