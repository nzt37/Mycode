#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int vis[20001];
bool isprime(int n)
{
    if(n == 1 || n == 0) return false;
    for(int i = 2; i <= sqrt(n); i++){
        if(n%i == 0) return false;
    }
    return true;
}
int x,f[200011],ans[200011];
void dfs(int a,int x, int num)
{
    if(a == 1){
        ans[x] = num;
        return ;
    }
    if(vis[a]) return;
    vis[a] = 1;
    int m = a, ans = 0;
    while(m){
        ans += pow(m%10,2);
        m/=10;
    }
    f[a]++;
    //cout << ans << " "<< num << endl;
    dfs(ans,x,num+1);

}

int main() {
    int a,b;
    cin >> a >> b;
    int flag = 0;
    for(int i = a; i <= b; i++){
        memset(vis,0,sizeof(vis));
        dfs(i,i,0);
    }
    for(int i = a; i <= b; i++){
        if(ans[i] > 0 && f[i] == 1){
            flag = 1;
            if(isprime(i)){
                cout << i << " " << 2*ans[i] << endl;
            }
            else{
                cout << i << " " << ans[i] << endl;
            }
        }

    }
    if(!flag){
        cout << "SAD" << endl;
    }
    return 0;
}
