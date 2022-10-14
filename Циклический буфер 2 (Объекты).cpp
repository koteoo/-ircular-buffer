// Циклический буфер

#include "pch.h"
#include <iostream>
using namespace std;
#define SIZE 5

class packet{
public:
	packet() = default;
	packet(int num, char *name):number(num),_name(name){}
	~packet() {
		cout << "Goodbye pack. " << endl;
	}
	void show_pack() {
		cout << "pack: " << _name << " number: " <<number << endl;
	}
	
private:
	int number = 0;
	char *_name;
};

class Buffer {
public:
	Buffer(){
		cout << "Default buffer's is started." << endl;
	}
	~Buffer();
	
	void put(int n, char *name);
	void show_buff();
	void buffer_size();

private:
	int general_amount_packets = 0;//Общее число прошедших пакетов через буфер
	int packets_amount = 0;
	packet *packets[SIZE]{nullptr};
};

Buffer::~Buffer() {
	cout << "Buffer's END." << endl;
	//deleting all packets
	for (int i = 0; i < SIZE; i++) {
		delete packets[i];
	}
}

void Buffer::put(int n, char *name) {
	
	general_amount_packets++;
	if (packets_amount < SIZE) {
		packets_amount++;
	}
	if (general_amount_packets > SIZE) {
		delete packets[SIZE-1];
		cout << packets[packets_amount - 1] << endl;
	}
	
	packet *p = new packet(n,name);

		for (int i = packets_amount-1; i > 0; i--) {

			packets[i] = packets[i - 1];

		}

		packets[0] = p;
	
}

void Buffer::show_buff() {
	cout <<"Count of complete packets at this moment: "<<packets_amount << endl;

	if (packets_amount != 0) {
		for (int i = 0; i < packets_amount; i++) {

			packets[i]->show_pack();

		}
	}

}

void Buffer::buffer_size() {
	cout << "packets_amount: " << packets_amount << endl;
	cout << "general_amount_packets: " << general_amount_packets << endl;
}

int main()
{
	Buffer one;
	
	char name[] = "John";
	//Кладем значения в буфер
	one.put(11, name);
	one.put(12, name);
	one.put(13, name);
	one.put(14, name);
	one.put(15, name);
	one.put(16, name);
	one.put(17, name);
	one.buffer_size();
	one.show_buff();

}

