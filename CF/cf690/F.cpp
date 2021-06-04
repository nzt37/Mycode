#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5  + 5;
int n,m;
struct node{
    int l,r;
}a[maxn];
void solve()
{
    cin >> n;
    vector<int > p1;
    vector<int > p2;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].l >> a[i].r;
        p1.push_back(a[i].l);
        p2.push_back(a[i].r);
    }
    sort(p1.begin(),p1.end());
    sort(p2.begin(),p2.end());
    int ans = INT_MAX;
    for(int i = 1; i <= n; i++) {
        int num1 = lower_bound(p2.begin(),p2.end(),a[i].l) - p2.begin();
        int num2 = max(0,n - (int)(upper_bound(p1.begin(),p1.end(),a[i].r) - p1.begin()));
        ans = min(ans,num1+num2);
    }
    cout << ans << endl;

}
int main(){
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}