
#include "Header.h"
using namespace std;
/*Heap Sort function*/
/*Binary Heap �ϥ�MaxHeapify  BuildMaxHeap
Heap Sort
��m0�S���ϥ�
*/
void swap(int &p1, int &p2) {
	int temp = p1;
	p1 = p2;
	p2 = temp;
	
}

void MaxHeapify(vector<int> &array, int root, int length) {

	int left = 2 * root;     //���l��  ��*2
	int right = 2 * root + 1;//�k�l��  ��*2+1
	int largest;             //�� �k �� �`�I �A��M���@�ӬO�̤j��
	if (left <= length && array[left] > array[root])//�p�G���l��S���W�X�}�C�d��ӥB���l��Ȥj��ڵ��I��
		largest = left;                             //�̤j�Ȫ���m�s�J���l��
	else                                           
		largest = root;                              //�̤j�Ȫ���m�s�J�ڵ��I
	if (right <= length && array[right] > array[largest]) //�p�G�k�l��S���W�X�}�C�d��ӥB�k�l��Ȥj��ثe�̤j��
		largest = right;                             //�̤j�Ȫ���m�s�J�k�`�I
	if (largest != root) {                           //�p�G�ڤ��O�̤j��
 		swap(array[largest], array[root]);           //��̤j��(value)����ڵ��I
		MaxHeapify(array, largest, length);          //���j�ˬd
	}
}

void BuildMaxHeap(vector<int> &array) {
	for (int i = (int)array.size() / 2;i >= 1;i--) {   //2�I�վ��I��1  3�I�վ��I��1  4�I�վ��I��2 ���O(��e�`���I��/2)���ݭn�վ㪺�`�I�ƶq
		MaxHeapify(array, i, (int)array.size() - 1);   //��X�̫�@�Ӹ`�I  ���״�@
	}
}

void HeapSort(vector<int> &array) {
	array.insert(array.begin(), 0);  //�b���w��m(begin)���J0

	BuildMaxHeap(array);             //array ->Max Heap
	 
	int size = (int)array.size() - 1;  //�ثe�n�B�z���x�}����
	for (int i = (int)array.size() - 1;i >= 2;i--) {//
		swap(array[1], array[i]);   //�̤j�ȩ��array�̫�@�Ӧ�m
		size--;                     //�ؤo��1
		MaxHeapify(array, 1, size); //�̫�@�ӭȿ�X�A�����}�C��

	}
	array.erase(array.begin());     //�N0�R��
}

void PrintArray(vector<int> &array) {
	for (int i = 0;i < array.size();i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}
///////////////////////////////////////////////////////////////////////////////