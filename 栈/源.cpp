#include"stat.h"
// ��ʼ��ջ
void StackInit(Stack* ps) {
	assert(ps);

	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}

void StackPush(Stack* ps, STDataType data) {
	//ջ��������
	if (ps->_top == ps->_capacity) {
		STDataType new_capacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		ps->_a = (STDataType*)realloc(ps->_a,sizeof(STDataType)* new_capacity);//��ԭ���ռ�����

		ps->_capacity = new_capacity;
	}
	//��������
	ps->_a[ps->_top++] = data;
}
// ��ջ
void StackPop(Stack* ps) {
	assert(ps);
	//ջ������һλ
	ps->_top--;

}

// ��ȡջ��Ԫ��
STDataType StackTop(Stack* ps) {
	assert(ps);
	return ps->_a[ps->_top-1];

}
int StackEmpty(Stack* ps) {
	assert(ps);
	return ps->_top == 0?1:0;
}
// ��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps) {
	assert(ps);
	return ps->_top ;

}

// ����ջ
void StackDestroy(Stack* ps) {
	assert(ps);
	if (ps->_a) {
	
		free(ps->_a);
	}
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;

}

void Printf(Stack* ps) {
	while (!StackEmpty(ps)) {
		int s = StackTop(ps);
		cout <<s<<" ";
		StackPop(ps);

	}
	cout << endl;
}
void test() {
	Stack  ps;
	StackInit(&ps);
	StackPush(&ps, 1);
	StackPush(&ps, 2);
	StackPush(&ps, 3);
	StackPush(&ps, 4);
	StackPush(&ps, 5);
	StackPush(&ps, 6);
	while (StackEmpty(&ps) == 0)
	{
		printf("%-4d", StackTop(&ps));
		StackPop(&ps);
	}

}

int main() {
	test();
}