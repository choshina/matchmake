#ifndef RESULTQUEUE_H_
#define RESULTQUEUE_H_

#include <pthread.h>
#include "Order.h"
#include "DealOrder.h"

using namespace std;

class ResultQueue{
private:
	
	pthread_mutex_t enqLock;
	pthread_mutex_t deqLock;
	DealOrder* head;
	DealOrder* tail;

public:
	ResultQueue();
	void enq(DealOrder*);
	DealOrder* deq();
	string toString();	
};
#endif
