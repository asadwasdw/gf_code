#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;


void solve(){
    vector<pair<ll,ll>>a,b;

    ll n,m;
    cin>>n>>m;
    ll cnt=-1;
    for(int i=1;i<=n;i++)
    {
        ll x;
        cin>>x;

        ll gs=1;
        while(x%m==0)
        {
            gs*=m;
            x/=m;
        }

        if(cnt== -1)
        {
            cnt++;
            a.push_back({x,gs});
            continue;
        }

        if(a[cnt].first==x){
            gs+=a[cnt].second;
            a[cnt]={x,gs};
        }
        else{
           // cout<<x<<" "<<a[cnt].first<<endl;
            cnt++;
            a.push_back({x,gs});
        }
        
    }
    cin>>n;

    cnt=-1;

    for(int i=1;i<=n;i++)
    {
        ll x;
        cin>>x;

        ll gs=1;
         while(x%m==0)
        {
            gs*=m;
            x/=m;
        }
        if(cnt==-1)
        {
            cnt++;
            b.push_back({x,gs});
            continue;
        }

        if(b[cnt].first==x){
            gs+=b[cnt].second;
            b[cnt]={x,gs};
        }
        else{
            cnt++;
            b.push_back({x,gs});
        }
    }

    //for(auto t:a) cout<<t.first<<" "<<t.second<<endl;cout<<endl;
  //  for(auto t:b) cout<<t.first<<" "<<t.second<<endl;


    if(a==b)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}


int main()
{
    int t;cin>>t;while(t--)
    solve();
}