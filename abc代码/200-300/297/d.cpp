#include<iostream>

#include<algorithm>

using namespace std;

int main()
{
   long long a,b;
    cin>>a>>b;
    long long  cnt=0;
    while(a!=b)
    {
        if(a>b)swap(a,b);
        long long t=b-a;
        long long c=t/a;
        b-=a*c;
        cnt+=c;
        if(b>a){
            cnt++;
            b=b-a;
        }
     //   cout<<a<<" "<<b<<endl;
    }

    //cout<<a<<" "<<b<<endl;
    cout<<cnt<<endl;
}
 