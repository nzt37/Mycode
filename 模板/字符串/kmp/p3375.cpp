#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn = 1e7 + 7;
char a[maxn],b[maxn];
int p[maxn];
int main() {
    cin >> a+1;
    cin >> b+1;
    int la = strlen(a+1);
    int lb = strlen(b+1);
    int j = 0;
    p[1] = 0;
    for(int i = 2; i <= lb; i++) {
        while(j > 0 && b[i] != b[j+1]) j = p[j];
        if(b[i] == b[j+1]) j++;
        p[i] = j;
    }
    j = 0;
    for(int i = 1; i <= la; i++){
        while(j > 0 && a[i] != b[j+1]) j = p[j];
        if(a[i] == b[j+1]) j++;
        if(j == lb){
            printf("%d\n",i-lb+1);
            j = p[j];
        }
    }
    //printf("\n");
    for(int i = 1; i <= lb ; i++){
        printf("%d ",p[i]);
    }
    return 0;
}
