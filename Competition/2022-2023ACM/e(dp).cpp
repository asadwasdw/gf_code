#include<iostream>
#include<algorithm>

using namespace std;

const int N=1010;

bool st[N][N];

int main()
{
    st[0][0]=true;
    int n,k,e;
    cin>>n>>k>>e;

    int a=e;
    int b=k;
    int c=n-k-e;
    //cout<<a<<" "<<c<<endl;

    for(int len=1;len<=max(a,c);len++)
    {
       if(len==b)continue;
        for(int i=a;i>=0;i--)
        for(int j=c;j>=0;j--)
        {

            if(len<=i)st[i][j]|=st[i-len][j];
            if(len<=j)st[i][j]|=st[i][j-len];
        }
    }

    // for(int i=0;i<=2;i++){
    // for(int j=0;j<=2;j++)
    // {
    //     cout<<st[i][j]<<" ";
    // }
    // cout<<endl;
    // }

    int ans=0;

    for(int i=0;i<=a;i++)
    {
        for(int j=0;j<=c;j++)
        {
            if(st[i][j])ans=max(ans,i+j+b);
        }
    }

    cout<<n-ans<<endl;


}