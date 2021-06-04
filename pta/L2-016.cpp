#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 4;
struct node{
    int f,m, sex;
    bool flag;
}a[maxn];
void f1(int x)
{
    if(a[x].f != -1) {
        a[a[x].f].flag = 1;
        f1(a[x].f);
    }
    if(a[x].m != -1) {
        a[a[x].m].flag = 1;
        f1(a[x].m);
    }
}
int ans,flag;
void f2(int x,int sum)
{
    int f = a[x].f;
    int m = a[x].m;
    if(a[x].flag == 1 && flag == 0) {
        ans = sum;
        flag = 1;
    }
    if(a[x].f != -1) {
        f2(f,sum + 1);
    }
    if(a[x].m != -1) {
        f2(m,sum + 1);
    }
}
void init()
{
    for(int i=0; i<100010; i++)
    {
        a[i].f=-1;
        a[i].m=-1;
    }
}
int main()
{
    int n,k;
    cin >> n;
    int id,f,m;
    char ch;
    init();
    for(int i = 1; i <= n ;i++) {
        cin >> id >> ch >> f >> m;
        a[id].f = f;
        a[id].m = m;
        if(ch == 'M') {
            a[id].sex = 1;
        }else {
            a[id].sex = 2;
        }
        a[f].sex = 1;
        a[m].sex = 2;
    }
    cin >> k;
    while(k--) {
        int l,r;
        cin >> l >> r;
        if(a[l].sex == a[r].sex) {
            cout << "Necer mind" << endl;
            continue;
        }
        for(int i = 0; i <= 100010; i++) {
            a[i].flag = 0;
        }
        f1(l);
        flag = 0;
        ans = -1;
        f2(r,0);
        if(ans >= 5 || ans == -1 ) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    return 0;
}
