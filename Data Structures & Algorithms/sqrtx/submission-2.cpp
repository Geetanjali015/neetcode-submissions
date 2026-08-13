class Solution {
public:
    int pred(int m,int x){
        return (long long)m*m >x;
    }
    
    int mySqrt(int x) {
        
        int l=0;
        int r=x+1;
        while(r-l>1){
            int m=l+(r-l)/2;
            if(pred(m,x)==0)
                l=m;
            else
                r=m;

        }
        return l;

    }
};