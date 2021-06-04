#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
inline int read() {
    int x = 0, neg = 1; char op = getchar();
    while (!isdigit(op)) { if (op == '-') neg = -1; op = getchar(); }
    while (isdigit(op)) { x = 10 * x + op - '0'; op = getchar(); }
    return neg * x;
}
inline void print(int x) {
    if (x < 0) { putchar('-'); x = -x; }
    if (x >= 10) print(x / 10);
    putchar(x % 10 + '0');
}
const int maxn = 120;
int a[1000008];

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int sum = n * k;
        for (int i = 1; i <= sum; ++i) {
            cin >> a[i];
        }
        sort(a + 1, a + 1 + sum);
        long long ans = 0;
        int temp = n / 2;
        for (int i = sum - temp, j = k; j > 0; i -= temp, --j) {
            ans += a[i];
            --i;
        }
        cout << ans << endl;
    }
    return 0;
}
