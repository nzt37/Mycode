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
#define BR printf("--------------------\n")
#define debug(x) std::cerr << #x << '=' << x << '\n'
#define y1 yzang
using namespace std;

const int maxn = 2e5 + 10;
const int mod= 1e9 + 7;
int n,m;
int a[maxn];
multiset<int> se[maxn];
map<int,int> f[maxn];
int prime[maxn];
int ismp[maxn];
int pre[maxn];
int cnt = 0;
ll qpow(ll a, ll b) {
  ll ans = 1;
  while(b) {
    if(b & 1) ans = ans * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return ans;
}
ll pow_mod(ll x,ll n,ll mod)
{
  ll res = 1;
  while(n)
  {
    if(n & 1) res = res * x % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return res;
}
int minprime[maxn];
void Prime(int x) {
  for(int i = 2; i <= x; i++) {
    if(!ismp[i]) prime[++cnt] = i,ismp[i] = i;
    for(int j = 1; j <= cnt && i * prime[j] <= x; j ++) {
      ismp[i*prime[j]] = prime[j];
      if(i % prime[j] == 0) break;
    }
  }
}
int main() {
    ios::sync_with_stdio(false);
  cin.tie(0),cout.tie(0);
  
  
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  Prime(200000);
  for(int i = 1; i <= n; i++) {
    for(int j = 2; j * j <= a[i]; j++) {
      if(a[i] % j == 0) {
        int c = 0;
        while(a[i] % j == 0) {
          c++;
          a[i] /= j;
        }
        f[i][j] = c;
        se[j].insert(c);
      // cout << c << "cxac\n";
      }
      if(a[i] > 1) {
        f[i][a[i]] = 1;
        se[a[i]].insert(1);
      }
    }
  }
  ll g = 1;
  for(int i = 1; i <= cnt; i++) {
    int x = prime[i];
    if(se[x].size() == n) {
      auto j = *se[x].begin();
      g = g * qpow(1ll*x,1ll*j) % mod;
      pre[x] = j; 
    }
  }
  // for(int i = 1; i <= n; i++)
  // {
  //   cout << p[i] << "cas\n";
  // } 
  // cout << cnt << "\n";
 while(m --)
  {
    int I,X;
    cin >> I >> X;
    cout << I << "cxasc\n";
    for(int j = 1 ; prime[j] * prime[j] <= X && j <= cnt ; j ++) if(X % prime[j] == 0)
    {
      int c = 0 , p = prime[j];

      while(X % p == 0) X /= p , c ++ ;

      if(f[I].count(p))
      {
        auto it = se[p].find(f[I][p]);

        se[p].erase(it);
      }

      f[I][p] += c;
  
      se[p].insert(f[I][p]);

      if(se[p].size() == n)
      {
        auto it = *se[p].begin();

        g = g * pow_mod(p , it - pre[p] , mod) % mod;

        pre[p] = it;
      }
    }
    if(X > 1)
    {
      if(f[I].count(X))
      {
        auto it = se[X].find(f[I][X]);
        
        se[X].erase(it);
      }
      
      f[I][X] += 1;
      
      se[X].insert(f[I][X]);
      
      if(se[X].size() == n)
      {
        auto it = *se[X].begin();

        g = g * pow_mod(X , it - pre[X] , mod) % mod;

        pre[X] = it;

      }
    }
    cout << g << '\n';
  }
  return 0;
}