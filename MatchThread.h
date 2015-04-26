#ifndef MATCHTHREAD_H_
#define MATCHTHREAD_H_

#include "BufferQueue.h"
#include "BuyArrayList.h"
#include "SellArrayList.h"
#include "MyThread.h"
#include <string>
#include <sstream>
#include <iostream>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;
#define LEN 100000

extern BufferQueue* bufferQueue;
extern BuyArrayList* bal;
extern SellArrayList* sal;


class MatchThread:public MyThread{
private:
//	Order* order;
	int length;
	long* rID;
	int* rb;
	int* rqu;
	double* rp;
public:
	MatchThread();
	void run();
	void result();
};

#endif
