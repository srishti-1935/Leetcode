class Solution {
public:
    int n;
    const int mod=1e9+7;
   // vector<int>dp;


   /* int f(int i,string &s){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        long long ans=0;
        vector<bool>visited(26,false);
        for(int j=i;j<n;j++){
            if(visited[s[j]-'a']) continue;
           ans=(ans%mod+1+f(j+1,s))%mod;
           visited[s[j]-'a']=true;
        }
        return dp[i]=(int)ans;
    }
    */


  /*  int f(int i,vector<int>&prevIdx,string &s){
        if(i==-1) return 1;
        if(dp[i]!=-1) return dp[i];
        long long ans=2LL*f(i-1,prevIdx,s)%mod;
        if(prevIdx[i]!=-1) ans=(ans-f(prevIdx[i]-1,prevIdx,s)+mod)%mod;
        return dp[i]=(int)ans%mod;
    }
   */

    int distinctSubseqII(string s) {
        this->n=s.size();


       vector<int>prevIdx(n+1,-1);
       unordered_map<char,int>mpp;
       for(int i=0;i<n;i++){
        if(mpp.count(s[i])) prevIdx[i+1]=mpp[s[i]];
        mpp[s[i]]=i+1;
       }
       vector<int>dp(n+1,-1);
       dp[0]=1;
       for(int i=1;i<=n;i++){
         long long ans=2LL*dp[i-1]%mod;
         if(prevIdx[i]!=-1) ans=(ans-dp[prevIdx[i]-1]+mod)%mod;
         dp[i]=(int)ans%mod;
       }
       return (dp[n]-1+mod)%mod;
    }
};