#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N =  5e4+100;

char A[N],B[N];
int a[N],b[N],ans[N];

int main()
{
    cin>>A>>B;
    
    a[0] = strlen(A), b[0] = strlen(B);
    
    //注意下标从1开始
    for(int i = 1; i<=a[0]; i++) a[i] = A[a[0]-i]-'0';
    for(int j = 1; j<=b[0]; j++) b[j] = B[b[0]-j]-'0';
    
    //对应b[j] 与 a 的每一位相乘
    for(int i = 1; i<=a[0]; i++)
        for(int j = 1; j<=b[0]; j++)
            ans[i+j-1] += a[i] * b[j];
            
    //模拟进位
    for(int i = 1; i<a[0]+b[0]; i++)
        if(ans[i]>9) 
        {
            ans[i+1] += ans[i] / 10;
            ans[i] %= 10;
        }
    
    int len = a[0] + b[0];
    while(ans[len]==0 && len>1) len --;
    
    //从最高位到最低位进行输出
    for(int i = len; i>=1; i--) cout<<ans[i];
    cout<<endl;
    
    return 0;
}