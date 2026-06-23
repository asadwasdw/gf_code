#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=2e6+10;
const int mod=1e9+7;
const int INF  = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

int n;
const int P =13331;
ull p[N];
ull h[N];
ull fh[N];


ull get(int l,int r)
{
    if(l>r)return 0;
    return (h[r]-h[l-1]*p[r-l+1]%mod+mod)%mod;
}

ull get2(int L,int R)
{
    int l=2*n-R+1;
    int r=2*n-L+1;
    if(l>r)return 0;
    return (fh[r]-fh[l-1]*p[r-l+1]%mod+mod)%mod;
}


void solve()
{
    cin>>n;

    p[0]=1;
    string s;
    cin>>s;
    string fs=s;
    reverse(fs.begin(),fs.end());
   
    s=" "+s;
    fs=" "+fs;
    for(int i=1;i<=2*n;i++)
    {
        p[i]=p[i-1]*P%mod;
        h[i]=h[i-1]*P%mod+s[i]-'a'+1+mod%mod;
        fh[i]=fh[i-1]*P%mod+fs[i]-'a'+1+mod%mod;

        p[i]%=mod;
        h[i]%=mod;
        fh[i]%=mod;
    }

    //cout<<get(1,3)<<endl;

     //cout<<fs<<endl;

    for(int i=0;i<=n;i++)
    {
        ull t = (get(1,i)*p[2*n-(i+n+1)+1]%mod+get(i+n+1,2*n)%mod)%mod;
        //cout<<i<<" "<<i+n+1<<endl;
    
        ull t2 = get2(i+1,i+n)%mod;
      //  cout<<t<<" "<<t2<<endl;
        if(t==t2){
          //  cout<<"Yes"<<endl;
            for(int j=i+n;j>=i+1;j--){
                cout<<s[j];
            }
            cout<<endl<<i<<endl;
            return;
        }
    }

    cout<<"-1"<<endl;


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