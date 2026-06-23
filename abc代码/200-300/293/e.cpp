#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define int long long
const int N=11;
struct matrix {
    int m[N][N];
};


int a,b,MOD;
matrix operator * (const matrix& a,const matrix& b){
    matrix c;
    memset(c.m,0,sizeof c.m);

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            for(int k=0;k<N;k++){
                c.m[i][j]=(c.m[i][j]+a.m[i][k]*b.m[k][j])%MOD;
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


signed main()
{
    cin>>a>>b>>MOD;

    matrix t;
    memset(t.m,0,sizeof t.m);
    t.m[0][0]=a;
    t.m[0][1]=1;
    t.m[1][0]=0;
    t.m[1][1]=1;

    t=qmi(t,b);
   //cout<<t.m[0][1]<<endl;
    matrix ans;
    memset(ans.m,0,sizeof ans.m);
    ans.m[0][0]=0;
    ans.m[1][0]=1;

    ans=t*ans;

    cout<<ans.m[0][0]<<endl;
    
}