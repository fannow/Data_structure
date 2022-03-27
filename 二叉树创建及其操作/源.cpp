#include"BT.h"
// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
//ǰ�򹹽�������
BinaryTreeNode* BinaryTreeCreate(string s, int* num) {
	if (s[*num] == '#') {
		(*num)++;
		return NULL;
	}
	else {


		BinaryTreeNode* root = new BinaryTreeNode(s[*num]);
		(*num)++;
		//һ��һ�����¸�root�������ӽڵ㣬ֱ��sΪ�գ�ÿ�ε���#�������Ϸ���һ��
		root->_left = BinaryTreeCreate(s, num);
		root->_right = BinaryTreeCreate(s, num);
		return root;
	}

}


// ������ǰ�����
void BinaryTreePrevOrder(BTNode* root) {
	if (root == NULL) {

		return;
	}
	cout << root->_data << " ";
	BinaryTreePrevOrder(root->_left);
	
	BinaryTreePrevOrder(root->_right);
}
// �������������
void BinaryTreeInOrder(BTNode* root) {
	if (root == NULL) {
	
		return;
	}
	BinaryTreeInOrder(root->_left);
	cout << root->_data << " ";
	BinaryTreeInOrder(root->_right);
}

// �������������
void BinaryTreePostOrder(BTNode* root) {
	if (root == NULL) {
	
		return;
	}
	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	cout << root->_data << " ";
}

// �������ڵ��������һ  sizeΪ����Ͳ���
int BinaryTreeSize1(BTNode* root,int *size) {
	if (root == NULL) {
		return 0;
	}
	else {
		(*size)++;
	}

	BinaryTreeSize1(root->_left,size);
	BinaryTreeSize1(root->_right,size);

}


// �������ڵ����������
int BinaryTreeSize2(BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	//�ݹ鵽Ҷ�ӽڵ㣬Ȼ��һ��һ�ε����Ϸ���
	return 1 + BinaryTreeSize2(root->_left) + BinaryTreeSize2(root->_right);
}
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	//Ҷ�ӽڵ��child��ΪNULL
	if (root->_left == NULL && root->_right == NULL) {
		//����Ҷ�ӽڵ������
		return 1;
	}
	//��root������������Ѱ��һֱ�ݹ�ֱ������Ҷ�ӽڵ����������1
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);

}



// ����������
void BinaryTreeDestory(BTNode** root) {
	assert(root);
	if (*root == NULL) {
		return;
	}
	//�ݹ��ͷſռ�
	BinaryTreeDestory(&(*root)->_left);
	BinaryTreeDestory(&(*root)->_right);
	//�ݹ鵽Ҷ�ӽڵ��������ͷſռ䣬��Ҷ�ӽڵ㿪ʼ��Ϊ�˷�ֹ�ͷ�ʱparent�ڵ��Ҳ���child�ڵ�
	
	free(*root);
	*root = NULL;

}



// ��������k��ڵ����
/*
��ǰ���ĵ�K�����ת��Ϊ����ת��Ϊ���������ĵ�k-1��
����k==1ʱ������Ҫ�ٷֽ�
*/

int BinaryTreeLevelKSize(BTNode* root, int k) {
	if (root == NULL) {
		return 0;
	}

	if (k == 1) {
	//�����K��
		return 1;
	}
	/*
	�ݹ鵽��K�㣬��K���ж��ٽڵ�ͷ�����1�������㲻���������������µݹ�	��ֱ���ݹ鵽��K����������
	*/
	return BinaryTreeLevelKSize(root->_left,k-1) + BinaryTreeLevelKSize(root->_right,k-1);
}

// �������
/*
* �������е��Ƚ��ȳ�������ʵ��

*/
void BinaryTreeLevelOrder(BTNode* root) {
	queue<BTNode*> v;

	if (root == NULL) {
		return;
	}
	v.push(root);
	//ѭ���������в�Ϊ��
	while(!v.empty()) {
		//����
		BTNode* newnode = v.front();
		//ɾ����ͷ�ڵ�
		v.pop();
		cout << newnode->_data << " ";
		//���������ӽڵ�
		//����ʱ�ڵ���������ӽڵ�
		//���ҽڵ㲻ΪNULL
		if (newnode->_left) {
			v.push(newnode->_left);
		}
		if (newnode->_right) {
			v.push(newnode->_right);
		}
	}
}
// �ж϶������Ƿ�����ȫ������
bool BinaryTreeComplete(BTNode* root) {
	if (root == NULL) {
		return true;
	}
	queue<BTNode*> v;
	v.push(root);
	//ѭ���������в�Ϊ��
	BTNode* newnode=NULL;
	do {
		//����
		 newnode = v.front();
		v.pop();
		if (newnode == NULL) {
			break;
		}
		//���������ӽڵ�
		//����ʱ�ڵ���������ӽڵ�
		//���ҽڵ㲻ΪNULL
			v.push(newnode->_left);
			v.push(newnode->_right);
		
	} while (!v.empty() );
	while (!v.empty()) {
		//�������Ƿ���ڷǿսڵ�
		if (v.front()) {
			return false;
		
		}
		v.pop();
	
	}
	return true;
}
int main() {

	string a1 = "AB##D##";
	int a = 0;
	BTNode*node= BinaryTreeCreate(a1, &a);
	cout << "��ȫ��������" << BinaryTreeComplete(node) << endl;
	BinaryTreeLevelOrder(node);
	
	return 0;
}