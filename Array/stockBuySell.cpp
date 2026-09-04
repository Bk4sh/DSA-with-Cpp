#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4, 10};
    int maxProfit = 0, bestBuy = prices[0];
    
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] > bestBuy) {
            maxProfit = max(maxProfit, prices[i] - bestBuy);
        }

        bestBuy = min(prices[i], bestBuy);
    }

    cout << "Maximum Profit " << maxProfit;
    return 0;
}