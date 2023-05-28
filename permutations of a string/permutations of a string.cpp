class Solution {
public:

    void solve(vector<int>& nums, int index, vector<vector<int>> &ans)
    {
        //in this question we just take th original nums and reorder it and get the base case and push it in ans then again reorder nums again push back and so on
            
        //base case
        if(index>=nums.size())
        {
            //in base case we get a combination so we push this order of nums into ans
            ans.push_back(nums);
            return;
        }

        //swap the index ele with itself and with  all  ele next to it, so j will look after it by pointing to index and all ele to next of it till the end of nums
        for(int j = index; j<nums.size(); j++)
        {
            swap(nums[index], nums[j]);
            //keep increasing the index and run recursion
            solve(nums,index+1,ans);
            // we undo the swapping as we move up the recusion tree now
            swap(nums[index], nums[j]);

        }

    }



    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index =0;

        solve(nums,index,ans);

        return ans;
    }
};
