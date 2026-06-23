#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
using namespace std;
const int N=2e6+10;

typedef pair<int,int>PII;
typedef long long ll;
unordered_map<ll,ll>mp;
vector<int>a;

PII qj[N];
int W[N];

int sum1[N];
ll sum2[N];

int main()
{
    int n;cin>>n;
    int k;cin>>k;

    for(int i=1;i<=n;i++)
    {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        a.push_back(x);
        a.push_back(y);
        a.push_back(y+1);
        qj[i]={x,y};
        W[i]=w;
    }
    a.push_back(0);
    int cnt=0;

    sort(a.begin(),a.end());

    for(int i=1;i<a.size();i++)
    {
        if(a[i]!=a[i-1])
        {
            cnt++;
            mp[a[i]]=cnt;
        }
    }

    for(int i=1;i<=n;i++)
    {
        int x=qj[i].first;
        int y=qj[i].second;
        x=mp[x];y=mp[y];

        sum1[x]++;
        sum1[y+1]--;

        sum2[x]^=W[i];
        sum2[y+1]^=W[i];
    }

    for(int i=1;i<=cnt;i++)
    {
        sum1[i]+=sum1[i-1];

        sum2[i]^=sum2[i-1];
    }

    ll ans=-1;


    for(int i=1;i<=cnt;i++)
    {
        if(sum1[i]>=k)
        {
            ans=max(ans,sum2[i]);
        }
    }
    printf("%lld",ans);

   // cout<<ans<<endl;




}