#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--){
    long long A,B,C;
    cin>>A>>B>>C;
   // cout<<A<<B<<C<<endl;
    long long sum=(A+B+C);
    if(sum%2){
        cout<<"NO"<<endl;
        continue;
    } 
    sum/=2;
        
    long long a[5];
     a[1]=sum-C;
     a[2]=sum-B;
     a[3]=sum-A;
     sort(a+1,a+4);
     //cout<<a[1]<<a[2]<<a[3]<<endl;
     if(a[1]+a[2]>a[3])
     {
        cout<<"Yes"<<endl;


        printf("%lld %lld %lld\n",sum-A,sum-B,sum-C);
     }
     else cout<<"No"<<endl;
    }

}