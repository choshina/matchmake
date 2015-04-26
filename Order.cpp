#include "Order.h"

long Order::id = 0;

Order::Order(long aN,long sID,int bOS,int qu,double p)
{

//	pthread_mutex_init(&idlock,NULL);
//	pthread_mutex_lock(&idlock);
	id++;
//	pthread_mutex_unlock(&idlock);
	orderID = id;
	accountNumber = aN;
	securityID = sID;
	buyOrSell = bOS;
	quantity = qu;
	price = p;
}

string Order::toString()
{
	stringstream ss;
//	ss<<"account number:"<<accountNumber<<" securityID:"<<securityID
//		<<" buy or sell:"<<buyOrSell<<" quantity:"<<quantity
//		<<" price:"<<price;
	ss<<"ID :"<<orderID<<" bos "<<buyOrSell<<" quantity "<<quantity<<" price "<<price<<"  ";
	return ss.str();
}
