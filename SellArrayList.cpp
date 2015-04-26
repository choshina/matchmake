#include "SellArrayList.h"

SellArrayList::SellArrayList(double mp)
{
	pthread_mutex_init(&lock,NULL);
	orderList = new WaitItem*[20];
	for(int i = 0; i < 20; i++)
		orderList[i] = NULL;
	top = 0;
	minPrice = 5000;
	tick = 1;
}

void SellArrayList::add(Order* o)
{
//	pthread_mutex_lock(&lock);
	double np = o->getPrice();
	if(minPrice == 5000){
		WaitItem* wi = new WaitItem(np);
		wi->add(o);
		orderList[top] = wi;
		minPrice = np;
	}else if(np < minPrice){
		WaitItem* wi = new WaitItem(np);
		wi->add(o);
		int tmp = (20 + top - (int)((minPrice - np)/tick))%20;
		orderList[tmp] = wi;
		top = tmp;
		minPrice = np;
	}else if(np < minPrice + 20){
		int tmp = (top + ((int)((np - minPrice)/tick)))%20;
		if(orderList[tmp] == NULL){
			WaitItem* wi = new WaitItem(np);
			orderList[tmp] = wi;
		}
		orderList[tmp]->add(o);
	}else{

	}
//	pthread_mutex_unlock(&lock);
}

Order* SellArrayList::remove(Order* o)
{
	if(minPrice == 5000)
		return o;
//	pthread_mutex_lock(&lock);
	int i;
	Order* remain;
	int tmp = top;
	int end = (int)((o->getPrice()-minPrice)/tick);

	for(i = 0;i<=end;i++){
		tmp = (top + i)%20;
		if(orderList[tmp] == NULL)
			continue;
		remain = orderList[tmp]->remove(o);
		if(remain != NULL){
			orderList[tmp] = NULL;
		}else{
			if(orderList[tmp]->isNull()){
				orderList[tmp] = NULL;
			//	tmp = (tmp + 1)%20;
			}
			break;
		}
	}
//	if(i > end){
		for(;i<20;i++){
			if(orderList[(top+i)%20] != NULL){
				top = (top+i)%20;
				minPrice = orderList[top]->getPrice();
				break;
			}
		}
		if(i>=20){
			top = 0;
			minPrice = 5000;
		}
//	}else{
//		top = tmp;
///		minPrice = orderList[top]->getPrice();
//	}
//	pthread_mutex_unlock(&lock);
	return remain;
}

double SellArrayList::getMinPrice()
{
	return minPrice;
}

string SellArrayList::toString()
{
	string str = "";

	int t = top;
	for(int i=0;i<20;i++){
		if(orderList[t]!=NULL)
			str = str + orderList[t]->toString();
		t = (t+1)%20;
	}
	return str;
}
