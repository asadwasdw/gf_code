#include<iostream>
#include<algorithm>

using namespace std;
const int N=1e5+10;

int f[N];
int F(int k,int x)
{
    if(k>1)return f[F(k-1,x)];

    else return f[x];

}

int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>f[i];

   cout<<F(1,4)<<endl;

    int q;
    cin>>q;
   for(int i=1;i<=q;i++)
    {
        cout<<i<<"---->";
        int a,b;
        cin>>a>>b;
       // cout<<a<<" "<<b<<" ";
        
        for(int x=1;x<=n;x++)
        {
            if(F(a,x)==F(b,x))cout<<x<<" ";
        }
        cout<<endl;
    }

}