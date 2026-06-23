#include<iostream>
#include<algorithm>
using namespace std;

const int N=1e6+10;

int num[N];
int a[N];
int st[N];
int ans=0;
bool ST[N];


void pd(int x)
{
    if(st[x]){
      return ;
    }

    if(num[x]>=2){
        ST[x]=true;
        st[x]=1;
    }

    for(int j=2;j*x<N;j++)
    {
        int k=j*x;
        ST[k]=true;
    }
    st[x]=1;
 



}

int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        num[a[i]]++;
    }
  
    for(int i=1;i<=n;i++)
    {
        pd(a[i]);
    }


    for(int i=1;i<=n;i++)
    {
        if(!ST[a[i]])ans++;
    }
    cout<<ans<<endl;
    return 0;
}


