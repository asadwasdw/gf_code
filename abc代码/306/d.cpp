#include<iostream>
#include<algorithm>

using namespace  std;;

#define int long long

const int N = 1e6+10;

int f[N][5];
// 0 跳过
// 1 健康
// 2 G
signed main()
{

    int n;cin>>n;

    for(int i=1;i<=n;i++)
    {
        int x,w;
        cin>>x>>w;
        if(x==1)
        {
            f[i][2]=max(f[i-1][2],f[i-1][1]+w);
            f[i][1]=f[i-1][1];
        }
        else 
        {
            f[i][2]=f[i-1][2];
            f[i][1]=max(f[i-1][1]+w,f[i-1][2]+w);
            f[i][1]=max(f[i][1],f[i-1][1]);
        }
    }


    //for(int i=1;i<=n;i++)cout<<f[i][1]<<" "<<f[i][2]<<endl;

    cout<<max(f[n][1],f[n][2])<<endl;

}