#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int a[N];
int b[N];
int c[N];


bool cmp(int a,int b)
{
    return a>b;
}


void solve()
{
    int n,m;
    cin>>n>>m;
    int num1=0;
    int num2=0;
    int num0=0;
    for(int i=1;i<=n;i++)
    {
        int t,w;
        cin>>t>>w;
        if(t==0)
        {
            num0++;
            a[num0]=w;
        }
        else if(t==1)
        {
            num1++;
            b[num1]=w;
        }
        else 
        {
           // cout<<t<<" "<<w<<endl;
            num2++;
            c[num2]=w;
        }
    }

   

    sort(a+1,a+num0+1,cmp);
    sort(b+1,b+num1+1,cmp);
    sort(c+1,c+num2+1,cmp);
  
//     for(int i=1;i<=num0;i++)cout<<a[i]<<" ";cout<<endl;
//     for(int i=1;i<=num1;i++)cout<<b[i]<<" ";cout<<endl;
//     for(int i=1;i<=num2;i++)cout<<c[i]<<" ";cout<<endl;
    for(int i=1;i<=n;i++)a[i]+=a[i-1];
    int ans = a[m];
    int r = 1;

    ll res = 0;
    int g = c[1];
    for(int i=1;i<=num1;i++){

        if(g==0&&r<num2){
            r++;
            g+=c[r];
        }
        
        if(g){
            g--;
            res+=b[i];
        }
        
        int t = res;
        //cout<<c[r]<<endl;
        //cout<<res<<endl;
       

        int num = m-i-r;
        if(num<0)break;
        t+=(a[num]);
        ans=max(t,ans);
        //cout<<t<<endl;

    }
    cout<<ans<<endl;


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