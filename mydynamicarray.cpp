#include <iostream>
using namespace std;

class MyDynamicArray {
	public:
		MyDynamicArray();
		MyDynamicArray(int s);
		~MyDynamicArray();
		int& operator[](int i);
		void add(int v);
		void del();
		int length();
		int clear();
		
	private:
		int size;
		int index;
		int *array;
		int ignore;
};

MyDynamicArray::MyDynamicArray() {
size = 2;
index = 0;
array = new int[size];


}

MyDynamicArray::MyDynamicArray(int s) {
size = s;
index = s;
array = new int[size];


}

MyDynamicArray::~MyDynamicArray() {
delete [] array;
}

int& MyDynamicArray::operator[] (int i) {

	if (i >= index) {
	cout << "Out of bounds reference : " << i << endl;
	return ignore;
	}
return array[i];
}

void MyDynamicArray::add(int v) {
	int *arrayNew;
	if (index == size) {
cout << "Doubling to : " << size * 2 << endl;
		size = size * 2;
		arrayNew = new int[size];
	for (int x = 0; x < index; x++)
		arrayNew[x] = array[x];
delete [] array;
array = arrayNew;
}
	array[index++] = v;
}

void MyDynamicArray::del() {

int *arrayNew;
if (index < size / 4){
	cout << "Reducing to : " << size / 2 << endl;
	size = size / 2;
		arrayNew = new int[size];
	for (int x = 0; x < index; x++)
		arrayNew[x] = array[x];
	delete [] array;
	array = arrayNew;
}
index--;

}

int MyDynamicArray::length() {
return index;
}

int MyDynamicArray::clear() {
delete [] array;
size = 2;
index = 0;
return index;
}




