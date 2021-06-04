#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;


int main() {
    int n;
    cin >> n;
    int a, b, c, d;
    //cin >> a >> b;
    scanf("%d/%d",&a,&b);
    while(~scanf("%d/%d",&c,&d)){
        //cin >> c >> d;
        int m = __gcd(b,d);
        a *= d/m;
        c *= b/m;
        a += c;
        b *= d/m;
        m = __gcd(a,b);
        a /= m;
        b /= m;
    }
    if( b < 0 )
    {
        a = -a;
        b = -b;
    }
    if(b == 1) printf("%d\n",a);
    else if(abs(a) > abs(b)){
        if(a % b == 0)
            printf("%d ",a / b);
        else{
            int m = a / b;
            printf("%d %d/%d\n",m,a-b*m,b);

        }

    }
    else
        printf("%d/%d\n",a,b);
    return 0;
}
