#include <bits/stdc++.h>
using namespace std;

int n,m;
bool isprime(int n)
{
    if(n == 1 || n == 0) return false;
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) return false;
    }
    return true;
}
int main(){
    cin >> n;
    int cnt = 0;
    for(int i = 2; i <= n; i++) {
        if(isprime(i)) {
            cnt++;
        }
    }
    if(n < 4) {
        cout << -1 << endl;
    }
    else
    cout << cnt+2 << endl;
    return 0;
}