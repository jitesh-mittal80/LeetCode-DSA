class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int i = n;
        int odd = 1;
        int even = 2;
        int sumodd = 1;
        int sumeven = 2;
        n = n-1;
        while(n>0){
            even += 2;
            odd += 2;
            sumodd += odd;
            sumeven += even;
            n--;
        }

        return gcd(sumeven, sumodd);
    }
};