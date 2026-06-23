//https://vjudge.net/problem/HDU-1704


#include<iostream>
#include<algorithm>
#include<cstring>
#include<bitset>
using namespace std;

const int N=510;

bitset<N> st[N];

void solve()
{
 //   memset(st,0,sizeof st);
    int a,b;
    cin>>a>>b;

    //for(int i=1;i<=a;i++)st[i][i]=1;

    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=a;j++)
        {
            st[i][j]=(i==j);
        }
    }


    for(int i=1;i<=b;i++)
    {
        int x,y;
        cin>>x>>y;
        st[x][y]=1;
    }

    for(int k=1;k<=a;k++)
    {
        for(int i=1;i<=a;i++)
        if(st[i][k])
            st[i]|=st[k];
    }
    int ans=0;
    for(int i=1;i<=a;i++)
    {
        for(int j=i+1;j<=a;j++)
        {
            if((st[i][j]==0)&&(st[j][i]==0))
            {
               // cout<<i<<" "<<j<<endl;
                ans++;
            }
        }
    }
    cout<<ans<<endl;


}

int main()
{
    int t;cin>>t;while(t--)
    solve();
    
}