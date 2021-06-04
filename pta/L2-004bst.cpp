#include <bits/stdc++.h>

using namespace std;
const int maxn = 1010;
int a[maxn];
bool flag;
vector <int > p;
void dfs(int root,int tail)                
{
    if(root > tail) return;
    int i = root + 1;
    
    int j = tail;     
    if(!flag) {
        while(i <= tail && a[root] > a[i]) i++;
        while(j  > root && a[root] <= a[j]) j--;
    } else {
        while(i <= tail && a[root] <= a[i]) i++;
        while(j  > root && a[root] > a[j]) j--;
    }
    if(i - j != 1) return;
    // cout << root + 1 << " " << j << "\n";
    dfs(root+1,j);
    dfs(i,tail);
    p.push_back(a[root]);
}
int main() 
{   
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(1,n);
    if(p.size() != n) {
        flag = 1;
        p.clear();
        dfs(1,n);
    }
    if(p.size() == n) {
        cout << "YES" << endl;
        for(int i = 0; i < (int)p.size() - 1; i++) {
            cout << p[i] << " " ;
            
        }
        cout << p[n-1];
    }else {
        cout << "NO" << endl;
    }
    return 0;
}