#ifndef GENTHREAD_H_
#define GENTHREAD_H_
#include "MyThread.h"
#include "BufferQueue.h"
#include <sys/time.h>
#include <stdlib.h>
#include "Order.h"

#define LENGTH 100000
extern BufferQueue* bufferQueue;

class GenThread:public MyThread{
private:
	
public:
	GenThread();
	void run();	
};

#endif
