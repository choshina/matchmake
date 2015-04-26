#include "BuyArrayList.h"

BuyArrayList::BuyArrayList(double mp)
{
	orderList = new WaitItem*[20];
	for(int i =0;i<20;i++)
		orderList[i] = NULL;
	top = 0;
	maxPrice = -1;
	tick = 1;
	pthread_mutex_init(&lock,NULL);
}

void BuyArrayList::add(Order* o)
{
//	pthread_mutex_lock(&lock);
	double np = o->getPrice();
	if(maxPrice == -1){
		WaitItem* wi = new WaitItem(np);
		wi->add(o);
		orderList[top] = wi;
		maxPrice = np;
	}else if(np > maxPrice){
		WaitItem* wi = new WaitItem(np);
		wi->add(o);
		int tmp = (20 + top - (int)((np-maxPrice)/tick))%20;
		orderList[tmp] = wi;
		top = tmp;
		maxPrice = np;
	}else if(np > maxPrice - 20){
		int tmp = (top + ((int)((maxPrice - np)/tick)))%20;
		if(orderList[tmp]==NULL){
			WaitItem* wi = new WaitItem(np);
			orderList[tmp] = wi;
		}
		orderList[tmp]->add(o);
	}else{

	}
//	pthread_mutex_unlock(&lock);
}

Order* BuyArrayList::remove(Order* o)
{
	
	if(maxPrice == -1)
		return o;
//	pthread_mutex_lock(&lock);
	Order* remain;
	int tmp = top;
	double pri = o->getPrice();
	int end =(int)(maxPrice - pri)/tick;
	int i;
	
	
	for(i = 0; i<= end;i++){
		tmp = (top+i)%20;
		if(orderList[tmp] == NULL)
			continue;
		remain = orderList[tmp]->remove(o);
		if(remain !=NULL){
			orderList[tmp] = NULL;
			
		}else{
			if(orderList[tmp]->isNull())
			{
				orderList[tmp] = NULL;
//				tmp = (tmp+1)%20;
			}
			break;
		}
		
	}
//	if(i > end){
		for(;i<20;i++){
			if(orderList[(top + i)%20] != NULL ){
				top = (top+i)%20;
				maxPrice = orderList[top]->getPrice();
				break;		
			}
		}
		if(i>=20){
			top = 0;
			maxPrice = -1;
		}	
//	}else{
//		top = tmp;
//		maxPrice = orderList[top]->getPrice();
//	}
//	pthread_mutex_unlock(&lock);
	return remain;
}


double BuyArrayList::getMaxPrice()
{
	return maxPrice;
}

string BuyArrayList::toString()
{
	string str = "";

	int t = top;
	for(int i = 0;i < 20;i++){
		if(orderList[t]!=NULL)
			str = str + orderList[t]->toString();
		t = (t+1)%20;
	}
	return str;
}
