#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=110;
struct matrix {
    int m[N][N];
};



matrix operator * (const matrix& a,const matrix& b){
    matrix c;
    memset(c.m,0,sizeof c.m);

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            for(int k=0;k<N;k++){
                c.m[i][j]=(c.m[i][j]+a.m[i][k]*b.m[k][j]);
            }
        }
    }
    return c;
}

matrix qmi(matrix a,int n)
{
    matrix ans;
    memset(ans.m,0,sizeof ans.m);

    for(int i=0;i<N;i++)
    {
        ans.m[i][i]=1;
    }

    while(n)
    {
        if(n&1)ans=ans*a;
        a=a*a;
        n>>=1;
    }
    return ans;
}


int main()
{
    int n;cin>>n;

    matrix a,b;
    memset(a.m,0,sizeof a.m);
    memset(b.m,0,sizeof b.m);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a.m[i][j];
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>b.m[i][j];
        }
    }
    a=a*b;


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
          cout<<a.m[i][j]<<" ";
        }
        cout<<endl;
    }
}