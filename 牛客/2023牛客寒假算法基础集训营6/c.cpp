#include<iostream>
#include<algorithm>

using namespace std;
const int N=1010;
const int M=1e9+10;
int a[N];
long long b[N];
int main()
{
    int n;
    cin>>n;
    int mid=n/2+1;
    for(int i=n;i;i--)
    {
       if(n==i) b[mid]=a[mid]=i;
       else {
        if((n-i)%2==1){
            b[mid-(n-i+1)/2]=a[mid-(n-i+1)/2]=i;
        }
        else{
            b[mid+(n-i)/2]=a[mid+(n-i)/2]=i;
        }
       }
    }

  
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=n-i+1;j++)
        {
            b[j]=(b[j]+b[j+1])%M;
        }
    }

    cout<<b[1]<<endl;
      for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
}