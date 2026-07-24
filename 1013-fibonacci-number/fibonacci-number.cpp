class Solution {
public:
    int fibrec(int n){
        if(n==0) return 0;
        if(n==1) return 1;
        return fibrec(n-2) + fibrec(n-1);
    }
    int fib(int n) {
        return fibrec(n);
    }
};