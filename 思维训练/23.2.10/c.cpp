#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;

ll p[20];
void jsp()
{
    ll sum=1;
    for(ll i=1;i<=16;i++)
    {
        sum*=i;
        p[i]=sum;
    }
}

int js(ll x)
{
    if(x<0)return 9999999;
    int num=0;
    while(x)
    {
        if(x&1){
            num++;
        }
        x>>=1;
    }
    return num;
}


void solve()
{


    ll n;cin>>n;

    int ans=js(n);

    for(int i=0;i<(1<<14);i++)
    {
        ll res=0;
        int num=0;
        for(int j=0;j<14;j++){
            if(i>>j&1){
                res+=p[j+1];
                num++;
            }
            
        }

        ans=min(ans,js(n-res)+num);
    }

    cout<<ans<<endl;



}

int main()
{
    jsp();
    int t;cin>>t;while(t--)
    solve();
}