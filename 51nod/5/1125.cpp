#include<iostream>
#include<algorithm>
#include<queue>
#include<unordered_map>
//#define int long long;
using namespace std;
typedef long long ll;

const int N=5e5+10;
unordered_map<int,int>st;
bool v[N];
ll n;
ll a[N];
ll b[N];

int main()
{
    ll mn=0x3f3f3f3f;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
        
        mn=min(a[i],mn);
    }

    sort(b+1,b+n+1);

    for(int i=1;i<=n;i++)
    {
        st[b[i]]=i;
    }

    ll ans=0;

    for(int i=1;i<=n;i++)
    {
        if(v[i])continue;
        queue<int>q;
        ll jbzx=0x3f3f3f3f;
       
        if(st[a[i]]!=i){

           ll t;
            t=i;
            ll sum=0;
            while(!v[t])
            {
                v[t]=true;
                jbzx=min(jbzx,a[t]);
                sum+=a[t];
                q.push(a[t]);
                t=st[a[t]];
               // cout<<a[t]<<endl;
            }

           // cout<<sum<<endl;

          // cout<<sum+(q.size()-1)*jbzx<<endl;

            ans+=min(sum+(q.size()-2)*jbzx,sum-jbzx+mn+(q.size()-2)*mn+2*(mn+jbzx));

        }

        //cout<<ans<<endl;
    }

    cout<<ans<<endl;





}
