#include "BufferQueue.h"

BufferQueue::BufferQueue()
{
	pthread_mutex_init(&deqLock,NULL);
	head = new BufferNode(NULL);
	tail = head;
}

void BufferQueue::enq(Order* o)
{
	BufferNode* newNode = new BufferNode(o);
	tail->next = newNode;
	tail = newNode;
}

Order* BufferQueue::deq()
{
	Order* result;
	pthread_mutex_lock(&deqLock);
	result = head->next->order;
	head = head->next;
	pthread_mutex_unlock(&deqLock);
	return result;
}

bool BufferQueue::empty()
{
	return head==tail;
}
