#include "Header.h"
using namespace std;
/*Heap Sort function*/
/*Binary Heap 使用MaxHeapify  BuildMaxHeap
Heap Sort
位置0沒有使用
*/
void swap(int &p1, int &p2) {
	int temp = p1;
	p1 = p2;
	p2 = temp;
	
}

void MaxHeapify(vector<int> &array, int root, int length) {

	int left = 2 * root;     //左子樹  根*2
	int right = 2 * root + 1;//右子數  根*2+1
	int largest;             //根 右 左 節點 ，找尋哪一個是最大值
	if (left <= length && array[left] > array[root])//如果左子樹沒有超出陣列範圍而且左子樹值大於根結點值
		largest = left;                             //最大值的位置存入左子樹
	else                                           
		largest = root;                              //最大值的位置存入根結點
	if (right <= length && array[right] > array[largest]) //如果右子樹沒有超出陣列範圍而且右子樹值大於目前最大值
		largest = right;                             //最大值的位置存入右節點
	if (largest != root) {                           //如果根不是最大值
 		swap(array[largest], array[root]);           //把最大值(value)換到根結點
		MaxHeapify(array, largest, length);          //遞迴檢查
	}
}

void BuildMaxHeap(vector<int> &array) {
	for (int i = (int)array.size() / 2;i >= 1;i--) {   //2點調整點為1  3點調整點為1  4點調整點為2 都是(當前總結點數/2)為需要調整的節點數量
		MaxHeapify(array, i, (int)array.size() - 1);   //輸出最後一個節點  長度減一
	}
}

void HeapSort(vector<int> &array) {
	array.insert(array.begin(), 0);  //在指定位置(begin)插入0

	BuildMaxHeap(array);             //array ->Max Heap
	 
	int size = (int)array.size() - 1;  //目前要處理的矩陣長度
	for (int i = (int)array.size() - 1;i >= 2;i--) {//
		swap(array[1], array[i]);   //最大值放到array最後一個位置
		size--;                     //尺寸減1
		MaxHeapify(array, 1, size); //最後一個值輸出，忽略陣列尾

	}
	array.erase(array.begin());     //將0刪除
}

void PrintArray(vector<int> &array) {
	for (int i = 0;i < array.size();i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}
///////////////////////////////////////////////////////////////////////////////
