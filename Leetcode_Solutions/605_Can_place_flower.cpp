class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz = flowerbed.size();

        for (int i = 0; i < sz; i++) {  
            if (flowerbed[i] == 0) {    

                bool lft = false;
                if (i == 0 || flowerbed[i - 1] == 0)
                    lft = true;

                bool rgt = false;
                if (i == sz - 1 || flowerbed[i + 1] == 0)
                    rgt = true;

                if (lft && rgt) {
                    flowerbed[i] = 1;   
                    n--;               
                }
            }
        }
        return n <= 0;
    }
};
