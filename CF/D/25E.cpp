#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn = 1e5+ 6;
char a[maxn],b[maxn],c[maxn];
int p[maxn];
int kmp(char s1[],char s2[])
{
    int n = strlen(s1+1);
    int m = strlen(s2+1);
    int j = 0;
    for(int i = 2; i <= n; i++) {
        while(j > 0 && s1[i] != s1[j+1]) j = p[j];
        if(s1[i] == s1[j+1]) j++;
        p[i] = j;
    }
    j = 0;
    int maxx = 0;
    for(int i = 1; i <= m; i++) {
        while(j > 0 && s2[i] != s1[j+1]) j = p[j];
        if(s2[i] == s1[j+1]) {
            j++;
            maxx = max(j,maxx);
        }

    }
    return maxx;
}
int main() {
    scanf("%s",a+1);
    scanf("%s",b+1);
    scanf("%s",c+1);
    int ans = (strlen(a+1) + strlen(b+1) + strlen(c+1));
    int x = kmp(a,b);
    int y = kmp(b,c);
    int z = kmp(a,c);
    cout << x << endl;
    return 0;
}
