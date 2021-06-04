#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 10;
int n, w, pfx[maxn];
void solve(){
    int n,w;
    cin >> n >> w;
    for(int i=0;i<n;++i){
        int s,t,p;
        cin >> s >> t >> p;
        pfx[s]+=p;
        pfx[t]-=p;
    }
    for(int i=0;i<maxn;++i){
        if(i>0) pfx[i]+=pfx[i-1];
        if(pfx[i]>w){
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}
int main()
{
    int n,w;
    cin >> n >> w;
    for(int i=0;i<n;++i){
        int s,t,p;
        cin >> s >> t >> p;
        pfx[s]+=p;
        pfx[t]-=p;
    }
    for(int i=0;i<maxn;++i){
        if(i>0) pfx[i]+=pfx[i-1];
        if(pfx[i]>w){
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}
