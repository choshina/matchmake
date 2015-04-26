#include "ResultQueue.h"

ResultQueue::ResultQueue()
{
	pthread_mutex_init(&enqLock,NULL);
	pthread_mutex_init(&deqLock,NULL);
	head = new DealOrder(-1,-1,-1);
	tail = head;
}

void ResultQueue::enq(DealOrder* deo)
{
	pthread_mutex_lock(&enqLock);
	tail->setNext(deo);
	tail = deo;
	pthread_mutex_unlock(&enqLock);
}

DealOrder* ResultQueue::deq()
{
	DealOrder* result;
	pthread_mutex_lock(&deqLock);
	if(head->getNext()==NULL){
		pthread_mutex_unlock(&deqLock);
		return NULL;
	}
	result = head->getNext();
	head->setNext(head->getNext());
	pthread_mutex_unlock(&deqLock);
	return result;
}

string ResultQueue::toString()
{
	string str = "";
	DealOrder* p = head;
	while(p!=tail){
		str = str + p->getNext()->toString();
		str += "\n";
		p = p->getNext();	
	}
	return str;
}	
