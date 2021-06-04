#include <bits/stdc++.h>

using namespace std;
const int maxn  =1e5 + 5;
int a[maxn];
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    int tmp1 = 0,tmp2 = 0;
    for(int i = 1; i <= n/2; i++) {
        tmp1 += a[i];
        tmp2 += a[i+n/2];
    }
    if(n & 1) {
        tmp2 += a[n];
    }
    printf("Outgoing #: %d\n",(n&1)?(n/2)+1 : n/2);
    printf("Introverted #: %d\n",n/2);
    printf("Diff = %d\n",tmp2-tmp1);
    return 0;
}
