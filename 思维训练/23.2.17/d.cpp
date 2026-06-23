#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector< pair <int,int>>ans;
const int N=2e5+10;
long long a[N];
void  solve()
{
    int n,k;
    cin>>n>>k;
    ans.clear();

    int l=1;
   

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i==1)continue;

        if(a[i]*2>a[i-1]){
           // cout<<i<<" "<<a[i]<<endl;
            continue;
        }
        else{
          //  if(i==n)yn=true;
            ans.push_back({l,i-1});
            l=i;
        }
    }
     ans.push_back({l,n});
    int res=0;
    k++;
    for(auto t:ans)
    {
        res+=max(0,t.second-t.first+1-k+1);
      //  cout<<t.first<<" "<<t.second<<endl;
    }

    cout<<res<<endl;    

}


int main()
{
    int t;cin>>t;while(t--)
    solve();
}
