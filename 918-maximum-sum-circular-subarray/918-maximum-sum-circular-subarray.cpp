class Solution {
    public:
    int maxSubarraySumCircular(vector<int> &A) {
        int nonCircularSum = kadaneMaxSum(A);
        int totalSum = 0;
        for(int i=0;i<A.size();i++){
            totalSum += A[i];
            A[i] = -A[i];
        }
              
        int circularSum = totalSum + kadaneMaxSum(A);
        if(circularSum == 0)
            return nonCircularSum;
        return max(circularSum,nonCircularSum);
    }
    
    int kadaneMaxSum(vector<int> &A){
        int currentSum = A[0];
        int maxSum = A[0];
        for(int i=1;i<A.size();i++){
            if(currentSum < 0)
                currentSum = 0;
            currentSum = A[i] + currentSum;
            maxSum = max(maxSum,currentSum);
        }
        return maxSum;
    }
};