test:test.o BuyArrayList.o SellArrayList.o BufferQueue.o ResultQueue.o GenThread.o MatchThread.o MyThread.o WaitItem.o DealOrder.o Order.o
	g++ -o test test.o BuyArrayList.o SellArrayList.o BufferQueue.o ResultQueue.o GenThread.o MatchThread.o MyThread.o WaitItem.o DealOrder.o Order.o -pthread -g
test.o:test.cpp BuyArrayList.h SellArrayList.h ResultQueue.h MatchThread.h
	g++ -o test.o -c test.cpp -g
Order.o:Order.h Order.cpp
	g++ -o Order.o -c Order.cpp -g
BufferQueue.o:BufferQueue.h BufferQueue.cpp Order.h
	g++ -o BufferQueue.o -c BufferQueue.cpp -g
ResultQueue.o:ResultQueue.h ResultQueue.cpp Order.h DealOrder.h
	g++ -o ResultQueue.o -c ResultQueue.cpp -g
BuyArrayList.o:BuyArrayList.h BuyArrayList.cpp WaitItem.h
	g++ -o BuyArrayList.o -c BuyArrayList.cpp -g
SellArrayList.o:SellArrayList.h SellArrayList.cpp WaitItem.h
	g++ -o SellArrayList.o -c SellArrayList.cpp -g
GenThread.o:GenThread.h GenThread.cpp MyThread.h
	g++ -o GenThread.o -c GenThread.cpp -g
MatchThread.o:MatchThread.h MatchThread.cpp MyThread.h
	g++ -o MatchThread.o -c MatchThread.cpp -g
#BufferQueue.o:BufferQueue.h BufferQueue.cpp Order.h
#	g++ -o BufferQueue.o -c BufferQueue.cpp -g
MyThread.o:MyThread.h MyThread.cpp
	g++ -o MyThread.o -c MyThread.cpp -g
DealOrder.o:DealOrder.h DealOrder.cpp Order.h
	g++ -o DealOrder.o -c DealOrder.cpp -g
WaitItem.o:WaitItem.h WaitItem.cpp Order.h
	g++ -o WaitItem.o -c WaitItem.cpp -g
#Order.o:Order.h Order.cpp
#	g++ -o Order.o -c Order.cpp
clean:
	rm *.o
