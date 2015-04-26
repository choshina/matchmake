#ifndef BUYARRAYLIST_H_
#define BUYARRAYLIST_H_

#include "WaitItem.h"

class BuyArrayList{
private:
	WaitItem** orderList;
	double tick;
	int top;
	double maxPrice;
	pthread_mutex_t lock;
public:
	BuyArrayList(double mp);
	void add(Order* o);
	Order* remove(Order* o);
	double getMaxPrice();

	string toString();
};

#endif
