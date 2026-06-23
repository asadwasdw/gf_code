#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=2e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


int tr[N];

void add(int x,int c)
{
    for(int i=x;i<N;i+=i&-i)tr[i]+=c;
}


ll sum(int x)
{
    ll res=0;
    for(int i=x;i;i-= i&-i)res+=tr[i];
    return res;
}

int last[N];
int a[N];

void solve()
{
    int n;cin>>n;

    // if(n==7)
    // {
    //     cout<<"7 6 5 4 4 4 4"<<endl;
    //     return;
    // }

    for(int i=0;i<=n+10;i++)tr[i]=0,last[i]=0,a[i]=0;;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(last[x]==0)
        {
            int t = sum(i);
            a[1]++;
          //  cout<<i<<" "<<t<<endl;
        }
        else {
            int t = sum(i)-sum(last[x]);
            a[1]++;
            a[t+1]--;
          //  cout<<i<<" "<<t<<endl;
            add(last[x],-1);
        }
        last[x]=i;
        add(last[x],1);
    }

    for(int i=1;i<=n;i++)
    {
        a[i]+=a[i-1];
    }

    for(int i=1;i<=n;i++){
        cout<<a[i];
        if(i!=n)cout<<" ";
    }
    cout<<endl;
    

}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}