#include"stat.h"
// 初始化栈
void StackInit(Stack* ps) {
	assert(ps);

	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}

void StackPush(Stack* ps, STDataType data) {
	//栈满了扩容
	if (ps->_top == ps->_capacity) {
		STDataType new_capacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		ps->_a = (STDataType*)realloc(ps->_a,sizeof(STDataType)* new_capacity);//在原来空间扩容

		ps->_capacity = new_capacity;
	}
	//插入数据
	ps->_a[ps->_top++] = data;
}
// 出栈
void StackPop(Stack* ps) {
	assert(ps);
	//栈顶后移一位
	ps->_top--;

}

// 获取栈顶元素
STDataType StackTop(Stack* ps) {
	assert(ps);
	return ps->_a[ps->_top-1];

}
int StackEmpty(Stack* ps) {
	assert(ps);
	return ps->_top == 0?1:0;
}
// 获取栈中有效元素个数
int StackSize(Stack* ps) {
	assert(ps);
	return ps->_top ;

}

// 销毁栈
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