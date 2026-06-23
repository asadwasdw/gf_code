    #include<iostream>
    #include<algorithm>
    #include<set>
    using namespace std;

    const int N=5010,M=1e7+7;
     long long f[M];
    int a[N];

    int main()
    {
        
        int n,k;cin>>n>>k;
        int mx=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            mx=max(mx,a[i]);
        }

        sort(a+1,a+n+1);

        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            f[a[j]-a[i]]++;
        }

        int ans=n-k;

        while(ans)
        {
           
            long long cnt=0;
            for(int i=ans;i<=mx;i+=ans)
            {
                cnt+=f[i];      
                if(cnt>(long long)k*(k+1)/2)break;          
            }

            if(cnt>(long long)k*(k+1)/2)
            {
                 //cout<<ans<<endl;
                ans++;
                continue;
            }

            set<int> s;
            bool bx=true;
            for(int i=1;i<=n;i++)
            {
                s.insert(a[i]%ans);
            }

            if(s.size()>=n-k){
                cout<<ans<<endl;
                break;
            }
            ans++;
   
        }
    }