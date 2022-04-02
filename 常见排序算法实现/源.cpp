#include"So.h"

void Swap(int* a, int* b) {

	int temp = *a;
	*a = *b;
	*b = temp;
}
//插入排序
void InsertSort1(int* a, int n) {
	//从1开始检查后边的数是不是比后边的大
		for (int i = 1;i < n;i++) {
		int key = a[i];//保存
		int j = i - 1;
		//从后往前移动数据直到遇到比key小的数据
		while (j >= 0 && a[j] > key) {
			a[j + 1] = a[j];
			j--;
		}
		//找到比key小的数就插入他的后边
		a[j+1] = key;

	}


}
//正向寻找比他key大的数
void InsertSort2(int* a, int n) {
	//从1开始检查后边的数是不是比后边的大
	for (int i = 1;i < n;i++) {
		int key = a[i];
		//每次都从0开始寻找比key大的数字
		int k = 0;
		while (a[i] > a[k]) {
		
			k++;
		}
		//找到位置为k的数字比key大
		//将k和k的后边的数字都后移动一位将key插入到位置k
		for (int j = i;j > k;j--) {
			a[j] = a[j - 1];
		}
		a[k] = key;
	}


}
//选择排序
//选择i后边比较的小的数和当前数字交换位置
void SelectSort(int* a, int n) {
	for (int i = 0;i < n;i++) {
	
		int m = i;
		//找出后边数据中最小的一个数
		for (int j = i+1;j < n;j++) {
			if (a[m] > a[j]) {
				
				m = j;
			}
		}
		Swap(&a[i], &a[m]);
	}


}
// 单躺希尔排序
void ShellSortMin(int* a, int n, int gap) {


	for (int i = 0;i < n - gap;i++) {
		int end = i;
		int temp = a[end + gap];
		//while循环一直检查后续数据是不是有序一直将每加一个gap都要检查后边的数据是不是有序
		while (end >=0) {
			if (temp<a[end]) {
				a[end + gap] = a[end];
				end -= gap;
			}
			else {		
				break;
			}
		}
		a[end + gap] = temp;
	}
}

//gap减半  gap越小数据就越                  有序
void ShellSort(int* a, int n) {
	int s[3] = { 5,3,1 };
	for (int i = 0;i < 3;i++) {
		ShellSortMin(a, n, s[i]);
		
	}

}
// 快速排序递归实现
// 快速排序hoare版本

/*
* 选最右边的值作为Key
* 那么一定让最左边的位置begin先走
* 这样就保证他们相遇的位置是一个比key大的位置
* 这样才能达到左边都比他小，右边都比他大
* 
*选最左边的值作为Key
*  同样要让end先走，原因都是一样的
* 
* 
* 哪边做key一定要让另一边先走
* 
* 
* 
* 快速排序时间复杂度最好情况就是选定的key每次都会选定的都是靠经中间的值，
* 但是快排时间复杂读最坏情况就是接近有序最大时是N*N因为每次选的不是最小的2值就是最大的值每次值排序就要循环NN
* 
* 
* 所以在排序之前可以用将最右边的和最左边的值还加上中间的值做一个三数取中，再者3个数中娶一个中间值，
* 让最坏情况不再出现
* 
* 
* 
* 
*/

int Mid(int *a,int left,int right) {
	int mid = (left + right) / 2;
	if (a[mid] > a[left]) {
	
		if (a[left] > a[right]) {
			return left;
		}
		else if (a[right] > a[mid]) {
		
			return mid;
		}
		else {
		
			return right;
		}
	}
	else {
		//mid<left
		if (a[mid] > a[right]) {
		
			return mid;
		}
		else if(a[right]>a[left]) {
			return left;
		}
		else {
			return right;
		}
	}
	

}
//左右指针法
int PartSort1(int* a, int left, int right) {
	int mid = Mid(a, left,  right);
	Swap(&a[right], &a[mid]);
	int key = a[right];
	int begin = left;
	int end = right ;
	while (begin<end) {
		while (begin<end&&a[begin]<=key) {
			begin++;
		
		}
		while (begin < end && a[end] >= key) {
			end--;
		}
		Swap(&a[begin], &a[end]);
	}

	Swap(&a[begin], &a[right]);


	return begin;
}

