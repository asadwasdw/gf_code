#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
const int N=2e5+10;
int a[N];

int arr[N];
int temp[N];
long long int ans=0;
void sort(int l,int r)
{
    if(l>=r)
    return ;
    
    int mid=(l+r)>>1;
    
    sort(l,mid);
    
    sort(mid+1,r);
    int k=0;
    int i=l;
    int j=mid+1;
    while(i<=mid&&j<=r)
    {
        if(arr[i]<arr[j])
        {
            temp[k++]=arr[i++];
        }
        else
        {
            ans+=mid-i+1;
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid)
    {
        temp[k++]=arr[i++];
    
    }
    while(j<=r)
    {
         temp[k++]=arr[j++];
    }
    
    for(int q=l, i=0;q<=r;)
    {
        arr[q++]=temp[i++];
    }
    
    
}



void solve()
{
    int n;
    cin>>n;
    ans=0;
    for(int i=0;i<n;i++)cin>>arr[i];
    
    sort(0,n-1);
    
     cout<<ans<<endl;

}

int main()
{
    int n;cin>>n;
    while(n--)
    solve();
}