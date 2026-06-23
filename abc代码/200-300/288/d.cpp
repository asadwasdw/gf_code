#include<iostream>
#include<algorithm>

using namespace std;

const int N=2e5+10,K=15;

int sum[N][K];
int a[N];

int main()
{
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
         cin>>a[i];
         for(int j=0;j<k;j++)
         {
            sum[i][j]=sum[i-1][j];
         }

         sum[i][i%k]+=a[i]-a[i-1];
         
         
    }


    int q;cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        int b[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

        for(int i=0;i<k;i++)
        {
            b[i]=sum[r][i]-sum[l-1][i];
            cout<<b[i]<<" ";
        }

        int flag=1;

        for(int i=1;i<k;i++){
            if(b[i]!=b[0])flag=0;
        }
        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
   
}