#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn = 2e5 + 6;
int a[maxn], b[maxn],n;
bool check(int d)
{
    int sum = 0;
    int flag = 1;
    for(int i = 0; i < n && flag; i++){
        if(d < a[i]){
            sum += b[i];
        }
        if(sum > d) return false;
    }
    return true;
}
void solve()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    int l = 1, r = 1e9;
    int ans = 0;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)) {
            ans = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    cout << ans << endl;
}
int main() {
    int T;
    cin >> T;
    while(T--){
        solve();
    }

    return 0;
}
