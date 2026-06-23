#include<iostream>
#include<algorithm>

using namespace std;

const int N=1e5+10;
int h[N],v[N];

int main()
{
    long long n,t,a;
    long long ans=0;
    cin>>n>>t>>a;

    for(int i=1;i<=n;i++)
    {
        cin>>h[i]>>v[i];
    }

   for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        if(h[i]>a&&v[i]*t>=a){
            cout<<"-1"<<endl;
            return 0;
        }
         
        ans++;

        if(h[i]>a)ans+=((h[i]-a)/(a-t*v[i])+(((h[i]-a)%(a-t*v[i]))!=0));

    }
    cout<<(ans-1)*t+1<<endl;
}