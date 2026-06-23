#include<iostream>
#include<algorithm>

using namespace std;

const int N = 2e5+10;

int a[N],b[N];

int num[5][5];

int main()
{

    int n;cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }

    sort(b+1,b+n+1);

    int ans=0;

    for(int i=1;i<=n;i++)
    {
        num[a[i]][b[i]]++;
    }

    for(int i=1;i<=4;i++)
    {
        ans+=num[i][i];
        num[i][i]=0;
    }

    for(int i=1;i<=4;i++)
    {
        for(int j=1+i;j<=4;j++)
        {
            int t=min(num[i][j],num[j][i]);

            ans+=t;

            num[i][j]-=t;
            num[j][i]-=t;
        }
    }


    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=4;j++)
        {
            for(int k=1;k<=4;k++)
            {
                int t=min(num[i][j],min(num[j][k],num[k][i]));

                ans+=t;

                num[i][j]-=t;
                num[j][k]-=t;
                num[k][i]-=t;
            }
        }
    }

    int cnt=0;
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=4;j++)
        {
            cnt+=num[i][j];
        }
    }
    ans+=cnt/4;
    ans=n-ans;
    cout<<ans<<endl;

}