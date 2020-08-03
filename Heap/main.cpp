#include <iostream>
#include <vector>
#include "Header.h"
using namespace std;


int main() {
	int  arr[] = {9,4,1,6,7,3,8,2,5};
	vector<int> array(arr, arr + sizeof(arr)/sizeof(int));
	//////////////////////////////////
	cout << "original:\n";
	PrintArray(array);

	HeapSort(array);
	cout << "sorted:\n";
	PrintArray(array);
	//////////////////////////////////
	system("pause");
	return 0;
	

}
