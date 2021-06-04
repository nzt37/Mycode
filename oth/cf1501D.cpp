#include<bits/stdc++.h>
#define int long long
#define PI pair<int,int>
using namespace std;
const int maxm=1e5+5;
PI pre[maxm][10];
double d[maxm][10];
int a[maxm];
double v[maxm];
int n,dig;
void solve(){
    cin>>n>>dig;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        v[i]=log(a[i]);
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<10;j++){
            d[i][j]=-1e9;
        }
    }
    d[0][1]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<10;j++){
            if(d[i][j]<0)continue;
            if(d[i][j]>d[i+1][j]){
                d[i+1][j]=d[i][j];
                pre[i+1][j]={j,0};//0表示没选
            }
            if(d[i][j] + v[i+1] > d[i+1][j * (a[i+1]) % 10]){
               d[i+1][j * (a[i+1]) % 10]  = d[i][j] + v[i+1] ;
                pre[i+1][a[i+1]*j%10]={j,1};//1表示选了
            }
        }
    }
    if(d[n][dig]<=0){
        cout<<-1<<endl;
    }else{
        vector<int>ans;
        int x=dig;
        for(int i=n;i>=1;i--){
            PI pre1=pre[i][x];
            x=pre1.first;
            if(pre1.second)ans.push_back(a[i]);
        }
        reverse(ans.begin(),ans.end());
        cout<<ans.size()<<endl;
        for(auto i:ans){
            cout<<i<<' ';
        }
        cout<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}
