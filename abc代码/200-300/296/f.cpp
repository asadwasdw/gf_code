#include<iostream>
#include<algorithm>

using namespace std;
const int N=2e5+10;
int a[N];
int b[N];
int t[N];

int gbpx(int a[],int l,int r)
{
    if(l>=r)return 0;
    int ans=0;
    int mid=l+r>>1;
    ans+=gbpx(a,l,mid);
    ans+=gbpx(a,mid+1,r);

    int i=l,j=mid+1;
    int k=0;

    while(i<=mid&&j<=r)
    {
        if(a[i]<=a[j])
        {
            t[++k]=a[i++];
        }
        else{
            ans+=mid-i+1;
           // ans+=j-mid;
            t[++k]=a[j++];
        }
    }

    while(i<=mid)
    {
        t[++k]=a[i++];
    }
    while(j<=r)
    {
        t[++k]=a[j++];
    }

    for(int i=1;i<=k;i++)
    {
        a[l+i-1]=t[i];
    }

    return ans;
}



int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];

  
    int t1=gbpx(a,1,n);
    int t2=gbpx(b,1,n);


    bool cf=false;

    for(int i=1;i<=n;i++)
    {
        if(a[i]!=b[i])
        {
            cout<<"No"<<endl;
            return 0;
        }
    }

      for(int i=2;i<=n;i++)
    {
        if(a[i]==a[i-1]||b[i]==b[i-1])
        {
            cout<<"Yes"<<endl;
            return 0;
        }
    }

    if(t1%2==t2%2)cout<<"Yes";
    else cout<<"No";



}