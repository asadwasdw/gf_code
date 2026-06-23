#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
const int N=1e5+10;
bool st[N];
set<int>p;
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        for(int k=2;k<=x/k;k++)
        {
            if(x%k==0)
            {
                while(x%k==0)
                {
                    x/=k;
                }
                p.insert(k);
            }
        }

        if(x>1)p.insert(x);
    }

    for(auto a:p)
    {
        for(int i=a;i<=m;i+=a)st[i]=true;
    }
    int ans=0;
    vector<int>Ans;
    for(int i=1;i<=m;i++)
    {
      
        if(!st[i])
        {
            Ans.push_back(i);
            ans++;
        }
    }
    cout<<ans<<endl;

    for(auto a:Ans)cout<<a<<endl;
}