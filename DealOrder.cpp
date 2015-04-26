#include "DealOrder.h"

long DealOrder::did = -1;

DealOrder::DealOrder(long first,long second,int qu)
{
	did++;
	dealID = did;
	buyID = first;
	sellID = second;
	quantity = qu;
	next = NULL;
	
}

string DealOrder::toString()
{
	stringstream ss;
	ss<<"deal ID: "<<dealID<<" firstID: "<<buyID<<" secondID: "<<sellID
			<<" quantity:"<<quantity;
	return ss.str();
}
