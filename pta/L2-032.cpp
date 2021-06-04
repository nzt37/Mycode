#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int a[10001];
int n,m,k;
stack<int> q;
void solve()
{
    for(int i = 1; i <= n; i++) cin >> a[i];
    int cnt = 1;
    while(!q.empty()) q.pop();
    for(int i = 1; i <= n; i++){
        if(a[i] == cnt){
            cnt++;
            while(!q.empty() && q.top() == cnt){
                cnt++;
                q.pop();
            }
        }else{
            q.push(a[i]);
        }
        if(q.size() > m){
            cout << "NO" << endl;
            return;
        }
    }
    if(q.size()){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
}
int main() {
    cin >> n >> m >> k;
    while(k--){
        solve();
    }

    return 0;
}
