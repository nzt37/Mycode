#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int sum[11];
bool prime(int x)
{
    if(x == 1 || x == 0) return false;
    if(x == 2 || x == 3) return true;
    if(x%6 != 1 && x % 6 != 5) return false;
    for(int i = 5; i * i <= x; i += 6) {
        if(x%i == 0 || x % (i+2) == 0) return false; 
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    if(prime(n)) {
        cout << 1 << endl;
        cout << n << endl;
        return 0;
    }
    int ans = 0,l = 0,r = 0;
    for(int i = 2; i * i <= n; i++) {
        int j = i,tmp = n;
        while(tmp % j == 0) {
            tmp/=j;
            j++;
        }
        if(j - i > r - l) {
            l = i;
            r = j;
        }
    }
    cout << r-l << endl;
    for(int i = l; i < r-1; i++) {
        cout << i << '*';
    }
    cout << r-1;
    return 0;
}
