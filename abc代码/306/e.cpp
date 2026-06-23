#include<bits/stdc++.h>
#define int long long 
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;


void solve()
{
    int n,k,q;
    cin>>n>>k>>q;

    vector<int>a(n+10);
    multiset<int>st1,st2;


    for(int i=1;i<=k;i++)st2.insert(0);
    for(int i=k+1;i<=n;i++)st1.insert(0);
    int ans=0;

    while(q--)
    {
        int x,y;
        cin>>x>>y;

        if(st2.find(a[x])!=st2.end()){
            ans-=a[x];
            st2.erase(st2.find(a[x]));
        }
        else 
        {
            st1.erase(st1.find(a[x]));
        }
        a[x]=y;
        if(st2.size()<k){
            ans+=y;
            st2.insert(y);
        }
        else {
            st1.insert(y);
        }

        if(st2.size()&&st1.size()&& *st2.begin() < *st1.rbegin())
        {

            int x1=*st2.begin();
            int x2=*st1.rbegin();
            
            ans-=x1;
            ans+=x2;

            st1.erase(prev(st1.end()));
            st2.erase(st2.begin());

            st1.insert(x1);
            st2.insert(x2);

        }
   
        cout<<ans<<endl;

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