class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        long long r = (long long)x + 1;

        while (r - l > 1) {
            long long m = l + (r - l) / 2;

            if (m * m <= x)
                l = m;
            else
                r = m;
        }

        return l;
    }
};