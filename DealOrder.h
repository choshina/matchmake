#ifndef DEALORDER_H_
#define DEALORDER_H_

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class DealOrder{
private:
	static long did;
	long dealID;
	long buyID;
	long sellID;
	int quantity;
	DealOrder* next;
	
public:
	DealOrder(long,long,int);
	void setNext(DealOrder* n){next = n;}
	DealOrder* getNext(){return next;}
	string toString();	
};

#endif
