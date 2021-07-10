#include "include.h"
#define minNum -10000
int maxSubArray(vector<int> &nums)
{
    //定义dp[i]是以nums[i]结尾的最优解
    // 他一定包含着nums[i]，但要不要前面的东西就是状态装一的东西
    //初始化
    int n=nums.size();
    vector<int> dp(n+1,minNum);
    dp[0]=nums[0];
    int maxValue=dp[0];
    for(int i=1;i<n;i++)
    {
        if(dp[i-1]>0)
        {
            dp[i]=dp[i-1]+nums[i];
        }
        if(dp[i-1]<=0)
        {
            dp[i]=nums[i];
        }
        maxValue=max(maxValue,dp[i]);
    }
    return maxValue;

}

 int nthUglyNumber(int n) 
    {
        //三根指针，计数和比大小 ，可以堪称取最小的就好了
        int index2=1;
        int index3=1;
        int index5=1;
        vector<int> dp(n+1,0);
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            int next2=dp[index2]*2;
            int next3=dp[index3]*3;
            int next5=dp[index5]*5;
            dp[i]=min(min(next2,next3),next5);
            if(dp[i]==next2) index2++;
            if(dp[i]==next3) index3++;
            if(dp[i]==next5) index5++;

        }
        return dp[n];
    }