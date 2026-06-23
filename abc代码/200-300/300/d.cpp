#include<iostream>
#include<algorithm>

using namespace std;
#define int long long
const int N=5e7+10;
int p[N];
bool st[N];
int cnt=0;

void prime()
{
    for(int i=2;i<N;i++)
    {
        if(!st[i])p[cnt++]=i;

        for(int j=0;p[j]*i<N;j++)
        {
            st[p[j]*i]=true;
            if(i%p[j]==0)break;
        }
    }
}


signed main()
{

    prime();
    int n;cin>>n;

    int ans=0;

   // for(int i=0;i<=10;i++)cout<<p[i]<<endl;


    for(int i=0;p[i]*p[i]<n;i++)
    {
        for(int j=i+1;p[i]*p[i]*p[j]<n;j++)
        {
            int l=0,r=cnt;
            int mul=p[i]*p[i]*p[j];


            while(l<r)
            {
                int mid=(l+r+1)>>1;
                if(p[mid]*p[mid]*mul>n||p[mid]*p[mid]*mul<0)r=mid-1;
                else l=mid;
            }

            if(l<=j)break;

           // cout<<mul<<" ";
           // cout<<l-1<<endl;

            ans+=max(0ll,l-j);
        }
    }  
   // cout<<p[cnt-1]<<endl;

    cout<<ans<<endl;

}