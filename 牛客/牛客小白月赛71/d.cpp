#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
const int N=4e5+10;

typedef long long ll;

ll a[N],b[N],c[N],d[N];
ll A[N];
unordered_map<ll,ll>st;

ll tr[N];
ll cnt;
ll lowbit(ll x)
{
    return x&-x;
}

void update(int x,int v)
{
    while(x<=cnt)
    {
        tr[x]=max(tr[x],(ll)v);
        for(int i=1;i<lowbit(x);i<<=1)
        {
            tr[x]=max(tr[x],tr[x-i]);
        }
        x+=lowbit(x);
    }
}
 
 
 
int query(int l,int r)
{
   ll ans=-1;
    while(l<=r)
    {
        ans=max(ans,A[r]);
        r--;
        while(r-l>=lowbit(r)){
            ans=max(tr[r],ans);
            r-=lowbit(r);
        }
    }
    return ans;
}

int main()
{
    int n,m;
    cin>>n>>m;

    vector<int>lsh;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        lsh.push_back(a[i]);
    }

    for(int i=1;i<=m;i++)
    {
        cin>>c[i];
    }

    for(int i=1;i<=m;i++)
    {
        cin>>d[i];
        lsh.push_back(d[i]);
      //  lsh.push_back(c[i]);
    }

    sort(lsh.begin(),lsh.end());

     cnt=1;

    st[lsh[0]]=1;

   // for(auto t:lsh)cout<<t<<" ";cout<<endl;
   

    for(int i=1;i<lsh.size();i++)   
    {
        if(lsh[i]==lsh[i-1])continue;
        cnt++;
        st[lsh[i]]=cnt;
    }

  
    for(int i=1;i<=m;i++)
    {
        update(st[d[i]],c[i]);
        A[st[d[i]]]=max(A[st[d[i]]],c[i]);
    }


    for(int i=1;i<=n;i++)
    {
        ll t=query(1,st[a[i]]);
        if(t<b[i])t=-1;
        cout<<t<<" ";
    }

}