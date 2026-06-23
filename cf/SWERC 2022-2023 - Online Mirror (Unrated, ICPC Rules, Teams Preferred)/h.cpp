#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

const int N=2e5+10;
unordered_map<int,int>dy;
int a[N];
void solve()
{
    dy.clear();

    int n;cin>>n;

    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        dy[x]=i;
    }

    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        a[i]=dy[x];
    }
    int zj=n;

    

    int ans=0;
    for(int i=n;i;i--){
      //  cout<<a[i]<<" ";
        if(a[i]>zj){
            ans=i;
            break;
        }
        zj=min(a[i],zj);
    }
   // cout<<endl;
   cout<<ans<<endl;

}


int main()
{
     int t;cin>>t;while(t--){
        solve();
     }
}