/*
* 快速排序挖坑法就是将最后一数字保存为Key先从头开始首先找到比Key大的数字然后将它挖到key原来的位置
* ，接着从后开始找比ke小的数字就将数据填到有坑出
* 
* 
* 
* 
*/
// 快速排序挖坑法
int PartSort2(int* a, int left, int right) {
	int mid = Mid(a, left, right);
	Swap(&a[right], &a[mid]);
	int key = a[right];
	while (left<right){

			while (left < right && a[left] <= key) {
				left++;
			}
			//将找到比key的数字就填到挖好的坑,left就形成一个新的坑
			a[right] = a[left];
			while(left < right && a[right] >= key) {
				right--;
			
			}
			//将找到比key大的数据添道新的坑中，right就形成一个新的坑
			a[left] = a[right];
	}
	//将最后保存的数据填到最后一个坑中
	a[right] = key;
	return left;

}
/*
* cur一直往前走直到遇到比key小的数字，
* 就把他prev++交换位置这就像一直把比key小的数字往前移动，把比key大的数字往后移动
* 一直到cur到达了right
* 最后让right和prev交换位置，达到前边比key小后边比key大
*/
// 快速排序前后指针法
int PartSort3(int* a, int left, int right) {
	int prev = left-1;
	int cur = left ;
	int key = a[right];
	while (cur < right) {
		//循环找比key小的数字
		if(a[cur] < key&&prev!=cur) {
			Swap(&a[cur],&a[++prev]);
			
		}
		//找打cur就和prerv++的位置交换位置
	cur++;
	
	
	}

	Swap(&a[++prev] ,& a[cur]);
	return prev;

}
void QuickSort(int* a, int left, int right) {


	if (left > right) {
	
		return;
	}
	int div = PartSort2(a, left, right);
	QuickSort(a, left, div - 1);
	QuickSort(a, div + 1, right);

	//小区间不再使用快速排序
	//快速排序只适用数据量庞大的情况
	//在数据量很小时可以更改排序方法比如插入排序	
}


/*
* 
* 递归该非递归 ----1循环--一些简单的递归才能该循环 2、找模拟存数据非递归
* 非递归：1、提法效率（递归建栈帧还是有消耗的，但是对于现代计算机，这个优化可以是微乎其微的
*			递归最大缺点就是如果栈帧深度太深，可能就会导致栈溢出，因为系统空间一般不太在M级别
*			数据结构栈模拟非递归，数据存储在堆上，堆在G级别的空间
* 
* 
*/
// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right) {
	stack<int> s;
	//入栈
	s.push(right);
	s.push(left);
	while (!s.empty()) {
		//出栈
		int begin = s.top();
		s.pop();
		int end = s.top();
		s.pop();
		int div = PartSort1(a, begin, end);
		//借助栈来保存区间
	
		if (div + 1 < end) {
		
			s.push(end);
			s.push(div+1);
		}
		if (begin < div - 1) {
			s.push(div - 1);
			s.push(begin);
					
		}
	}
}
//归并排序是一个外排序
void _MergeSort(int *a,int left,int right,int *temp) {

	if (left >= right) {
		return;
		//递归到数组长度为1停止递归，直接返回
	}
	//分解
	int mid = (left + right) / 2;
	_MergeSort(a,left,mid,temp);
	_MergeSort(a, mid + 1, right, temp);


	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = begin1;

	//合并
	while (begin1 <= end1 && begin2 <=end2) {
		if (a[begin1] < a[begin2])
			temp[index++] = a[begin1++];
		else 
			temp[index++] = a[begin2++];
	}
	while (begin1<=end1) 
		temp[index++] = a[begin1++];
	while (begin2<=end2)
		temp[index++] = a[begin2++];
	//将数据拷贝到原始空间
	for (int i = left;i <=right;i++) {
		a[i] = temp[i];
	}
}
// 归并排序递归实现
void MergeSort(int* a, int n){
	assert(a);
	int* temp = (int*)malloc(sizeof(int) * n);
	_MergeSort(a, 0, n-1, temp);
}

