#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define mid ((r+l)>>1)
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug cout << "dsdsdsdsd" << "\n";
#define y1 yzang
using namespace std;

const int maxn = 2e5 + 10;
int n,m;
string s[17];
int a[17][17];
int b[17][17];
int ans[17][17],is[17][17],cnt_1,cnt_2 = 1e4;
void work(int n,int m) {
	b[n][m] ^= 1;
	b[n][m+1] ^= 1;
	b[n+1][m] ^= 1;
	b[n][m-1] ^= 1;
	b[n-1][m] ^= 1;
    b[n+1][m+1] ^= 1;
    b[n-1][m+1] ^= 1;
    b[n+1][m-1] ^= 1;
    b[n-1][m-1] ^= 1;
}
void solve() {
    n = 5,m = 5;
    int flag = 1;
    CLR(is,0);
    CLR(ans,0);
    CLR(a,0);
    CLR(b,0);
    cnt_2 = 1e4;
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < m; j++) {
            a[i][j+1] = s[i][j]-'0';
            a[i][j+1] ^= 1;
        }
    }
    for(int k = 0; k <= (1 << m); k++) {
        flag = 1;
        cnt_1 = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                b[i][j] = a[i][j];
                ans[i][j] = 0;
            }
        }
        for(int i = 1; i <= m; i++) {
            if(k & (1<<(m-i))) {
                cnt_1++;
                ans[1][i] = 1;
                work(1,i);
            }
        }
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(b[i-1][j]) {
                    cnt_1++;
                    ans[i][j] = 1;
                    work(i,j);
                }
            }
        }
        for(int i = 1; i <= m; i++) {
            if(b[n][i]) {
                flag = 0;
            }
        }
        if(flag) {
            if(cnt_1 < cnt_2) {
                for(int i = 1; i <= n; i++ ) {
                for(int j = 1; j <= m; j++) {
                        is[i][j] = ans[i][j];
                    }
                }
                cnt_2 = cnt_1;
            }
        }
    }
    int tot = 0;
    if(cnt_2 == 1e4) {
        cout << "impossible,pa qu kao yan" << "\n";
        return;
    }
    else {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(is[i][j]) tot++;
            }
        }
    }
    cout << tot << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}