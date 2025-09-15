int mod;
int rec(int ind,string & str,vector<int>&dp)
{
    if (ind==str.size()) return 1;
    if (dp[ind]!=-1) return dp[ind];
    if (str[ind]=='0') return dp[ind]=0;
    int cur=0;
    int ans=0;
    for (int i=ind;i<str.size();i++)
    {
        int ele=str[i]-'0';
        cur=cur*10+ele;
        if (cur>26) break;
        ans= (ans%mod+rec(i+1,str,dp)%mod)%mod;
    }
    return dp[ind]=ans;
}

int decodeWays(string strNum) {
    mod=1e9+7;
    int sz=strNum.size();
    vector<int>dp(sz,-1);
    return rec(0,strNum,dp);
}