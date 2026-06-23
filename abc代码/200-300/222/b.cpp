#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n;cin>>n;
    int m;cin>>m;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        if(x<m)ans++;
    }

    cout<<ans<<endl;

}