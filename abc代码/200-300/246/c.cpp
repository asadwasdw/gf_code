#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;



priority_queue<int>q;

#define int long long 

signed main()
{

    int n,k,x;
    cin>>n>>k>>x;

    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%lld",&a);
        q.push(a);
      //  cout<<a<<endl;
    }

    for(int i=1;i<=k;i++)
    {

        if(q.size()){
        
        int t=q.top();q.pop();
        int num=max(t/x,1ll);
        num=min(num,k-i+1);
        //cout<<t<<endl;
        t-=num*x;
        i+=num-1;
        if(t>=1)q.push(t);

        }
        else break;
    }
    int ans=0;
    while(q.size())
    {
        ans+=q.top();
        q.pop();
    }

    cout<<ans<<endl;


}