#include "GenThread.h"

GenThread::GenThread()
	:MyThread()
{
	srand(time(NULL));
}

void GenThread::run()
{
	long aN,sID;
	int bOS,qu;
	double price;
	Order* order;

	long k = 0;
	while(k < LENGTH){
		aN = 0;
		sID = 0;
		bOS = rand()%2;
		qu = (rand()%20 + 1)*10;
		price = (bOS == 0?(203 - rand()%15):(196 + rand()%15));
		order = new Order(aN,sID,bOS,qu,price);
		
		bufferQueue->enq(order);
		k++;
	}
}
