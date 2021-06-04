#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn = 5050;
int nums1[26],nums2[26];
string s1, s2;
int T, n, k;
void solve()
{
    cin >> n >> k;
    cin >> s1 >> s2;
    int nums1[26] = { 0 }, nums2[26] = { 0 };
    for (int i = 0; i < n; i++) {
        nums1[s1[i] - 'a']++;
        nums2[s2[i] - 'a']++;
    }
    int flag = 1;
    for (int i = 0; i < 25; i++) {
        while (nums1[i] - k >= nums2[i]) {
            nums1[i] -= k;
            nums1[i + 1] += k;
        }
        if (nums1[i] != nums2[i]) {
            flag = 0;
            break;
        }
    }
    if (nums1[25] != nums2[25])
    flag = 0;
    if (flag == 1)
    cout << "YES" << endl;
    else 
    cout << "NO" << endl;
}
int main() {


	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}