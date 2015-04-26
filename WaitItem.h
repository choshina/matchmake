#ifndef WAITITEM_H_
#define WAITITEM_H_

#include "Order.h"
#include "ResultQueue.h"

extern ResultQueue* rq;

class WaitItem{
private:
	class WaitOrder{
	public:
		Order* order;
		WaitOrder* next;
		WaitOrder(Order* o){
			order = o;
			next = NULL;
		}
	};	
	double price;
	WaitOrder* head;
	WaitOrder* tail;
	void recordDeal(long,long,int);
public:
	WaitItem(double p);
	void add(Order* o);
	
	Order* remove(Order* o);
	
	double getPrice(){return price;}
//	WaitOrder* getHead(){return head;}
//	WaitOrder* getTail(){return tail;}	
	bool isNull(){return head == tail;}	
	string toString();
};

#endif
