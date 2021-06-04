#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e4 + 6;
struct node{
    int num,val,m; 
} a[maxn];
bool cmp(node a,node b)
{
    if(a.val == b.val) return a.m > b.m;
    return a.val > b.val;
}
int main()
{   
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        int cnt = 0;
        for(int j = 1; j <= k; j++) {
            int c,p;
            cin >> c >> p;
            a[c].val += p;
            a[c].m++;
            cnt += p;
        }
        a[i].val -= cnt;
        a[i].num = i;
    }
    sort(a+1,a+1+n,cmp);
    for(int i = 1; i <= n; i++) {
        cout <<a[i].num << " "<< fixed << setprecision(2) << (double)(a[i].val*1.0/100) << endl;
    }
    return 0;
}