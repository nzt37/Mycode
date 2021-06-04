#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn = 1e7;;
bool isprime[maxn];
int prime[maxn],a[110][110],cnt;
void get_prime(int n)
{
    memset(isprime, 1, sizeof(isprime));
    isprime[1] = 0;
    for(int i=2 ; i<=n ; i++)
    {
        if(isprime[i])
        {
            prime[++cnt] = i;
        }
        for(int j=1 ; j<=cnt && i*prime[j]<=n ; j++)
        {
            isprime[i*prime[j]] = 0;
            if(i%prime[j] == 0)
                break;
        }
    }
}

void solve(){
    int n;
    cin >> n;
    int b;
    int c = 101;
    get_prime(1100000);
    //if(n == 1){
    //b = 1;
    //}
    //else if (n == 2) b = 2;
    //else if ( n == 3 ) b = 3;
    //else{
    while(isprime[prime[c]-4*(n-1)] == true){
        c++;
    }
    b = prime[c] - 4*(n-1);
    //} 
    //cout << c << "dsd" <<  prime[c] << "f" << endl;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            cout << (i == j ? b : 4) << " ";
        }
        cout << endl;


    }
}

int main() {
    int T;
    cin >> T;
    while(T--){
        solve();
    }

    return 0;
}
