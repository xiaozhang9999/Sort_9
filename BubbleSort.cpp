using namespace std;
#include<iostream>

template <typename T>
void swap(T data[], int i, int j) {
	T t = data[i];
	data[i] = data[j];
	data[j] = t;
}
template <typename T>
void bubbleSort(T data[], int length)
{
	for (int i = 0; i < length - 1; i++) {
		//data[n-i,n)���ź���
		//��data[0,n-i)����ð������,��data[n-i-1]λ�÷���Ӧ�õ�Ԫ��
		for (int j = 0; j <length-i-1 ; j++) {
			if (data[j] > data[j + 1])
				swap(data, j, j + 1);
		}
	}
}
//һ���Ż�
template <typename T>
void Sort1(T data[], int length)
{
	for (int i = 0; i < length - 1; i++) {
		//data[n-i,n)���ź���
		//��data[0,n-i)����ð������,��data[n-i-1]λ�÷���Ӧ�õ�Ԫ��
		bool isSwap = 0;//��Ϊÿһ���Ƿ���н������б�ֵ
		for (int j = 0; j < length - i - 1; j++) {
			if (data[j] > data[j + 1]) {
				swap(data, j, j + 1);
				isSwap = 1;//��������
			}	
		}
		if (isSwap == 0)//��δ��������˵�������ٽ�������
			break;
	}
}
//��һ���Ż�
template <typename T>
void Sort2(T data[], int length)
{
	for (int i = 0; i < length - 1;) {
		//data[n-i,n)���ź���
		//��data[0,n-i)����ð������,��data[n-i-1]λ�÷���Ӧ�õ�Ԫ��
		int lastswapindex = 0;//��¼ÿ�����һ�ν���������ֵ
		for (int j = 0; j < length - i - 1; j++) {
			if (data[j] > data[j + 1])	{
				swap(data, j, j + 1);
				lastswapindex = j + 1;//������¼����ֵ
			}
		}
		i = length - lastswapindex;//��ʱ�´�����ֻ��ִ�е�������ֵ
	}
}
//������ʽʵ�֣��Ӻ���ǰ����
template <typename T>
void OpbubbleSort(T data[], int length)
{
	for (int i = 0; i <length-1; i++) {
		//data[0,i)���ź���
		//��data[i,n)����ð������,��data[n-i-1]λ�÷���Ӧ�õ�Ԫ��
		for (int j = length -1; j >=i ; j--) {
			if (data[j] < data[j - 1])
				swap(data, j, j - 1);
		}
	}
}

int main()
{
	int data[] = { 5,3,6,8,2,9,0,1,7,4 };
	//bubbleSort(data, 10);
	//Sort1(data, 10);
	//Sort2(data, 10);
	OpbubbleSort(data, 10);
	for (int e:data)
		cout << e << " ";
	cout << endl;
}