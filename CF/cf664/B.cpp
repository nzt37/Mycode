#include<bits/stdc++.h>
using namespace std;
int a[101][101];
int main(){
    int n,m;
    cin>>n>>m;
    int x1,y1;
    cin>>x1>>y1;
    cout << endl;
    for(int i=1;i<=n;i++)
    {
        if(i%2){
            for(int j=1;j<=m;j++)
                cout<<(i+x1-2)%n+1<<" "<<(j+y1-2)%m+1<<endl;
        }
        else{
            for(int j=m;j>=1;j--){
                cout<<(i+x1-2)%n+1<<" "<<(j+y1-2)%m+1<<endl;
            }
        }	
    }
    return 0; 
}
