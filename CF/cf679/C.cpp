#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn = 1e5+5;
const int inf=0x7fffffff;
struct node{
    int val, id;
    friend bool operator<(node a, node b){
        return a.val < b.val;
    }
};
int a[7],b[maxn],vis[maxn];
vector<node > v;
int main() {
    for(int i = 1 ; i <= 6 ; i++){
        cin >> a[i];
    }
    //    sort(a+1, a+1+6);
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> b[i];
        for(int j = 1 ; j <= 6 ; j++){
            v.push_back({b[i]-a[j], i});
        }
    }
    sort(v.begin(),v.end());
    int ans = inf;
    int cnt = 0;
    for(int i = 0, j = 0 ; i < 6*n ; i++){//i为右端点,j为左端点
        if(vis[v[i].id] == 0){
            cnt++;
        }
        vis[v[i].id]++;
        while(cnt == n){
            ans = min(ans,v[i].val - v[j].val);
            vis[v[j].id]--;
            if(vis[v[j].id] == 0) cnt--;
            j++;//左端点推进

        }
    }
    cout << ans << endl;
    return 0;
}
