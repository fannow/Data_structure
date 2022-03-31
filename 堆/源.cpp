#include"heap.h"


void swap(int *a,int *b) {
	int num = *a;
	*a = *b;
	*b = num;


}
//���ϵ���
void ShiftUp(int* a, int s, int child) {
	int parent = (child - 1) / 2;//�ҵ�child�ĸ��ڵ�
	while (child>0) {
		
		if (a[child] < a[parent]) {
		//������С�ӹ���
			//����λ��
			swap(a[child], a[parent]);
			//����child,parent
			child = parent;
			child = (parent - 1) / 2;
		
		}
		else {
		//����С�ѹ���
			break;
		
		}
	
	
	}


}
//���µ���
void ShiftDown(int* a, int s, int root) {
	int parent = root;
	int child = parent * 2 + 1;//����
	while (child<s) {
		//�ҳ����Һ���С����һ��
		//child+1<s��Ϊ�˷�ֹԽ��
		if (child+1	<s&&a[child+1] < a[child]) {
		//����С�ѵĹ���,����Ѱ����һ�����ӽڵ�
			++child;
		}
		//������С�ѵĹ��򣬽���λ��
		if (a[child] < a[parent]) {
			swap(&a[child], &a[parent]);
			//���¸���child parent
			child = parent;
			parent = (child -1)/2;
		}
		else {
		//���Һ��Ӷ�����parentֱ�Ӿ�����ѭ��
			break;

		}
	
	}


}
//���齨��----С������������������С��
void HeapCreate(Heap* hp, HPDataType* a, int n) {
	//��������ռ�
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	//�����ݿ����ѿռ���
	memcpy(hp->_a, a, sizeof(HPDataType)* n);
	hp->_capacity = n;
	hp->_size = n;
	//�����һ����С������ʼ����ΪС�ѣ�����Ϊ���ϵĴ������������ӵ����ĵ�һ����Ҷ�ӽڵ㿪ʼ����
	//��ʼ������
	for (int i = (n - 1 - 1) / 2;i >= 0;i--) {
		ShiftDown(hp->_a, hp->_size, i);//�����һ����Ҷ�ӽڵ㿪ʼ����
	
	}


}

void HeapDestory(Heap* hp) {
	assert(hp);
	free(hp->_a);
	hp->_size = hp->_capacity = 0;


}

// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x) {
	if (hp->_size == hp->_capacity) {
		int num = hp->_capacity * 2;
		HPDataType *temp = (HPDataType*)realloc(hp->_a, sizeof(HPDataType) * num);
		
		hp->_a = temp;

	
	}
	hp->_a[hp->_size++] = x;
	//���ϵ���
	ShiftUp(hp->_a, hp->_size, hp->_size-1);//���һ�����ݿ�ʼ����
}
void HeapSort(int *a,int size) {
	int n = size;
	//����С��
	for (int i = (size - 1 - 1) / 2;i >=0;i--) {
		//��ʼ���µ���
		ShiftDown(a, size, i);
	
	}
	int end = n - 1;
	//������
	//������δ���ݺͶ�ͷ����
	while (end>0) {
		swap(&a[0], &a[end]);
		ShiftDown(a, end, 0);
		end--;
	}

}

// �ѵ�ɾ��
void HeapPop(Heap* hp) {
	assert(hp);
	assert(hp->_size > 0);
	//���Ƚ��Ѷ����ݺ�1��β���ݽ���

	ShiftDown(hp->_a, hp->_size, 0);



}
// ȡ�Ѷ�������
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
tpok����
N�������ҵ�������С��ǰK�����⣿��
1�������뵽�ǵ���������ȡǰk������ʱ�临�Ӷ�����Ҳ��N*logN�����ǵ�N�ǳ���ʱ���޷�������
2��K�����ݵĶ������������ǰK����
---->��С�ѣ���һ����ֻ�������ͶѶ���С������Ƚϣ�
���������Ҫ�滻�Ѷ����ݣ�Ȼ������ѣ�




*/