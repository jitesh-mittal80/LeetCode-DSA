class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int h1 = INT_MIN;
        int h2 = INT_MIN;
        int c1 = -1;
        int c2 = -1;

        while(stones.size() > 1) {

            for(int i = 0; i < stones.size(); i++) {
                if(stones[i] >= h1) {
                    h2 = h1;
                    h1 = stones[i];

                    c2 = c1;
                    c1 = i;
                }
                else if(stones[i] > h2) {
                    h2 = stones[i];
                    c2 = i;
                }
            }

            if(h1 == h2) {
                if(c1 > c2) {
                    swap(stones[c1], stones.back());
                    stones.pop_back();

                    swap(stones[c2], stones.back());
                    stones.pop_back();
                }
                else {
                    swap(stones[c2], stones.back());
                    stones.pop_back();

                    swap(stones[c1], stones.back());
                    stones.pop_back();
                }
            }
            else {
                int diff = h1 - h2;

                if(c1 > c2) {
                    swap(stones[c1], stones.back());
                    stones.pop_back();

                    swap(stones[c2], stones.back());
                    stones.pop_back();
                }
                else {
                    swap(stones[c2], stones.back());
                    stones.pop_back();

                    swap(stones[c1], stones.back());
                    stones.pop_back();
                }

                stones.push_back(diff);
            }

            h1 = INT_MIN;
            h2 = INT_MIN;
            c1 = -1;
            c2 = -1;
        }

        return stones.empty() ? 0 : stones[0];
    }
};