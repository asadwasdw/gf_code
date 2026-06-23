#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void solve()
{
    vector<int>js;
    bool hjs=false;
    int n;cin>>n;
    long long sum=0;

    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x%2==0)continue;
        sum+=x;
        js.push_back(x);
        if((x-1)%4==0)hjs=true;
    }

    if(sum%2==0){
        cout<<"0"<<endl;
        return;
    }
    if(hjs){
        cout<<"1"<<endl;
        return;
    }
    int ans=999999999;

    for(auto t:js){
        int cs=0;
        while(1){
           cs++;
          int tt=t/2;
          if((t-tt)%2==1){
            break;
          }
          t=tt;
        }
        ans=min(ans,cs);
    }

    cout<<ans<<endl;




}

int main()
{
    int t;cin>>t;while(t--)
    solve();
}