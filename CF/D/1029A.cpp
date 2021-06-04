#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const int maxn = 5050;
int p[maxn],n,k;
char s[maxn];

void kmp(string s)
{
    int j = 0;
    int n = s.size();
    for(int i = 1; i < n; i++) {
        while( j > 0 && s[i] != s[j+1]) j = p[j];
        if(s[i] == s[j+1]) j++;
        p[i] = j;
    }
}
int main() {

    cin >> n >> k;
    cin >> s+1;
    string ss = "";
    ss += s;
    int j = 0;
    for(int i = 2; i <= n; i++) {
        while( j > 0 && s[i] != s[j+1]) j = p[j];
        if(s[i] == s[j+1]) j++;
        p[i] = j;
    }
    for(int i = 1; i <= n; i++) {
        cout << s[i];
    }
    for(int i = 1; i < k; i++) {
        cout << s+p[n]+1;
    }
    return 0;
}
