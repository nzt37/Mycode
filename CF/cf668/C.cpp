#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn = 1010;
int c[maxn][maxn],z[maxn][maxn],C[maxn][maxn];
const int mod = 1e9 + 7;
void zuhe(int n)
{
    for(int i=1; i<=2*n; i++) c[i][1]=c[i][i]=1;
    for(int i=3; i<=2*n; i++){
        for(int j=2; j<i; j++)
            c[i][j] = (c[i-1][j] + c[i-1][j-1] % mod)%mod; 
    }

}
void yhsj(int n)
{
    for (int i = 0; i <= n; ++i){
        z[i][0] = z[i][i] = 1;//杨辉三角形侧边初始值
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; j++) {
            z[i][j] = z[i - 1][j] + z[i - 1][j - 1];
        }
    }
}

void Initial(int n) 
{ 
    int i,j; 
    for(i=0; i<=n; ++i) 
    { 
        C[0][i] = 0; 
        C[i][0] = 1; 
    } 
    for(i=1; i<=n; ++i) 
    { 
        for(j=1; j<=n; ++j) 
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod; 
    } 
} 
int fac(int x)
{
    if(x == 0){
        return 1;
    }
    return x % mod*fac(x-1)% mod;
}
int main() {

    int n,x,pos;
    cin >> n >> x >> pos;
    zuhe(n);
    yhsj(n);
    Initial(n);
    // for(int i = 1 ; i <= n ; i++){
    //     for(int j = 1 ; j <= n ; j++){
    //         cout << C[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << C[n][n-2] << endl;
    return 0;
}
