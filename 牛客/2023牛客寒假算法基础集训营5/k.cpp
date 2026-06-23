#include<algorithm>
#include<iostream>

using namespace std;

int main()
{
    long long n;cin>>n;
    int cnt=0;
    while(n>2)
    {
        cnt++;
        if(n%2==0)
        {
            n-=n/2-1;
        }
        else{
            n-=n/2;
        }

       // cout<<n<<endl;
    }

    cout<<cnt<<endl;
}