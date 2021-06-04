#include <bits/stdc++.h>
using namespace std;

int n,m;

void solve()
{
    deque<int> q;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> m;
        q.push_back(m);
    }
    int cnt = 0;
    while(!q.empty()) {
        if(cnt >= n ) break;
        cout << q.front() << " ";
        q.pop_front();
        cnt++;
        if(cnt >= n ) break;
        cout << q.back() << " ";
        q.pop_back();     
        cnt++;
        if(cnt >= n ) break;
        
    }
    cout << endl;
    
}
int main(){
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}