// 归并排序非递归实现----合并
void _MergeSortNonR(int *a,int begin1,int end1,int begin2,int end2,int *temp) {
	int left = begin1;
	int right = end2;
	int index = begin1;	
	//合并
	while (begin1 <= end1 && begin2 <= end2) {
		if (a[begin1] < a[begin2])
			temp[index++] = a[begin1++];
		else
			temp[index++] = a[begin2++];
	}
	while (begin1 <= end1)
		temp[index++] = a[begin1++];
	while (begin2 <= end2)
		temp[index++] = a[begin2++];
	//将数据拷贝到原始空间
	for (int i = left;i <= right;i++) {
		a[i] = temp[i];
	}
}
// 归并排序非递归实现
void MergeSortNonR(int* a, int n) {

	assert(a);
	int* temp = (int*)malloc(sizeof(int) * n);
	int gap = 1;
	
	/*
	* 合并时后边数据可能会出界，出界情况包括1 第二组数据只有部分，和前一组数据不够与之合并，但是给出的数组范围超过了数组范围
	* 就需要修正边界
	* 
	* 
	* 
	*/
	while (gap < n) {
		for (int i = 0;i < n;i += 2 * gap) {
			int begin1 = i;
			int end1 = i + gap - 1;
			int begin2 = i + gap;
			int end2 = i + gap * 2 - 1;
			//合并时只有一组数据，就不需要合并，没有第二组。
			if (begin2 >=n) {
			
				break;
			}
			//合并时第二组只有部分数据，但是在放问时就有栈溢出，要修正边界end2
			if (end2 >= n) {
				end2 = n - 1;
			
			}
			_MergeSortNonR(a, begin1, end1, begin2,end2, temp);
		}
		gap *= 2	;
	}
	
}
//排序文件中10亿个数据-----外排序
//归并思想
const  char* FileSort(const char*file) {
	FILE* fil = fopen(file, "w");
	if (file==NULL) {
		cout << "文件打开失败" << endl;
	}
	//打开文件
	int a[10] = { 0 };
	int b = 10;
	int i = 0;
	int c = 0;
	int cc = 0;
	while (fscanf(fil, "%d\n", &c) != EOF) {
		if (c < 10) {
			a[cc] = c;
			cc++;
		}
		else {
			//读取文件接着排序
			QuickSort(a, 0, 9);
			char* ss =NULL;
			sprintf(ss, " sub\\subfile% d", i);
			i++;
			//将排序好的数据写回小文件
			FILE* subfile = fopen(ss, "w");
			if (subfile == NULL) {

				cout << "文件打开失败" << endl;
			}
			for (int i = 0;i < b;i++) {
				fprintf(subfile, "%d\n", a[i]);

			}
			fclose(subfile);
		}
	
	}
	fclose(fil);
	return NULL;
}
// 计数排序
void CountSort(int* a, int n) {
	assert(a);
	int min = a[0];
	int max = a[0];
	//找到数组中最大值和最小值是为了确定开辟数组的大小
	for (int i = 1;i < n;i++) {
		if (min > a[i]) {
			min = a[i];
		}
		if (max < a[i]) {
			max = a[i];
		}
	}
	int num = max - min +1;
	//填写·数组newn
	int* newn = new int [num] {0};
	for (int i = 0;i < n;i++) {
		newn[a[i] - min]++;
	}
	//回填数组并排序
	int nu = 0;
	int s = 0;
	for (int i = 0;i < num;i++) {
			while (newn[i]--) {
				a[nu++] = i;
			}
		
	}


}
void test() {
	srand(time(0));
	const int N = 10000000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
	}
	int begin1 = clock();
	QuickSort(a1, 0,N-1);
	int end1 = clock();

	cout << end1 - begin1 << endl;
}
int main() {
	//FileSort("1.txt");
	int a[9] = { 8,7,4,5,9,1,5,4,2};
	CountSort(a, 9);
	for (int i = 0;i <9;i++) {
	
		cout << a[i] << " ";
	}
	cout << endl;
	//InsertSort2(a, 10);
	//for (int i = 0;i < 10;i++) {

	//	cout << a[i] << " ";
	//}
	
	return 0;
}