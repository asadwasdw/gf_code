#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

typedef long long ll;

const int MOD =998244353;

const int N =4e5+10;
int dp[N];

ll qmi(ll a,ll b,ll c)
{
    ll res=1;
    while(b)
    {
        if(b&1)res=res*a%c;
        a=a*a%c;
        b>>=1;
    }

    return res;
}

int main()
{
    int n;cin>>n;
    string s;
    cin>>s;
    //s=" "+s;
    //cout<<s<<endl;

    for(int i=1;i<n;i++)
    {
        if(n%i)continue;
       // cout<<i<<endl;
        vector<int>f(n+1,1);
        for(int j=0;j<n;j++)
        {
            if(s[j]=='.')
            {
              // cout<<j%i<<" ";
                f[j%i]=0;
            }
            //cout<<endl;
        }

            // for(int j = 0; j < n; j ++ ) 
            //     if(s[j] == '.')
            //          f[j % i] = 0;

        //for(int j=0;j<i;j++)cout<<f[j]<<" ";cout<<endl;

        ll cnt=0;

        for(int j=0;j<i;j++)cnt+=f[j];
        //if(f[j])cnt++;

       //cout<<cnt<<endl;

        dp[i]=qmi(2,cnt,MOD);

        for(int j=1;j<i;j++)
        {
            if(i%j)continue;
            dp[i]=(dp[i]-dp[j]+MOD)%MOD;
        }
    }

    ll ans=0;

    for(int i=1;i<=n;i++)
    {
        ans=(ans+dp[i]+MOD)%MOD;
        //cout<<i<<" "<<dp[i]<<endl;
    }
    cout<<ans<<endl;
    
}