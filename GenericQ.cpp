#include <iostream>

using namespace std;
const int maxQsize = 100;

template <class Q> class Queue {
	Q array[maxQsize];
	int size;
	int putloc;
	int getloc;
public:
	Queue(int len) {
		if (len > 100) len = 100;
		else if (len <= 0) len = 1;
		size = len;
		putloc = 0;
		getloc = 0;
	}
	void put(Q val) {
		if (putloc == size) cout << "Queue is full";
		else { 
		putloc++; 
		array[putloc] = val;
		}
	}
	Q get() {
		if (getloc == putloc) {cout << "Queue is empty"; return 0;}
		else {
			getloc++;
			return array[getloc];
		}
	}
};

int main(){
	Queue <int> intQ(10);
	intQ.put(9);
	intQ.put(7);
	cout << intQ.get();
	cout << '\n';
	cout << intQ.get();
	cout << '\n';
	cout << intQ.get();//shows that empty
	cout << "\n\n";

	Queue <char> charQ(1);
	charQ.put('a');
	charQ.put('b');//shows that full
	cout << '\n';
	cout << charQ.get();
	cout << '\n';

return 0;
}