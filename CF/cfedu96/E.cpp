#include <bits/stdc++.h>
using namespace std;
const int  maxn = 1e5 + 5;
long long  ans;
int n,m;
int cnt[27],pos[27];
int main(){

    string s,r;
    cin >> n >> s;
    s = " " + s;
    r = s;
   
    for(int i = 1; i <= n; i++) {
        int t = s[i] - 'a';
        cnt[t]++;
        if(pos[t] == 0) {
            pos[t] = i;
        }
    }
    for(int i = n; i >= 1; i--) {
        int t = r[i] - 'a';
        //cout << pos[t] << " "<< t << endl;
        ans += pos[t] - 1;
        s.erase(pos[t],1);
        cnt[t]--;
        for(int j = 0; j < 26; j++) {
            if(pos[j] > pos[t]) {
                pos[j]--;
                // cout << "dsad " << j << pos[j] << endl; 
            }
        }
        if(cnt[t] == 0) {
            pos[t] = 0;
        }
        else {
            while(s[pos[t]] - 'a'   != t) {
                pos[t]++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}