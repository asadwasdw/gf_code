#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;


void solve()
{
    long long a;
    cin>>a;
    if(a==1){
        cout<<"1"<<endl;
        return;
    }
    if(a==3){
        cout<<"2"<<endl;
        return ;
    }
    if(a<=3)
    {
        cout<<"-1"<<endl;
        return;
    }

    if(a==4)
    {
        cout<<a/2<<endl;
        return;
    }

    if(a==5){
        cout<<"3"<<endl;
        return;
    }

    long long ans=(a+1)/2;
    long long sy = a-ans;

    ans+=(sy/3);
    cout<<ans<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    int t;t=1;
 ///cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}