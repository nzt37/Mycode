#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define me memset
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
using namespace std;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s1,s2,s3;
        cin>>s1>>s2>>s3;
        int len1=s1.length();
        int len2=s2.length();
        int len3=s3.length();
        int p1=0,p2=0,p3=0;
        string ans;
        while(p1<n*2&&p2<n*2&&p3<n*2)
        {
            if(s1[p1]==s2[p2])
            {
                ans+=s1[p1];
                p1++;
                p2++;
            }
            else if(s1[p1]==s3[p3])
            {
                ans+=s1[p1];
                p1++;
                p3++;
            }
            else
            {
                ans+=s2[p2];
                p2++;
                p3++;
            }
        }
       cout << ans << " cas\n";
        if(p1>=2*n)
        {
            if(p2>=p3) ans+=s2.substr(p2);
            else ans+=s3.substr(p3);
        }
        else if(p2>=2*n)
        {
            if(p1>=p3) ans+=s1.substr(p1);
            else ans+=s3.substr(p3);
        }
        else
        {
            if(p1>=p2) ans+=s1.substr(p1);
            else ans+=s2.substr(p2);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
