#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;
const int N=2e5+110;
long long a[N];
void solve()
{
    int n;cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int s=0;
    priority_queue <int,vector<int>,greater<int> > q;//递增

    for(int i=n;i;i--)
    {
        if(a[i]==0)
        {
           //cout<<i<<endl;
            s++;
        }
        else{
            
            if(q.size()<s)
            {
                q.push(a[i]);  
            }
            else{

                if(q.size()&&a[i]>q.top()){
                    q.pop();
                    q.push(a[i]);
                }
            }
        } 
    }
   //cout<<s<<endl;
  //cout<<q.size()<<endl;

    long long ans=0;
    while(q.size())
    {
        ans+=q.top();
        q.pop();
    }
    cout<<ans<<endl;
}


int main()
{
    int t;cin>>t;while(t--)
    solve();

}

