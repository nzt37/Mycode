#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
char a[maxn],b[maxn];
int p[maxn];
int t[maxn],top,f[maxn];
int main()
{
    cin >> a+1;
    cin >> b+1;
    p[0] = p[1] = 0;
    int n = strlen(a+1),j = 0,n1 = strlen(b+1);
    for(int i = 2; i <= n1; i++) {
        while(j && b[i] != b[j+1]) j = p[j];
        if(b[i] == b[j+1]) j++;
        p[i] = j;
    }
    j = 0;
    for(int i = 1; i <= n; i++) {
        while(j && a[i] != b[j+1]) j = p[j]; 
        if(a[i] == b[j+1]) j++;
        f[i] = j;
        t[++top] = i;
        if(j == n1) {
            top -= n1;
            j = f[t[top]];
        }
    }
    for(int i = 1; i <= top; i++) {
        printf("%c",a[t[i]]);
    }
    return 0;
}
