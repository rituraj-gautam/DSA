class Solution {
public:

    void solve(string &digits,string out, vector<string> &ans, int index, string map[])
    {
        //base case -- if index crosses input array's size then we get one combination so we input it in ans
        if(index>=digits.size())
        {
            ans.push_back(out);
            return;
        }

      
      // we find the first number of the input string , as it is in string format so we take the string's first character and minus it with '0' to get it in int format
        int num = digits[index]-'0';
      
      // now we find out the mapped chars for num and store it in string - s
        string s = map[num];

      
      // now for each char in s, we fix the char( s[i] ) by putting it in out,  and run recursion to get all its combination, 
      //and when when base case hits we get each possible combination of ( s[i] )  , then we come back, pop out the element from out and move on to next s[i] 
      
        for(int i=0;i<s.size();i++)
        {
            out.push_back(s[i]);
            solve(digits,out,ans,index+1,map);
            out.pop_back();
        }


    }


    vector<string> letterCombinations(string digits) {
        
      //create a vector of strings - ans and a string out
        vector<string> ans;
        string out;
      
      
      //base case -- if size is empty return empty string
        if(digits.size() == 0)
        {
            return ans;
        }

        // map the nos with the characters
        string map[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
      //take first number and function call
        int index=0;

        solve(digits,out,ans,index,map);

        return ans;






    }
};
