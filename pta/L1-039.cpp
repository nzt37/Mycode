#include <iostream>
#include <set>
using namespace std;
int main() {
	int n;
	cin >> n;
	getchar();
	string s;
	getline(cin, s);
	if(s.length()%n != 0) {
		int t = n-s.length()%n;
		for(int i = 0; i < t; i++) {
			s = s+" ";
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = s.length()-1; j >= 0; j--) {
			if(j%n == i) {
				cout << s[j];
			}
		}
		cout << endl;
	}
} 