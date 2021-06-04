#include <bits/stdc++.h>
using namespace std;
const int maxn = 31000010;
int p[maxn];
string s,ss;
void init(string s)
{
    ss = "~$";
    int l = 2;
    for(int i = 0; i < s.size(); i++){
        ss += s[i];
        ss += "$";
    }
    ss += "#";
}
int manacher()
{
    int r = 1,mid = 1,ans = 0;
    for(int i = 1; i < ss.size(); i++) {
        if(i < r) {
            p[i] = min(p[(mid << 1) - i], r - i);
        }
        else p[i] = 1;
        while(ss[i-p[i]] == ss[i + p[i]]) p[i]++;
        if(p[i] + i > r) {
            r = p[i] + i;
            mid = i;
        }
        ans = max(ans, p[i] - 1);     
    }
    return ans;
}
int main()
{
    cin >> s;
    init(s);
    printf("%d",manacher());
    return 0;
}
