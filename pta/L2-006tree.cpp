#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 6;
int post[maxn],in[maxn];
map<int,int> level;

void pre(int root, int start, int end, int index) {
    if(start > end) return ;
    int i = start;
    while(i < end && in[i] != post[root]) i++;
    level[index] = post[root];
    level[index] = post[root];
    pre(root - 1 - end + i, start, i - 1, 2 * index + 1);
    pre(root - 1, i + 1, end, 2 * index + 2);
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> post[i];
    }
    for(int j = 0; j < n; j++) {
        cin >> in[j];
    }
    pre(n-1, 0, n-1, 0);
    auto it = level.begin();
    printf("%d", it->second);
    while(++it != level.end()) printf(" %d", it->second);
    return 0;
}