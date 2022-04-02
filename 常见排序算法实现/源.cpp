#include"So.h"

void Swap(int* a, int* b) {

	int temp = *a;
	*a = *b;
	*b = temp;
}
//��������
void InsertSort1(int* a, int n) {
	//��1��ʼ����ߵ����ǲ��ǱȺ�ߵĴ�
		for (int i = 1;i < n;i++) {
		int key = a[i];//����
		int j = i - 1;
		//�Ӻ���ǰ�ƶ�����ֱ��������keyС������
		while (j >= 0 && a[j] > key) {
			a[j + 1] = a[j];
			j--;
		}
		//�ҵ���keyС�����Ͳ������ĺ��
		a[j+1] = key;

	}


}
//����Ѱ�ұ���key�����
void InsertSort2(int* a, int n) {
	//��1��ʼ����ߵ����ǲ��ǱȺ�ߵĴ�
	for (int i = 1;i < n;i++) {
		int key = a[i];
		//ÿ�ζ���0��ʼѰ�ұ�key�������
		int k = 0;
		while (a[i] > a[k]) {
		
			k++;
		}
		//�ҵ�λ��Ϊk�����ֱ�key��
		//��k��k�ĺ�ߵ����ֶ����ƶ�һλ��key���뵽λ��k
		for (int j = i;j > k;j--) {
			a[j] = a[j - 1];
		}
		a[k] = key;
	}


}
//ѡ������
//ѡ��i��߱Ƚϵ�С�����͵�ǰ���ֽ���λ��
void SelectSort(int* a, int n) {
	for (int i = 0;i < n;i++) {
	
		int m = i;
		//�ҳ������������С��һ����
		for (int j = i+1;j < n;j++) {
			if (a[m] > a[j]) {
				
				m = j;
			}
		}
		Swap(&a[i], &a[m]);
	}


}
// ����ϣ������
void ShellSortMin(int* a, int n, int gap) {


	for (int i = 0;i < n - gap;i++) {
		int end = i;
		int temp = a[end + gap];
		//whileѭ��һֱ�����������ǲ�������һֱ��ÿ��һ��gap��Ҫ����ߵ������ǲ�������
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

//gap����  gapԽС���ݾ�Խ                  ����
void ShellSort(int* a, int n) {
	int s[3] = { 5,3,1 };
	for (int i = 0;i < 3;i++) {
		ShellSortMin(a, n, s[i]);
		
	}

}
// ��������ݹ�ʵ��
// ��������hoare�汾

/*
* ѡ���ұߵ�ֵ��ΪKey
* ��ôһ��������ߵ�λ��begin����
* �����ͱ�֤����������λ����һ����key���λ��
* �������ܴﵽ��߶�����С���ұ߶�������
* 
*ѡ����ߵ�ֵ��ΪKey
*  ͬ��Ҫ��end���ߣ�ԭ����һ����
* 
* 
* �ı���keyһ��Ҫ����һ������
* 
* 
* 
* ��������ʱ�临�Ӷ�����������ѡ����keyÿ�ζ���ѡ���Ķ��ǿ����м��ֵ��
* ���ǿ���ʱ�临�Ӷ��������ǽӽ��������ʱ��N*N��Ϊÿ��ѡ�Ĳ�����С��2ֵ��������ֵÿ��ֵ�����Ҫѭ��NN
* 
* 
* ����������֮ǰ�����ý����ұߵĺ�����ߵ�ֵ�������м��ֵ��һ������ȡ�У�����3������Ȣһ���м�ֵ��
* ���������ٳ���
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
//����ָ�뷨
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
* ���������ڿӷ����ǽ����һ���ֱ���ΪKey�ȴ�ͷ��ʼ�����ҵ���Key�������Ȼ�����ڵ�keyԭ����λ��
* �����ŴӺ�ʼ�ұ�keС�����־ͽ�������пӳ�
* 
* 
* 
* 
*/
// ���������ڿӷ�
int PartSort2(int* a, int left, int right) {
	int mid = Mid(a, left, right);
	Swap(&a[right], &a[mid]);
	int key = a[right];
	while (left<right){

			while (left < right && a[left] <= key) {
				left++;
			}
			//���ҵ���key�����־���ںõĿ�,left���γ�һ���µĿ�
			a[right] = a[left];
			while(left < right && a[right] >= key) {
				right--;
			
			}
			//���ҵ���key�����������µĿ��У�right���γ�һ���µĿ�
			a[left] = a[right];
	}
	//����󱣴����������һ������
	a[right] = key;
	return left;

}
/*
* curһֱ��ǰ��ֱ��������keyС�����֣�
* �Ͱ���prev++����λ�������һֱ�ѱ�keyС��������ǰ�ƶ����ѱ�key������������ƶ�
* һֱ��cur������right
* �����right��prev����λ�ã��ﵽǰ�߱�keyС��߱�key��
*/
// ��������ǰ��ָ�뷨
int PartSort3(int* a, int left, int right) {
	int prev = left-1;
	int cur = left ;
	int key = a[right];
	while (cur < right) {
		//ѭ���ұ�keyС������
		if(a[cur] < key&&prev!=cur) {
			Swap(&a[cur],&a[++prev]);
			
		}
		//�Ҵ�cur�ͺ�prerv++��λ�ý���λ��
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

	//С���䲻��ʹ�ÿ�������
	//��������ֻ�����������Ӵ�����
	//����������Сʱ���Ը������򷽷������������	
}


/*
* 
* �ݹ�÷ǵݹ� ----1ѭ��--һЩ�򵥵ĵݹ���ܸ�ѭ�� 2����ģ������ݷǵݹ�
* �ǵݹ飺1���ᷨЧ�ʣ��ݹ齨ջ֡���������ĵģ����Ƕ����ִ������������Ż�������΢����΢��
*			�ݹ����ȱ��������ջ֡���̫����ܾͻᵼ��ջ�������Ϊϵͳ�ռ�һ�㲻̫��M����
*			���ݽṹջģ��ǵݹ飬���ݴ洢�ڶ��ϣ�����G����Ŀռ�
* 
* 
*/
// �������� �ǵݹ�ʵ��
void QuickSortNonR(int* a, int left, int right) {
	stack<int> s;
	//��ջ
	s.push(right);
	s.push(left);
	while (!s.empty()) {
		//��ջ
		int begin = s.top();
		s.pop();
		int end = s.top();
		s.pop();
		int div = PartSort1(a, begin, end);
		//����ջ����������
	
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
//�鲢������һ��������
void _MergeSort(int *a,int left,int right,int *temp) {

	if (left >= right) {
		return;
		//�ݹ鵽���鳤��Ϊ1ֹͣ�ݹ飬ֱ�ӷ���
	}
	//�ֽ�
	int mid = (left + right) / 2;
	_MergeSort(a,left,mid,temp);
	_MergeSort(a, mid + 1, right, temp);


	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = begin1;

	//�ϲ�
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
	//�����ݿ�����ԭʼ�ռ�
	for (int i = left;i <=right;i++) {
		a[i] = temp[i];
	}
}
// �鲢����ݹ�ʵ��
void MergeSort(int* a, int n){
	assert(a);
	int* temp = (int*)malloc(sizeof(int) * n);
	_MergeSort(a, 0, n-1, temp);
}

// �鲢����ǵݹ�ʵ��----�ϲ�
void _MergeSortNonR(int *a,int begin1,int end1,int begin2,int end2,int *temp) {
	int left = begin1;
	int right = end2;
	int index = begin1;	
	//�ϲ�
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
	//�����ݿ�����ԭʼ�ռ�
	for (int i = left;i <= right;i++) {
		a[i] = temp[i];
	}
}
// �鲢����ǵݹ�ʵ��
void MergeSortNonR(int* a, int n) {

	assert(a);
	int* temp = (int*)malloc(sizeof(int) * n);
	int gap = 1;
	
	/*
	* �ϲ�ʱ������ݿ��ܻ���磬�����������1 �ڶ�������ֻ�в��֣���ǰһ�����ݲ�����֮�ϲ������Ǹ��������鷶Χ���������鷶Χ
	* ����Ҫ�����߽�
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
			//�ϲ�ʱֻ��һ�����ݣ��Ͳ���Ҫ�ϲ���û�еڶ��顣
			if (begin2 >=n) {
			
				break;
			}
			//�ϲ�ʱ�ڶ���ֻ�в������ݣ������ڷ���ʱ����ջ�����Ҫ�����߽�end2
			if (end2 >= n) {
				end2 = n - 1;
			
			}
			_MergeSortNonR(a, begin1, end1, begin2,end2, temp);
		}
		gap *= 2	;
	}
	
}
//�����ļ���10�ڸ�����-----������
//�鲢˼��
const  char* FileSort(const char*file) {
	FILE* fil = fopen(file, "w");
	if (file==NULL) {
		cout << "�ļ���ʧ��" << endl;
	}
	//���ļ�
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
			//��ȡ�ļ���������
			QuickSort(a, 0, 9);
			char* ss =NULL;
			sprintf(ss, " sub\\subfile% d", i);
			i++;
			//������õ�����д��С�ļ�
			FILE* subfile = fopen(ss, "w");
			if (subfile == NULL) {

				cout << "�ļ���ʧ��" << endl;
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
// ��������
void CountSort(int* a, int n) {
	assert(a);
	int min = a[0];
	int max = a[0];
	//�ҵ����������ֵ����Сֵ��Ϊ��ȷ����������Ĵ�С
	for (int i = 1;i < n;i++) {
		if (min > a[i]) {
			min = a[i];
		}
		if (max < a[i]) {
			max = a[i];
		}
	}
	int num = max - min +1;
	//��д������newn
	int* newn = new int [num] {0};
	for (int i = 0;i < n;i++) {
		newn[a[i] - min]++;
	}
	//�������鲢����
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