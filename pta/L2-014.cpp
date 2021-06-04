#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    set<int > q;
    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        if(q.empty()) q.insert(a);
        else {
            if(q.lower_bound(a) != q.end()) {
                q.erase(q.lower_bound(a));
                q.insert(a);
            }
            else {
                q.insert(a);
            }
        }

    }
    cout << q.size() << endl;
    return 0;
}