#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn = 1e5+6;
int a[maxn];
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if(n&1) {
        int cnt = 0;
        cout << "YES" << endl;

        for(int i = 1; i <= n-3; i+=2) {
            cnt++;
        }
        for(int i = 1; i <= n-2; i+=2) {
            cnt++;
        }
        cout << cnt << endl;
        for(int i = 1; i <= n-2; i+=2) {
            cout <<  i << " " << i+1 << " " << i+2 << endl;

        }
        for(int i = 1; i < n-2; i+=2) {
            cout << i << " " << i+1 << " " << n << endl; 
        }
    }
    else {
        int cnt = 0;
        for(int i = 1; i <= n-3; i+=2) {
            cnt++;
            int val = a[i]^a[i+1]^a[i+2];
            a[i] = a[i+1] = a[i+2] = val;
        }
        if(a[n] == a[n-1]) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
            return 0;
        }
        for(int i = 1; i < n-3; i+=2) {
            cnt++;
        }
        cout << cnt << endl;
        for(int i = 1; i <= n-3; i+=2) {
            cout <<  i << " " << i+1 << " " << i+2 << endl;

        }
        for(int i = 1; i < n-3; i+=2) {
            cout << i << " " << i+1 << " " << n << endl; 
        }
    }

    return 0;
}
