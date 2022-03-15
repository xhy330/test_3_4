### 关于输入缓存问题

```c
int ret = 0;
char passward[20] = { 0 };
printf("please enter the passward:>");
scanf_s("%s", passward);

printf("please confirm(Y/N):>");

ret = getchar();

if (ret == 'Y') {
    printf("success!\n");
}
else {
    printf("quit\n");
}
```

这段代码会直接输出“quit”，不是我们想要的结果，通过调试我们可以知道，在开始的时候，ret变量的值是10，通过查询我们可知这是‘\n’的ASKII码的值。 

也就是说，scanf读取一段字符串如123456后，我们还输入了一个回车，这个时候scanf读取就结束了。而这个回车则会被放在**输入缓存**中。然后执行到getchar()后，这个函数会去缓存中找有没有可用的值，回车就会被作为字符被getchar()读取，所以就会得到这样的结果。、



### 关于continue关键字

```c
int main() {

	int i = 1;

	while (i <= 10)
	{
		if(i == 5)
			continue;
		printf("%d ", i);
		i++;
	}

	return 0;
}
```

注意，这个输出结果是1 2 3 4 然后进入死循环。而不是 1 2 3 4 6 7 8 9 10。注意continue在while中是直接跳到while的表达式判断中去，而不会执行下面的代码，所以此时的i一直是等于5。



**对比for**

```c
int main() {

	int i = 0;

	for (i = 1; i <= 10; i++) {
		if(i == 5)
			continue;
		printf("%d ", i);
	}

	return 0;
}
```

这个代码的输出结果则是1 2 3 4 6 7 8 9 10。在遇见continue后，代码会之间跳到for的i++中，这个时候i发生改变了，所以i = 6可以继续执行代码。



### 对比while和for的循环

| while                              | for                                                          |
| ---------------------------------- | ------------------------------------------------------------ |
| 遇见continue后会直接跳到判断表达式 | for的流程是先进入判断exp2，然后执行循环体，再去exp3。遇见continue后，直接跳到exp3中进行i迭代。 |



### 关于for循环的变种

```c
int main(){
    
    int i = 0;
    int j = 0;
    
    for(; i < 10; i++){
        
        for(; j < 10; j++){
            
            printf("hehe\n");
        }
    }
    
    return 0;
}
```

这个输出的结果不是100个hehe，而是10个hehe。**一定要注意分析代码，不要单纯想代码！！！**在内层循环结束后，打印了10个hehe，此时的j从9变成了10，然后i=1进行第二次循环，此时的内层循环中**j=10，而不是0！**所以后续的循环都是j=10，不满足判断条件！



```c
int main(){
    
    int i = 0;
    int k = 0;
    for(i = 0, k = 0; k = 0; i++, k++)
        k++;
    return 0;
}
```

这个并不是死循环，一定要记住，**exp2的判断的值是整个表达式的值。**而k=0这个表达式的值就是k的值，所以它只循环零次。

### 字符串直接的比较不能使用 == 来判断

这个时候需要用strcmp()来实现字符串判断

| 0    | 两个字符串相等   |
| ---- | ---------------- |
| <0   | 后面的字符串更大 |
| >0   | 前面的字符串更大 |

### 关于递归的那些事

eg：求字符串的长度

```c
int my_strlen(char* str){
    
    int count = 0;
    while(*str != '\0')
    {
        count++;
        str++;
    }
    return count;
}
```

如果用递归来做呢

```c
int my_strlen(char *str){
    
    if(*str != '\0'){
        return 1 + my_strlen(*str+1);
    }
    else{
        return 0;
    }
}
```



### 数组

**数组的创建**

type_t	arr_name	[const_n];

注意[]里面一定是常量表达式，不能是变量



**存字符串的时候，注意末尾的\0也要存进去**

```c
char arr[] = "abcdef";
printf("%d \n", sizeof(arr));
printf("%d \n", strlen(arr));
```

第一个结果是7(该数组中有7个字符)，第二个是6(**遇见\0后停止记录**)



```c
char arr[] = {'a', 'b', 'c'};
printf("%d \n", strlen(arr));
```

这个输出的结果应该是一个随机值，因为strlen要遇见'\0'才会停止，所以它就会一直往后索引。



### 排序

```c
#include <stdio.h>

void bubble_sort(int arr[], int sz) {

	// 确定冒泡排序的趟数，10个数字则就是9趟，最后一个
	// 不用比较

	// 注意，数组传参的时候，传递的不是整个数组
	// 这个时候的数组名仅仅是首元素地址！不能计算整个数组
	// 的大小
	// int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < sz - 1; i++) {
		
		// 每一趟的冒泡排序
		// 其实说白了就是每一趟需要比较的对数
		for (int j = 0; j < sz - 1 - i; j++) {

			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


int main() {

	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz);

	for (int i = 0; i < sz; i++) {
		printf("%d ", arr[i]);
	}


	return 0;
}
```



### 详解数组名

数组名返回的是首元素地址，但是也有两个例外

> 1. sizeof(数组名)：表示整个数组 
>
> 2. &数组名：数组名代表整个数组

虽然结果是一样的，但是他们的意义不一样。除了这两种，其他的所有都是首元素地址。
