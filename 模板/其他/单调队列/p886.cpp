#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn = 1e6 + 8;
struct node{
    int num,val;
};
deque<node > q;
deque<node > p;
int an[maxn],cnt,ans[2][maxn],num;
int main() {
    int n,k;
    cin >> n >> k;
    for(int i = 1; i <= n ;i++) {
        int a;
        scanf("%d", &a);
        node m;
        m.val = a;
        m.num = i;
        while(!q.empty() && a >= q.back().val) q.pop_back();
        while(!p.empty() && a <= p.back().val) p.pop_back();
        q.push_back(m);
        p.push_back(m);
        while(i-k >= q.front().num) q.pop_front();
        while(i-k >= p.front().num) p.pop_front();
        if(i >= k) {
            ans[0][++num] = p.front().val;
            ans[1][num] = q.front().val;
        }

    }
    for(int i = 1; i <= num; i++) {
        cout << ans[0][i] << " ";
    }
    cout << endl;
    for(int i = 1; i <= num; i++) {
        cout << ans[1][i] << " ";
    }
    return 0;
}