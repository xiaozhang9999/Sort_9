# Sort_9


## 冒泡排序
### 简单实现
```c++
template <typename T>
void bubbleSort(T data[], int length)
{
	for (int i = 0; i < length - 1; i++) {
		//data[n-i,n)已排好序
		//对data[0,n-i)进行冒泡排序,在data[n-i-1]位置放置应该的元素
		for (int j = 0; j <length-i-1 ; j++) {
			if (data[j] > data[j + 1])
				swap(data, j, j + 1);
		}
	}
}
```

### 一种优化
```c++
template <typename T>
void Sort1(T data[], int length)
{
	for (int i = 0; i < length - 1; i++) {
		//data[n-i,n)已排好序
		//对data[0,n-i)进行冒泡排序,在data[n-i-1]位置放置应该的元素
		bool isSwap = 0;//作为每一轮是否进行交换的判别值
		for (int j = 0; j < length - i - 1; j++) {
			if (data[j] > data[j + 1]) {
				swap(data, j, j + 1);
				isSwap = 1;//发生交换
			}	
		}
		if (isSwap == 0)//若未发生交换说明无需再进行排序
			break;
	}
}
```
### 另一种优化
```c++
template <typename T>
void Sort2(T data[], int length)
{
	for (int i = 0; i < length - 1;) {
		//data[n-i,n)已排好序
		//对data[0,n-i)进行冒泡排序,在data[n-i-1]位置放置应该的元素
		int lastswapindex = 0;//记录每轮最后一次交换的索引值
		for (int j = 0; j < length - i - 1; j++) {
			if (data[j] > data[j + 1])	{
				swap(data, j, j + 1);
				lastswapindex = j + 1;//交换记录索引值
			}
		}
		i = length - lastswapindex;//此时下次排序只需执行到该索引值
	}
}
```
### 换个方式实现，从后往前排序
```c++
template <typename T>
void OpbubbleSort(T data[], int length)
{
	for (int i = 0; i <length-1; i++) {
		//data[0,i)已排好序
		//对data[i,n)进行冒泡排序,在data[n-i-1]位置放置应该的元素
		for (int j = length -1; j >=i ; j--) {
			if (data[j] < data[j - 1])
				swap(data, j, j - 1);
		}
	}
}
```
### 主函数测试
```c++
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
```
