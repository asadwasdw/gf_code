#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

const int N=1e5+10;
long long a[N];
int n;

long long js(long long x)
{
    long long cs=a[0]-1;
    long long t=x;
    for(int i=1;i<n;i++){
        cs+=abs(t-a[i]);
        t*=x;
        if(t<0)return 999999999899999999;
      //  cout<<t<<endl;
    }
    return cs;
}
int main()
{
   cin>>n;

    for(int i=0;i<n;i++)cin>>a[i];

    sort(a,a+n);

    long long t=pow(a[n-1],(double)1/(n-1));
    while(1){
		if(pow(t,n-1)>=a[n-1])break;
		t++;
	}

    //cout<<t<<endl;
    long long ans=js(t);

   ans=min(ans,js(t+1));
    if(t!=1)ans=min(ans,js(t-1));
  
    cout<<ans<<endl;
    
}