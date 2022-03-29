#include"List.h"
SListNode* BuySListNode(SLTDateType x) {
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	if (newnode == NULL) {
		cout << "创建节点失败" << endl;
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
void SListPrint(SListNode* plist) {
	SListNode* node = plist;
	while (node) {
		cout << node->data << "->";
		node = node->next;//指向下一个节点
	}
	cout << endl;
}
// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x) {
	
	if (*pplist == NULL) {
		SListNode* newnode = BuySListNode(x);
		*pplist = newnode;
	}
	else {
		SListNode* node = *pplist;
		while (node->next) {
			node = node->next;
		}

		SListNode* newnode = BuySListNode(x);
		node->next =newnode ;//将组后一节点连接到新节点上
	}
}
//头查
void SListPushFront(SListNode** pplist, SLTDateType x) {

	if (*pplist == NULL) {
		SListNode* newnode = BuySListNode(x);
		*pplist = newnode;
	}
	else {
		SListNode* newnode = BuySListNode(x);
		newnode->next = *pplist;
		*pplist = newnode;

	}


}
// 单链表的尾删
void SListPopBack(SListNode** pplist) {
	assert(*pplist);
	assert(pplist);
	//检查是不是只剩一个值了
	if ((*pplist)->next==NULL) {
		//释放节点
		free(* pplist);	
		*pplist = NULL;
	}
	else {
		SListNode* node = *pplist;
		SListNode* newnode = node->next;
		while (newnode->next) {
			node = newnode;//保存最后一个节点的前一个节点
			newnode = newnode->next;
		}
		free(newnode);
		newnode = NULL;
		//将位节点的前一个节点置为NULL
		node->next = NULL;
	}


}
// 单链表头删
void SListPopFront(SListNode** pplist) {
	assert(*pplist);
	assert(pplist);
	//只剩一个节点直接释放
	if ((*pplist)->next == NULL) {
		//释放节点
		free(*pplist);
		*pplist = NULL;
	}
	else {
		SListNode* node = ( * pplist)->next;
		free(*pplist);
		*pplist = node;//将头节点的下一个节点


	
	}

}
SListNode* SListFind(SListNode* plist, SLTDateType x) {
	SListNode* node = plist;
	while (node) {
		if (node->data == x) {
			return node;
		}
		node = node->next;
	}

	return NULL;

}
//节点插入到pos之后
void SListInsertAfter(SListNode* pos, SLTDateType x) {
	//为节点直接插入
	if(pos->next == NULL) {
		SListPushBack(&pos,x);
	
	}
	else {
		SListNode* node = pos;
		SListNode*lnode = node->next;
		SListNode* newnode = BuySListNode(x);
		node->next = newnode;
		newnode->next = lnode;
	}


}
//删除pos之后的节点
void SListEraseAfter(SListNode* pos) {
	assert(pos->next);
	//判断删除节点是不是未节点
	if (pos->next->next==NULL) {
		SListPopBack(&pos->next);//未删除
	}
	else {
		SListNode* node = pos->next;
		SListNode* newnode = node->next;
		free(node);
		node = NULL;
		pos->next = newnode;
	
	
	}


}
// 分析思考为什么不在pos位置之前插入？
// 分析思考为什么不删除pos位置？
//因为没有获取到pos节点之前的节点删除pos节点无法将pos节点之前的节点和之后的节点连接的，会导致pos之后的一段链表丢失
void test() {
	SListNode* plist=NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);
	SListPushBack(&plist, 6);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPrint(plist);
	SListEraseAfter(SListFind(plist,4 ));
	SListPrint(plist);

}
int main() {
	test();

}