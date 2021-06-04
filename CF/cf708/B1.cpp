#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <deque>
#include <queue>
#include <list>
#include <set>
#include <stack>
//#include <random>
#include <string>
#include <cmath>
#include <ctime>
#include <bitset>
#include <iostream>
//#include <unordered_map>

#define db long double
#define FOR(x,a,b) for(ll x=a;x<=b;x++)
#define _FOR(x,a,b) for(ll x=a;x>=b;x--)
#define RI(n) scanf("%lld",&n)
#define RLL(n) scanf("%lld",&n)
#define RLL2(a,b) scanf("%lld %lld",&a,&b)
#define RLL3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define RLL4(a,b,c,d) scanf("%lld %lld %lld %lld",&a,&b,&c,&d)
#define RLF(n) scanf("%lf",&n)
#define RLF2(a,b) scanf("%lf %lf",&a,&b);
#define RLF3(a,b,c) scanf("%lf %lf %lf",&a,&b,&c);
#define RS(n) scanf("%s",n)
#define PLL(n) printf("%lld",n)
#define PLN(n) printf("%lld\n",n)
#define PLN2(a,b) printf("%lld %lld\n",a,b)
#define PLN3(a,b,c) printf("%lld %lld %lld\n",a,b,c)
#define MM(a,x) memset(a,x,sizeof(a));
#define DE(x) cout<<x<<endl;
#define ll long long
#define eps 1e-5

const long long inf=1e18+10;
const int N=2e5 + 10;
const int M=1e9;
const ll mod=1e9+7;
using namespace std;
ll t;
ll a[N],b[N];
map<ll, ll> mp;
void solve() {
     ll n, m;
        cin >> n >> m;
        ll cnt = 0;
        ll ans = 0, fs = 1;
        mp.clear();
        FOR(i, 1, n){
            RLL(a[i]);
            if(a[i] % m == 0){
                if(fs) ans = 1;
                fs = 0;
                continue;
            }
            if(!mp[a[i] % m]) b[++ cnt] = a[i] % m;
            mp[a[i] % m] ++;
        }
        sort(a + 1 ,a + 1 + cnt);
        FOR(i, 1, cnt){
            ll sx = m - b[i];
            if(sx == b[i]){
                ans ++;
                mp[sx] = 0;
                continue;
            }
            if(mp[sx]){
                if(mp[sx] == mp[b[i]]){
                    mp[sx] = mp[b[i]] = 0;
                }else{
                    ll mi = min(mp[sx], mp[b[i]]);
                    mp[sx] -= mi; mp[b[i]] -= mi;
                    if(mp[sx]) mp[sx] --;
                    else mp[b[i]] --;
                }
                ans += mp[b[i]] + mp[sx] ;
                mp[sx] = mp[b[i]] = 0;
                ans ++;
            }else{
                ans += mp[b[i]];
                mp[b[i]] = 0;
            }
        }
        cout << ans << "\n";
}
int main(){
    cin >> t;
    while(t --){
       solve();
    }

    return 0;
}
