#ifndef BUFFERQUEUE_H_
#define BUFFERQUEUE_H_

#include <pthread.h>
#include "Order.h"

using namespace std;

class BufferQueue{
private:
	class BufferNode{
	public:
		Order* order;
		BufferNode* next;
		BufferNode(Order* o){
			order = o;
			next = NULL;
		}
	};
	pthread_mutex_t deqLock;
	BufferNode* head;
	BufferNode* tail;
	
public:
	BufferQueue();
	void enq(Order* o);
	Order* deq();
	bool empty();
};

#endif
