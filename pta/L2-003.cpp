#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn = 1e5+6;
int a[maxn],c[maxn],b[maxn];
struct node{
    double num,w;
    double val;

}k[maxn];
bool cmp(node a,node b)
{
    return a.val > b.val;
}
int main() {
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> k[i].num;
    }
    for(int i = 1; i <= n; i++){
        cin >> k[i].w;
        k[i].val = (double)(k[i].w/k[i].num);
    }
    sort(k+1,k+1+n,cmp);
    double sum = 0,d = 0;
    for(int i = 1; i <= n; i++){
        if(d + k[i].num <= m){
            sum += k[i].w;
            d += k[i].num;
        }
        else{
            sum += k[i].val*(m-d);
            d = m;
        }
    }
    printf("%.2f\n",sum);
    return 0;
}
