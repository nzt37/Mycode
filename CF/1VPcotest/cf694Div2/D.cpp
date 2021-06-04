#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 6;
int n,m;
int a[maxn];
void solve() {
    cin >> n;
    map <int,int> c;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        int tmp = a[i];
        for(int j = 2; j * j <= tmp; j++) {
            if(tmp % j == 0) {
                int cnt = 0;
                while(tmp % j == 0) { tmp /= j, a[i] /= j, cnt++;}
                if(cnt & 1) a[i] *= j;
                
            }
        }
        c[a[i]]++;
    }
    int an_1 = 0;
    int an_2 = c[1];
    for(auto i : c) {
        an_1 = max(an_1,i.second);
        if(i.first > 1 && (i.second  & 1) == 0) {
            an_2 += i.second;
        }
    }
//  cout << an_1 << " " <<  an_2 << "\n";
    cin >> m;
    while(m--) {
        long long b;
        cin >> b;
        if(b) cout << max(an_1,an_2) << "\n";
        else cout << an_1 << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        solve();
    }   
    return 0;
}