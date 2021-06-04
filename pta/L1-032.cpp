#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    int n;
    cin >> n;
    char ch;
    cin >> ch;
    getchar();
    getline(cin,s);
    int m = s.size();
    if( m >= n) {
        for(int i = m - n; i < m; i++) {
            cout << s[i];
        }
    }
    else {
        for(int i = 1; i <= n - m; i++) {
            cout << ch;
        }
        cout << s;
    }

    return 0;
}