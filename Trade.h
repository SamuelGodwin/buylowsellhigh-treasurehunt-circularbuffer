#ifndef TRADE_H
#define TRADE_H


#include "vector.h"
using pep::vector;


class Trade {
protected:
    int buyTime;
    int sellTime;

public:
    Trade(const int buyTimeIn, const int sellTimeIn)
        : buyTime(buyTimeIn), sellTime(sellTimeIn) {
    }

    int getBuyTime() const {
        return buyTime;
    }

    int getSellTime() const {
        return sellTime;
    }

    void setBuyTime(int buyTime1) {
    	buyTime = buyTime1; // ??
    }

    void setSellTime(int sellTime1) {
    	sellTime = sellTime1; // ??
    }

};

// GLOBAL function (outside of class)
Trade bestBuySellTime(vector<int> & prices) {
	int maxDifference = 0;
	Trade bestTimes(0,0);

	for(int iBuy = 0; iBuy < prices.size() - 1; iBuy++) {
		for (int iSell = iBuy + 1; iSell < prices.size(); iSell++) {
			// if difference larger than current maxDiff...
			if((prices[iSell] - prices[iBuy]) > maxDifference) {
				maxDifference = (prices[iSell] - prices[iBuy]);
				bestTimes.setBuyTime(iBuy);
				bestTimes.setSellTime(iSell);
			}
		}
	}
	return bestTimes;
}
#endif
