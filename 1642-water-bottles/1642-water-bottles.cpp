class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalBottles = numBottles ; 
        int emptyBottles = numBottles ; 

        while(emptyBottles >= numExchange){
            totalBottles += emptyBottles / numExchange;
            emptyBottles = (emptyBottles / numExchange) + (emptyBottles % numExchange);
        }
    return totalBottles ;
    }
};