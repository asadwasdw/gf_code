#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


vector<int>lsh;
   int n,m;
int a[N];

int tr[N];


ll sum(int x)
{
    ll res = 0;
    for(int i=x;i;i-= i&-i)res+=tr[i];
    return res;
}

void add(int x,int t)
{
    for(int i=x;i<N;i+= i&-i)tr[i]+=t;
}



int find()
{
    int l =1;
    int r =1e6;
    while(l<r){
        int mid=(l+r)>>1;
        if(sum(mid)>=(n+1)/2)r=mid;
        else l=mid+1;
    }
    return l;

}


void solve()
{

 
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        add(a[i],1);
    }


    while(m--)
    {
        int x,y;
        cin>>x>>y;
        add(a[x],-1);
        add(y,1);
        a[x]=y;

        cout<<find()<<endl;

    }


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