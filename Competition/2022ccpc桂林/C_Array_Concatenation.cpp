#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=1e9+7;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
int a[N];
int qmi(int a,int b,int c) {
    int res = 1;
    while(b) {
        if(b&1) res = res * a % c;
        a = a*a%c;
        b>>=1;
    }
    return res;
}
int a2[N];



void solve()
{


    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];

    int ans1,ans2;
    {
        int num = (((qmi(2,2*m,mod) - (((qmi(2,m,mod)-1 + mod)%mod) * qmi(2,m-1,mod) %mod) + mod )%mod)) *n %mod;
        int cd = qmi(2,m,mod);
        int ans = 0;
        for(int i=1;i<=n;i++) {
            ans+=num*a[i]%mod;
            // cout<<num<<endl;
            num = (num - cd + mod) %mod;
            ans%=mod;
        }

        ans1 = ans;
    }

    {
  
        
        for(int i=1;i<=n;i++)a2[i] = a[n-i+1];
        for(int i=n+1;i<=2*n;i++)a2[i] = a[i-n];

        n*=2;
        m--;

        for(int i=1;i<=n;i++)a[i]=a2[i]%mod;
    
        if(m==0) {
            int sum = 0;
            for(int i=1;i<=n;i++) {
                a[i]+=a[i-1];
                sum += a[i];
            }
            ans2 = sum%mod;
            
        }
        else {

            int num = (((qmi(2,2*m,mod) - (((qmi(2,m,mod)-1 + mod)%mod) * qmi(2,m-1,mod) %mod) + mod )%mod)) *n %mod;
            int cd = qmi(2,m,mod);
            int ans = 0;
            for(int i=1;i<=n;i++) {
                ans+=num*a[i]%mod;
                // cout<<num<<endl;
                num = (num - cd + mod) %mod;
                ans%=mod;
            }
              ans2 = ans%mod;
        }
    }

    cout<<max(ans1,ans2)<<endl;



}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}