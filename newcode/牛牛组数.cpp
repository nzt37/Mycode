#include <bits/stdc++.h>

using namespace std;
int a[10007];
int main()
{
    string s;
    int k;
    cin >> s;
    cin >> k;
    int n = s.size();
    sort(s.begin(),s.end());
    for(int i = k-1; i < n; i++) {
        a[i-(k-1)] = s[i] - 48;
    }
    for(int i = 0; i < k-1; i++) {
        a[0] += s[i] - 48;
    }
    // for(int i = 0; i < n; i++) {
    //     cout << a[i] << endl;
    // }
    int up = 0;
    for(int i = 0; i < n; i++) {
        if(a[i]) up = i;
        if(a[i] > 10) {
            a[i+1] += a[i]/10;
            a[i] = a[i]%10;
        }
    }
    string ans = "";
    for(int i = up; i >= 0; i--) {
        ans += a[i]+'0';
    }
    cout << ans;
    return 0;
}