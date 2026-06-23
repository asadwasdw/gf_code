#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<vector>
#include<cstring>
#include<queue>

typedef long long ll;
using namespace std;

int M= 998244353;

ll qmi(ll a,ll b,ll p)
{
    ll res=1;
    while(b)
    {
        if(b&1)res=(res*a)%p;
        a=(a*a)%p;
        b>>=1;
    }
    return res;
}

unordered_map<ll,ll>mp;
unordered_map<ll,bool>st;

ll num[10];

void js(ll n)
{
    while(n%2==0)
    {
        n/=2;
        num[2]++;
    }

    while(n%3==0)
    {
        n/=3;
        num[3]++;
    }

    while(n%5==0)
    {
        n/=5;
        num[5]++;
    }
}

void solve()
{

    ll n;cin>>n;

    ll gl=qmi(5,M-2,M);

    priority_queue<ll,vector<ll>,greater<ll>>q;

    js(n);
    q.push(1);

    ll yz2=qmi(2,num[2]+1,M*M);

    ll yz3=qmi(3,num[3]+1,M*M);
    ll yz5=qmi(5,num[5]+1,M*M);

   // cout<<yz5<<endl;

    mp[1]=1;

    while(q.size())
    {
        ll t=q.top();q.pop();
       // cout<<t<<" "<<mp[t]<<endl;
        for(int i=2;i<=6;i++)
        {
         
            ll x=t*i;
             //  cout<<x<<endl;
            if(x>n)continue;
            if(x<1)continue;

            if(x%yz2==0)continue;
            if(x%yz3==0)continue;
            if(x%yz5==0)continue;

            if(!st[x])
            {
                q.push(x);
                mp[x]=0;
            }
            st[x]=true;
            mp[x]+=mp[t]*gl%M;
            mp[x]%=M;
        }
    }

    //cout<<8*qmi(36,M-2,M)%M<<endl;

    cout<<mp[n]<<endl;

    

    
}


int main()
{
  //int t;cin>>t;while(t--)
    solve();
}