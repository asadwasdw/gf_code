#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 110;
int ans[N][N];


int main()
{
    int n,m,c;

    cin>>n>>m>>c;

    if(n*m%c)
    {
        cout<<"impossible"<<endl;
        return 0;
    }
    int sum=n*m/c;
    //cout<<sum<<endl;
    int x=1,y=1;

    for(int i=1;i<=n;i++)
    {
        if(sum%i)continue;

        int j=sum/i;

        if(n%i==0&&m%j==0)
        {
            x=i,y=j;
            break;
        }
    }
    int cnt=0;

    //cout<<x<<" "<<y<<endl;

    for(int i=1;i<=n;i+=x)
    {
        for(int j=1;j<=m;j+=y)
        {
            for(int a=i;a<i+x;a++)
            {
                for(int b=j;b<j+y;b++)
                {
                    ans[a][b]=cnt;
                }
            }

            cnt++;
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<(char)(ans[i][j]+'A');
        }
        cout<<endl;
    }


}