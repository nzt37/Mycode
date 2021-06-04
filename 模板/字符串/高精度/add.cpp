#include<iostream>
#include<vector>
using namespace std;

const int N = 100010;

vector<int> add(vector<int> &A,vector<int> &B)
{
    vector<int> C;
    int t=0;
    for(int i=0;i<A.size()||i<B.size();i++)
    {
        if(i<A.size()) t+=A[i];
        if(i<B.size()) t+=B[i];
        C.push_back(t%10);
        t/=10;
    }
    
    if(t) C.push_back(t);
    
    return C;
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    vector<int> A,B;
    for(int i=s1.size()-1;i>=0;i--) A.push_back(s1[i]-'0');
    for(int i=s2.size()-1;i>=0;i--) B.push_back(s2[i]-'0');
    auto C = add(A,B);
    for(int i=C.size()-1;i>=0;i--) cout<<C[i];
    cout<<endl;
    return 0;
}