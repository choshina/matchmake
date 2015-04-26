#include "WaitItem.h"

WaitItem::WaitItem(double p)
{
	price = p;
	WaitOrder* wo = new WaitOrder(NULL);
	head = wo;
	tail = head;
}

void WaitItem::add(Order* o)
{
	WaitOrder* wo = new WaitOrder(o);
	tail->next = wo;
	tail = wo;
}

Order* WaitItem::remove(Order* o)
{
	
	if(head == tail){
		return o;
	}else{
		int oqu = o->getQuantity();
		int thqu = head->next->order->getQuantity();
		if(oqu > thqu){
			recordDeal(head->next->order->getOrderID(),o->getOrderID(),thqu);
			o->setQuantity(oqu-thqu);
			head = head -> next;
			this->remove(o);
		}else if(oqu == thqu){
			recordDeal(head->next->order->getOrderID(),o->getOrderID(),oqu);
			head  = head->next;
			return NULL;
		}else{
			recordDeal(head->next->order->getOrderID(),o->getOrderID(),oqu);
			head->next->order->setQuantity(thqu-oqu);
			return NULL;
		}
	}
}

void WaitItem::recordDeal(long first,long second,int quan)
{
//	first->setQuantity(quan);
//	second->setQuantity(quan);
	
	DealOrder* ndo = new DealOrder(first,second,quan);
//	cout<<ndo->toString()<<endl;
	rq->enq(ndo);
}

string WaitItem::toString()
{
	WaitOrder* wo = head;
	string str = "";
	while(wo!=tail){
		str = str + wo->next->order->toString();
		wo = wo->next;
	}
	return str;
}
