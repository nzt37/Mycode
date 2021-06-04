#include <bits/stdc++.h>
#define MAX 1005
#define ll long long
using namespace std;

template<typename T>
void read(T &n){
    n = 0;
    T f = 1;
    char c = getchar();
    while(!isdigit(c) && c != '-') c = getchar();
    if(c == '-') f = -1, c = getchar();
    while(isdigit(c)) n = n*10+c-'0', c = getchar();
    n *= f;
}
template<typename T>
void write(T n){
    if(n < 0) putchar('-'), n = -n;
    if(n > 9) write(n/10);
    putchar(n%10+'0');
}

ll a, b, c;

long double calc(int x){
    return 1.0*((x+1)*a+x*b)/(2*x+1);
}

int main()
{
    int T;
    cin >> T;
    while(T--){
        scanf("%lld%lld%lld", &a, &b, &c);

        if(c == a) puts("1");
        else if(c*2 <= a+b) puts("2");
        else{
            ll x = floor(1.0*(c-a)/(a+b-2*c));
            long double ans1 = calc(x), ans2 = calc(x+1);
            ll x1 = ((x+1)*a+x*b-c*(2*x+1))*(2*x+3), x2 = (-(x+2)*a-(x+1)*b+(2*x+3)*c)*(2*x+1);
            if(x1 <= x2){
                printf("%d\n", 2*x+1);
            }
            else printf("%d\n", 2*x+3);
        }
    }

    return 0;
}