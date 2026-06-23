#include<iostream>
#include<algorithm>

using namespace std;

const int N=1010;
int num[1000][N];

int js(int n)
{
    string s;
    int cnt=0;
    s+=" ";
    int W=1;
    
    int last=0;

    while(1)
    {
        W*=10;
        int t=W/n;
        W%=n;

        cnt++;
        if(num[W][n])
        {
            last=num[W][n];
           break;
        }
        num[W][n]=cnt;
    }

    return cnt-last;
}


int main()
{

    //cout<<js(25)<<endl;
    int n;cin>>n;
    int ans=0;
    int mx=0;
    for(int i=2;i<=n;i++)
    {
        int t=js(i);
       // cout<<i<<" "<<t<<endl;
        if(t>=mx)
        {
            mx=t;
            ans=i;
        }
    }
    cout<<ans<<endl;

}