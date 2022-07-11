class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        //         longest increasing subsequence  and print it also  this has TC:O(n^2) SC:O(N)

        //     int n=nums.size();
        //     vector<int>hash(n);

        //     int index=0;
        //     vector<int>dp(n,1);
        //       int maxi=1;
        //     for(int i=1;i<n;i++){
        //         hash[i]=i;
        //         for(int j=0;j<=i;j++){
        //             if(nums[i]>nums[j]&&dp[j]+1>dp[i]){
        //                 dp[i]=dp[j]+1;
        //                 hash[i]=j;
        //             }
        //         }
        //         if(dp[i]>maxi){
        //             maxi=dp[i];
        //             index=i;
        //         }
        //     }
        //     vector<int>lis;
        //     lis.push_back(nums[index]);
        //     while(hash[index]!=index){
        //         index=hash[index];
        //         lis.push_back(nums[index]);
        //     }
        //     reverse(lis.begin(),lis.end());
        //     for(auto i:lis){
        //         cout<<i<<" ";
        //     }
        //     return maxi;

        // }
        // using binary search
        // lower_bound() is like binary search it returns the index of the element if found and if not found it returns the immediate greater number index
        // syntaxint index= lower_bound(a.begin(),a.end(),number)-a.begin();
        vector<int> temp;
        int n = nums.size();
        temp.push_back(nums[0]);
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > temp.back())
            {
                temp.push_back(nums[i]);
            }
            else
            {
                int index = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin(); // this is binary search
                temp[index] = nums[i];
            }
        }
        return temp.size();
    }
};