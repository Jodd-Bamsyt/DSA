class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int start = 0 ; 
        int end  = 0 ; 
        int size = nums.size() ; 
        int count = 0 ; 
        int maxi = 0 ;

        while(end < size){
            if(nums[end] == 1){
                count ++;
                end ++;
                maxi = max(count  , maxi);
            }
            else{

                if(k > 0){
                    k --;
                    count ++;
                    maxi = max(count, maxi);
                    end++;
                }
                else{
                    while( nums[start] != 0 ){
                        start++;
                        count--;
                    }
                    start++;
                    count--;
                    k++;
                }
            }

        }
        return maxi;
        
    }
};