#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

map<int,int>jy;
map<int,int>ans;
int bf(int x)
{
    if(jy[x])return jy[x];
    int num=0;
    while(x){
        if(x&1)num++;
        x>>=1;
    }
    return jy[x]=num;
}

int main()
{
    int n,q;
   cin>>n>>q;
    priority_queue<int> a;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        a.push(x);
    }

    for(int k=1;k<=10000000;k++)
    {
        int x=a.top();a.pop();
        if(x==1)
        {
            break;
        }
        x=bf(x);
        a.push(x);
        ans[k]=a.top();
    }
    while(q--)
    {
        int x;
        cin>>x;
        if(ans[x])cout<<ans[x]<<endl;
        else cout<<"1"<<endl;
    }
    
    
}