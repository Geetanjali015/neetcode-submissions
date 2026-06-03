class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0; 
        //i=writer, j=scanner
        int i=1; 
        for(int j=1;j<nums.size();j++){
            if(nums[j]!=nums[j-1]){ // 1 1 2 3 4 //2!=1
                nums[i]=nums[j]; //write value at pos j in pos i  // 1 2 2 3 4 // 2->1
                i++;// and inc i to nect element
            }
       }
        return i;
    }
};

//tc=o(n) , sc=o(1)
