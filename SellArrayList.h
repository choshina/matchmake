#ifndef SELLARRAYLIST_H_
#define SELLARRAYLIST_H_

#include "WaitItem.h"

class SellArrayList{
private:
	WaitItem** orderList;
	int top;
	double minPrice;
	double tick;
	pthread_mutex_t lock;
public:
	SellArrayList(double mp);
	void add(Order* o);
	Order* remove(Order* o);
	double getMinPrice();	
	
	string toString();
};


#endif
