#include<stdio.h>
#include<stdlib.h>

void about_pointer(){
	/*
		指针不是地址, 指针是一种数据类型(作用是存储地址)
		为啥要设计指针这个类型？答: 让函数能够做到修改其他函数的变量, 做到数据共享
		如何做到数据共享？找到变量的地址-->改变此地址存储的值
		那为何不直接传递地址来操作？因为各个数据类型所占字节数不相同, 占用了一段连续的内存空间
		传递变量首地址, 读取期望的字节数来取出变量的值, 这就是指针这个类型的功能
	*/
	int i = 123;
    int* p = &i;  // int* 是指向整数的指针类型，p是该类型的变量，&i是赋于p的值
    printf("%p, %p\n", &i, p);  // &i是对i取址，生成一个int* 类型、指向i的指针
    printf("%d, %d\n", *p, i);  // i===*p是值, &i===p是指针
    printf("%p, %p\n", i, &i);  // %p 为指针类型输出其关联的地址, 那%p格式输出的i是什么玩意？？？
}

// 引用参数实现交换
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// 引用参数实现交换
void swap1(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main(){
	about_pointer();
	int a = 1, b = 2;
    swap(&a, &b);
    swap1(a, b);
    printf("%d %d\n",a,b);
}