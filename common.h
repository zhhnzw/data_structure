#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#include<stdio.h>
#include<stdlib.h>
#define LIST_ELEM_SIZE 100  // 线性表存储空间的初始分配量
#define LIST_INCREMENT 10 // 线性表存储空间的分配增量

typedef int Status;
typedef int ElemType;