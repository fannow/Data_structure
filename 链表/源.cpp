#include"List.h"
SListNode* BuySListNode(SLTDateType x) {
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	if (newnode == NULL) {
		cout << "�����ڵ�ʧ��" << endl;
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
void SListPrint(SListNode* plist) {
	SListNode* node = plist;
	while (node) {
		cout << node->data << "->";
		node = node->next;//ָ����һ���ڵ�
	}
	cout << endl;
}
// ������β��
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
		node->next =newnode ;//�����һ�ڵ����ӵ��½ڵ���
	}
}
//ͷ��
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
// �������βɾ
void SListPopBack(SListNode** pplist) {
	assert(*pplist);
	assert(pplist);
	//����ǲ���ֻʣһ��ֵ��
	if ((*pplist)->next==NULL) {
		//�ͷŽڵ�
		free(* pplist);	
		*pplist = NULL;
	}
	else {
		SListNode* node = *pplist;
		SListNode* newnode = node->next;
		while (newnode->next) {
			node = newnode;//�������һ���ڵ��ǰһ���ڵ�
			newnode = newnode->next;
		}
		free(newnode);
		newnode = NULL;
		//��λ�ڵ��ǰһ���ڵ���ΪNULL
		node->next = NULL;
	}


}
// ������ͷɾ
void SListPopFront(SListNode** pplist) {
	assert(*pplist);
	assert(pplist);
	//ֻʣһ���ڵ�ֱ���ͷ�
	if ((*pplist)->next == NULL) {
		//�ͷŽڵ�
		free(*pplist);
		*pplist = NULL;
	}
	else {
		SListNode* node = ( * pplist)->next;
		free(*pplist);
		*pplist = node;//��ͷ�ڵ����һ���ڵ�


	
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
//�ڵ���뵽pos֮��
void SListInsertAfter(SListNode* pos, SLTDateType x) {
	//Ϊ�ڵ�ֱ�Ӳ���
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
//ɾ��pos֮��Ľڵ�
void SListEraseAfter(SListNode* pos) {
	assert(pos->next);
	//�ж�ɾ���ڵ��ǲ���δ�ڵ�
	if (pos->next->next==NULL) {
		SListPopBack(&pos->next);//δɾ��
	}
	else {
		SListNode* node = pos->next;
		SListNode* newnode = node->next;
		free(node);
		node = NULL;
		pos->next = newnode;
	
	
	}


}
// ����˼��Ϊʲô����posλ��֮ǰ���룿
// ����˼��Ϊʲô��ɾ��posλ�ã�
//��Ϊû�л�ȡ��pos�ڵ�֮ǰ�Ľڵ�ɾ��pos�ڵ��޷���pos�ڵ�֮ǰ�Ľڵ��֮��Ľڵ����ӵģ��ᵼ��pos֮���һ������ʧ
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