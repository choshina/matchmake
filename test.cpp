
#include "BuyArrayList.h"
#include "SellArrayList.h"
#include "ResultQueue.h"
#include "MatchThread.h"
#include "GenThread.h"
#include "MyThread.h"
#include "BufferQueue.h"
#include <sys/time.h>
#include <stdlib.h>
using namespace std;

BufferQueue* bufferQueue;
BuyArrayList* bal;
SellArrayList* sal;
ResultQueue* rq;

int main()
{

	bufferQueue = new BufferQueue();
	bal = new BuyArrayList(200);
	sal = new SellArrayList(201);
	rq = new ResultQueue();
	
	GenThread gt;
	gt.start();
	gt.join();


	MatchThread mt1;
//	MatchThread mt2;	
	mt1.start();
//	mt2.start();

	mt1.join();
//	mt2.join();

	

//	mt.result();	
	cout<<rq->toString()<<endl;
}
