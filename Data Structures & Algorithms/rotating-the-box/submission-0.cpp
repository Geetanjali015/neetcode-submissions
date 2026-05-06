/*Instead of scanning rightward for each stone, we can use a two-pointer technique. Maintain a pointer i that tracks the rightmost available position for a stone. Scan from right to left: when we see a stone, swap it with position i and decrement i. When we see an obstacle, reset i to just before the obstacle. This avoids redundant scanning and processes each cell at most twice.*/
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int ROWS=boxGrid.size(),COLS=boxGrid[0].size();
        for(int r=0;r<ROWS;r++){
            int i=COLS-1;
            for(int c=COLS-1;c>=0;c--){
                if(boxGrid[r][c]=='#'){//stone
                   swap(boxGrid[r][c], boxGrid[r][i]);
                   i--;
                } 
                else if(boxGrid[r][c]=='*'){
                    i=c-1; // Stones cannot cross obstacle
                    // So restart available position
                    // to LEFT SIDE of obstacle
                }
                
            }
        }
        vector<vector<char>> res(COLS, vector<char>(ROWS)); //90 rotation
        for (int c = 0; c < COLS; ++c) {
            for (int r = ROWS - 1; r >= 0; --r) {
                res[c][ROWS - 1 - r] = boxGrid[r][c];
            }
        }
        return res;
    }
};