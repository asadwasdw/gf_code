#include<iostream>
#include<algorithm>

using namespace std;

const int N=510;

int a[N][N];
int b[N][N];
int c[N][N];
int ans[N][N];

int main()
{
    int n;cin>>n;


    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
        cin>>a[i][j];
    }


    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
        cin>>b[i][j];
    }

    
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
        cin>>c[i][j];
    }


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {

            int sum=0;

            for(int k=1;k<=n;k++)
            {
                sum+=a[i][k]*b[k][j];
            }

            ans[i][j]=sum;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(ans[i][j]!=c[i][j]){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }

    cout<<"Yes"<<endl;
}