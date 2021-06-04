#include <bits/stdc++.h>

using namespace std;
const int maxn = 1010;
string s,s1;
int p[maxn];
int manacher()
{
    int n = s.size();
    s1 = "*$";
    for(int i = 0; i < n; i++) {
        s1 += s[i];
        s1 += "$";
    }
    int r = 1,mid = 1,ans = 0;
    for(int i = 1; i < s1.size(); i++) {
        if(i < r) {
            p[i] = min(p[(mid << 1) - i],r-i);
        }else {
            p[i] = 1;
        }
        while(s1[ i - p[i] ] == s1[ i + p[i] ]) p[i]++;
        if(p[i] + i > r) {
            r = p[i] + i;
            mid = i;
        }
        ans = max(ans,p[i]-1);
    }
    return ans;
}
int main()
{
    getline(cin,s);
    cout << manacher();
   // cout << s1 << endl;
}