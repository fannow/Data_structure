#include"heap.h"


void swap(int *a,int *b) {
	int num = *a;
	*a = *b;
	*b = num;


}
//向上调整
void ShiftUp(int* a, int s, int child) {
	int parent = (child - 1) / 2;//找到child的父节点
	while (child>0) {
		
		if (a[child] < a[parent]) {
		//不符合小队规则
			//交换位置
			swap(a[child], a[parent]);
			//更新child,parent
			child = parent;
			child = (parent - 1) / 2;
		
		}
		else {
		//符合小堆规则
			break;
		
		}
	
	
	}


}
//向下调整
void ShiftDown(int* a, int s, int root) {
	int parent = root;
	int child = parent * 2 + 1;//左孩子
	while (child<s) {
		//找出左右孩子小的那一个
		//child+1<s是为了防止越界
		if (child+1	<s&&a[child+1] < a[child]) {
		//符合小堆的规则,继续寻找下一个孩子节点
			++child;
		}
		//不符合小堆的规则，交换位置
		if (a[child] < a[parent]) {
			swap(&a[child], &a[parent]);
			//向下更新child parent
			child = parent;
			parent = (child -1)/2;
		}
		else {
		//左右孩子都大于parent直接就跳出循环
			break;

		}
	
	}


}
//数组建堆----小堆满足左右子树都是小堆
void HeapCreate(Heap* hp, HPDataType* a, int n) {
	//首先申请空间
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	//将数据拷到堆空间中
	memcpy(hp->_a, a, sizeof(HPDataType)* n);
	hp->_capacity = n;
	hp->_size = n;
	//从最后一个最小子树开始调整为小堆，依次为向上的大子树调整，从倒数的第一个非叶子节点开始调整
	//开始构建堆
	for (int i = (n - 1 - 1) / 2;i >= 0;i--) {
		ShiftDown(hp->_a, hp->_size, i);//从最后一个非叶子节点开始调整
	
	}


}

void HeapDestory(Heap* hp) {
	assert(hp);
	free(hp->_a);
	hp->_size = hp->_capacity = 0;


}

// 堆的插入
void HeapPush(Heap* hp, HPDataType x) {
	if (hp->_size == hp->_capacity) {
		int num = hp->_capacity * 2;
		HPDataType *temp = (HPDataType*)realloc(hp->_a, sizeof(HPDataType) * num);
		
		hp->_a = temp;

	
	}
	hp->_a[hp->_size++] = x;
	//向上调整
	ShiftUp(hp->_a, hp->_size, hp->_size-1);//最后一个数据开始调整
}
void HeapSort(int *a,int size) {
	int n = size;
	//构建小堆
	for (int i = (size - 1 - 1) / 2;i >=0;i--) {
		//开始向下调整
		ShiftDown(a, size, i);
	
	}
	int end = n - 1;
	//堆排序
	//交换堆未数据和堆头数据
	while (end>0) {
		swap(&a[0], &a[end]);
		ShiftDown(a, end, 0);
		end--;
	}

}

// 堆的删除
void HeapPop(Heap* hp) {
	assert(hp);
	assert(hp->_size > 0);
	//首先将堆顶数据和1堆尾数据交换

	ShiftDown(hp->_a, hp->_size, 0);



}
// 取堆顶的数据
HPDataType HeapTop(Heap* hp) {
	assert(hp);
	assert(hp->_size > 0);
	
	int num = hp->_a[0];



	return num;

}
int main() {
	int a[10] = { 3,4,5,6,7,8,9,0 };
	Heap heap;

	HeapCreate(&heap, a, 8);
	for (int i = 0;i < 8;i++) {

		cout << heap._a[i] << " ";
	}
	cout << endl;
	cout << HeapTop(&heap) << endl;;

	for (int i = 0;i < 8;i++) {
	
		cout << heap._a[i] << " ";
	}

	
}

/*
tpok问题
N个数中找到最大或最小的前K个问题？？
1、首先想到是的先排序在取前k个但是时间复杂度最下也是N*logN，但是当N非常大时，无法内排序
2建K个数据的堆来解决？最大的前K个数
---->建小堆（来一个数只需让他和堆顶最小的数相比较，
比他大就需要替换堆顶数据，然后调整堆）




*/