#include <bits/stdc++.h>

using namespace std;
int f(string s)
{
    int n = s.size();
    int sum = 0;
    for(int i = 0 ;i <  n; i++) {
        if(isdigit(s[i])) {
            sum *= 10;
            sum += s[i]-'0';
        }
        else{
            return 1001;
        }
    }
    if(sum <= 1000 && sum >= 1)return sum;
    else {
        return 1001;
    }
}
int main()
{
    string s1,s2;
    cin >> s1;
    cin.ignore();
    getline(cin,s2);
    int n = f(s1);
    int m = f(s2);
    if( n != 1001 && m != 1001 ) {
        printf("%d + %d = %d\n",n,m,n+m);
    }
    else if(n == 1001 && m == 1001) {
        printf("? + ? = ?\n");
    }
    else if(n == 1001 && m != 1001) {
        printf("? + %d = ?\n",m);
    }
    else if(n != 1001 && m == 1001){
        printf("%d + ? = \n",n);
    }
    
    return 0;
}