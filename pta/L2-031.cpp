#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
vector<int > v[100001];
int f[200001],vis[200001],ans[200001];
void bfs(int x)
{
    queue<int >q;
    q.push(x);
    ans[x] = 1;
    while(1){
        int m = q.front();
        q.pop();
        //if(vis[m]) continue;
        //vis[m] = 1;
        for(int i = 0 ; i < v[m].size(); i++){
            //ans[v[m][i]] = ans[m] + 1;
            q.push(v[m][i]);
        }
        if(q.empty()){
            printf("%d",m);
            break;
        }
    }

}
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        for(int j = 1; j <= a; j++){
            int b;
            cin >> b;
            v[i].push_back(b);
            f[b]++;
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(f[i] == 0){
            bfs(i);
            break;
        }
    }


    return 0;
}
