#include "MatchThread.h"

MatchThread::MatchThread()
	:MyThread()
{
//	length = leng;
	rID = new long[LEN];
	rb = new int[LEN];
	rqu = new int[LEN];
	rp = new double[LEN];
}

void MatchThread::run()
{
	Order* order;
	long aN ,sID;
	int bOS,qu;
	double price;
	
	int k = 0;
	while(true){
	
/*		aN = 0;
		sID = 0;
		bOS = rand()%2;

		rb[k] = bOS;
		qu = (rand()%20 + 1)*10;
		rqu[k] = qu;
		price = (bOS == 0?(203 - rand()%15):(196+rand()%15));
		rp[k] = price;
		order = new Order(aN,sID,bOS,qu,price);
		rID[k] = order->getOrderID();*/// generate order in this thread, not prepare it in advance

//generate thread in advance, storing in the bufferqueue
		if(bufferQueue->empty())
			break;
		order = bufferQueue->deq();
		
		double pri = order->getPrice();
		if(order->getBuyOrSell() == 0){
			if(pri>bal->getMaxPrice()&&pri>=sal->getMinPrice()){
				Order* ro = sal->remove(order);
				if(ro!=NULL)
					bal->add(ro);	
			}else{
				bal->add(order);
			}
			
		}else{
			if(pri<sal->getMinPrice()&&pri<=bal->getMaxPrice()){
				Order* ro = bal->remove(order);
				if(ro!=NULL)
					sal->add(ro);
			}else{
				sal->add(order);
			}
		}
		
//		k++;
	}
}


void MatchThread::result()
{
	for(int i = 0; i < length;i++){
		cout<<"orderID "<<rID[i]<<
			" buy or sell "<<rb[i]<<
			" quantity "<<rqu[i]<<
			" price "<<rp[i]<<endl;
	}
}
