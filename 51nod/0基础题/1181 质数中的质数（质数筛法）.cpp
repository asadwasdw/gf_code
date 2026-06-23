#include<iostream>
#include<algorithm>

using namespace std;

const int N=1e7+10;
bool st[N];
int pri[N];
int cnt;

int dypri(int n)
{
    st[1]=true;
    for(int i=2;i;i++)
    {
        if(!st[i]){
            pri[cnt++]=i;
            if(i>=n&&!st[cnt])return i;
            
        }

        for(int j=0;j<cnt&&pri[j]<N/i;j++)
        {
            st[pri[j]*i]=true;

            if(i%pri[j]==0)
            {
                break;
            }
        }
    }
    return 0;
}

int main()
{
    int n;cin>>n;
    
    cout<<dypri(n);
}