#include <bits/stdc++.h>
using namespace std;

int n,m;

void solve()
{
    cin >> n;
    string s1,s2;
    cin >> s1 >> s2;
    int cnt1 = 0,cnt2 = 0;
    vector<int > a(n);
    vector<int > b(n);
    for(int i = 1; i < n; i++) {
        if(s1[i] != s1[i-1]) {
            a[cnt1++] = i;
        }
    }
    for(int i = 1; i < n; i++) {
        if(s2[i] != s2[i-1]) {
            b[cnt2++] = i;
        }
    }
    if(s1[n-1] != s2[n-1]) {
        a[cnt1++] = n;
    }
    cout << cnt1 + cnt2  << " ";
    for(int i = 0; i < cnt1; i++) {
        cout << a[i] << " ";
    }
    for(int i = cnt2 - 1; i >= 0; i--) {
        cout << b[i] << " ";
    }
       cout << endl;


}
int main(){
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}