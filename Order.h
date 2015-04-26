#ifndef ORDER_H_
#define ORDER_H_

#include <pthread.h>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

class Order{
private:
	static long id;
	long orderID;
	long accountNumber;
	long securityID;
	int buyOrSell;
	int quantity;
	double price;
//	pthread_mutex_t idlock;
public:
	Order(long,long,int,int,double);
	long getOrderID(){return orderID;}
	long getAccountNumber(){return accountNumber;}
	long getSecurityID(){return securityID;}
	int getBuyOrSell(){return buyOrSell;}
	int getQuantity(){return quantity;}
	double getPrice(){return price;}
	void setQuantity(double q){quantity = q;}
	
	string toString();
	
};


#endif
