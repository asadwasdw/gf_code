#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int>PII;
const int mod=1e9+7;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

const int N = 2010; 
const int M=1e9+7;

int a[N][N];
int s[N];

void init()
{
   a[0][0]=1;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(!j)a[i][j]=1;
            else a[i][j]=(a[i-1][j-1]+a[i-1][j])%M;
        }
    }
}


unordered_map<int,int>st;

ll qmi(ll a,ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1)res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}


void solve()
{

   // cout<<a[5][2]<<endl;

   int n;
   cin>>n;

    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        st[x]++;
    }

    int ans =0;


    

    for(auto t:st)
    {
        int x= t.first;
        int num = t.second;

        for(int i=1;i<=num;i++)
        {
            for(int j=0;j<=i;j++)
            {
                ans+= a[num][i]*a[n-num][j]%M;
                ans%=M;
            }
        }
    }

    int ans2=0;

    for(auto t:st)
    {
        int x= t.first;
        int num = t.second;

        for(auto t2:st)
        {
            if(t.first==t2.first)continue;

            int num2 =t2.second;
            //cout<<t2.first<<" "<<num2<<endl;
            int t =min(num,num2);

            for(int i=1;i<=t;i++)
            {
                ans2+=a[num][i]%mod*a[num2][i]%M;
                ans2%=M;
            }
        }
    }

   //cout<<ans<<" "<<ans2<<endl;

    cout<<(ans-ans2*qmi(2,mod-2)%M+M)%M<<endl;

}


signed main()
{
    init();
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}