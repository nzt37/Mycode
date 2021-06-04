#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 6;

int a[maxn];
int f[maxn];
int ans[maxn],cnt;
int find(int x) {
    return f[x] == 0 ? x : f[x] = find(f[x]);
}
int n;
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) f[i] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        int x = find(a[i]);
        f[x] = x + 1;
        ans[++cnt] = x;
    }
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i==n];
    }

}