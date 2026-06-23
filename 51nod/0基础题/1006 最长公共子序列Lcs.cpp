#include<iostream>
#include<algorithm>

using namespace std;

const int N=1e3+10;

int f[N][N];


int main()
{

    string a,b;
    cin>>a>>b;
   a=" "+a;
   b=" "+b;
    char final[1002]={0};
     int ans=0;
     

    for(int i=1;i<a.size();i++)
    {
        for(int j=1;j<b.size();j++)
        {
            f[i][j]=max(f[i-1][j],f[i][j-1]);
            if(a[i]==b[j])f[i][j]=max(f[i][j],f[i-1][j-1]+1);

            ans=max(ans,f[i][j]);
        }
    }
    int i=a.size();
    int j=b.size();

    int k=1001;
	while(i>0&&j>0)
		if(a[i]==b[j])
		{
			final[k--]=a[i];
			i--;
			j--;			
		}else if(f[i-1][j]>f[i][j-1])
			i--;
		else j--;
   printf("%s\n",final+k+1);
  //  cout<<ans<<endl;

}