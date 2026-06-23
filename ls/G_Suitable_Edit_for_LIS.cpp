#include <iostream>

#include<cstring>
using namespace std;

const int N =1e5+10;

int a[N];
int q[N],id[N];

int main()
{
    
    int n;
    cin>>n;
    int len =0;
    
    for(int i=1;i<=n;i++)cin>>a[i];
    int ans = 0;

    for(int i=1;i<=n;i++)
    {
        
        int l=0,r=len;
        int t = 0;
        
        while(l<r)
        {
            int mid =l+r+1>>1;
            if(q[mid]>=a[i]) r=mid-1;
            else l=mid;
        }

        if(id[r] < i - 1 && q[r] < a[i] - 1) t = 1;

        len = max(len,r+1);
        ans = max(len + t, ans);
        cout << q[r + 1] << " -- ";

        if(q[r + 1] == 0 || (a[i] < q[r + 1]))  {
            q[r + 1] = a[i];
            id[r + 1] = i;
        }

       
        for(int i = 1; i <= len; i ++) cout << id[i]<< " \n"[i == len];

        // cout << len << endl;
        
    }
    
    cout<<ans;
    
    
}