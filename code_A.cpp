

ll dp[100][32];

void solve() {
    
    ll n,m;
    cin>>n>>m;
    
    memset(dp,-1,sizeof(dp));
    
    for(int i=0;i<m;i++)
    {
        ll x,y;
        cin>>x>>y;
        
        dp[y][0] = x;
    }
    
    for(int len=1;len<=32;len++)
    {
        for(int i=1;i<=n;i++)
        {
            if(dp[i][len - 1] != -1)
                dp[i][len] = dp[dp[i][len - 1]][len - 1];
        }
    }
    
    ll len = 4;
    
    ll x = 6;
    
    for(int i=0;i<32;i++)
    {
        if((len >> i)&1)
            x = dp[x][i];
    }
    
    cout<<x;
    
}// do mind if testcases input required or not

