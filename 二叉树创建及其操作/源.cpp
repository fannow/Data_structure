#include"BT.h"
// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
//前序构建二叉树
BinaryTreeNode* BinaryTreeCreate(string s, int* num) {
	if (s[*num] == '#') {
		(*num)++;
		return NULL;
	}
	else {


		BinaryTreeNode* root = new BinaryTreeNode(s[*num]);
		(*num)++;
		//一层一层向下给root加左右子节点，直到s为空，每次到了#都会向上返回一层
		root->_left = BinaryTreeCreate(s, num);
		root->_right = BinaryTreeCreate(s, num);
		return root;
	}

}


// 二叉树前序遍历
void BinaryTreePrevOrder(BTNode* root) {
	if (root == NULL) {

		return;
	}
	cout << root->_data << " ";
	BinaryTreePrevOrder(root->_left);
	
	BinaryTreePrevOrder(root->_right);
}
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root) {
	if (root == NULL) {
	
		return;
	}
	BinaryTreeInOrder(root->_left);
	cout << root->_data << " ";
	BinaryTreeInOrder(root->_right);
}

// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root) {
	if (root == NULL) {
	
		return;
	}
	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	cout << root->_data << " ";
}

// 二叉树节点个数方法一  size为输出型参数
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


// 二叉树节点个数方法二
int BinaryTreeSize2(BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	//递归到叶子节点，然后一段一段的向上返回
	return 1 + BinaryTreeSize2(root->_left) + BinaryTreeSize2(root->_right);
}
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	//叶子节点的child都为NULL
	if (root->_left == NULL && root->_right == NULL) {
		//满足叶子节点的条件
		return 1;
	}
	//在root的左右子树都寻找一直递归直到满足叶子节点的条件返回1
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);

}



// 二叉树销毁
void BinaryTreeDestory(BTNode** root) {
	assert(root);
	if (*root == NULL) {
		return;
	}
	//递归释放空间
	BinaryTreeDestory(&(*root)->_left);
	BinaryTreeDestory(&(*root)->_right);
	//递归到叶子节点向上走释放空间，从叶子节点开始是为了防止释放时parent节点找不到child节点
	
	free(*root);
	*root = NULL;

}



// 二叉树第k层节点个数
/*
当前树的第K层可以转换为可以转换为左右子树的的k-1层
层数k==1时就像不需要再分解
*/

int BinaryTreeLevelKSize(BTNode* root, int k) {
	if (root == NULL) {
		return 0;
	}

	if (k == 1) {
	//到达第K层
		return 1;
	}
	/*
	递归到第K层，第K层有多少节点就返回少1，其他层不满足条件继续向下递归	，直到递归到第K层满足条件
	*/
	return BinaryTreeLevelKSize(root->_left,k-1) + BinaryTreeLevelKSize(root->_right,k-1);
}

// 层序遍历
/*
* 借助队列得先进先出的性质实现

*/
void BinaryTreeLevelOrder(BTNode* root) {
	queue<BTNode*> v;

	if (root == NULL) {
		return;
	}
	v.push(root);
	//循环条件队列不为空
	while(!v.empty()) {
		//出队
		BTNode* newnode = v.front();
		//删除对头节点
		v.pop();
		cout << newnode->_data << " ";
		//带进左右子节点
		//出队时节点带进左右子节点
		//左右节点不为NULL
		if (newnode->_left) {
			v.push(newnode->_left);
		}
		if (newnode->_right) {
			v.push(newnode->_right);
		}
	}
}
// 判断二叉树是否是完全二叉树
bool BinaryTreeComplete(BTNode* root) {
	if (root == NULL) {
		return true;
	}
	queue<BTNode*> v;
	v.push(root);
	//循环条件队列不为空
	BTNode* newnode=NULL;
	do {
		//出队
		 newnode = v.front();
		v.pop();
		if (newnode == NULL) {
			break;
		}
		//带进左右子节点
		//出队时节点带进左右子节点
		//左右节点不为NULL
			v.push(newnode->_left);
			v.push(newnode->_right);
		
	} while (!v.empty() );
	while (!v.empty()) {
		//队列中是否存在非空节点
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
	cout << "完全二叉树：" << BinaryTreeComplete(node) << endl;
	BinaryTreeLevelOrder(node);
	
	return 0;
}