#include "common.h"

typedef struct{
	ElemType *elem;  //存储空间基址
	int length; // 当前长度
	int list_size; //当前分配的存储容量
} SqList;

SqList new_list(){
    SqList L = SqList();
	L.elem = (ElemType *)malloc(LIST_ELEM_SIZE*sizeof(ElemType));
    if(!L.elem){
        exit(OVERFLOW);
    }
    L.length = 0;
    L.list_size = LIST_ELEM_SIZE;
	return L;
}

Status insert_elem_to_list(SqList &L, int index, ElemType elem){
    ElemType *p = L.elem;
    printf("%d %d\n", index,L.length);
    for(int current_i=L.length-1;index<=current_i;current_i--){
        printf("%d\n", *(p+current_i));
        *(p+current_i+1) = *(p+current_i);
    }
    *(p+index) = elem;
    L.length ++;
    return OK;
}

Status delete_elem_to_list(SqList &L, int index){
    ElemType *p = L.elem;
    for(int current_i=index;current_i<=index<=L.length;current_i++){
        *(p+current_i) = *(p+current_i+1);
    }
    L.length--;
    // *(p+index) = elem;
    return OK;
}

int main(){
    SqList L = new_list();
    *L.elem = 1;
    *(L.elem+1) = 4;
    // printf("%s\n", "?");
    *(L.elem+2) = 3; //(1,null,3)
    L.length = 3;
    // printf("%s\n", "!");
    printf("%d %d %d\n", *L.elem, *(L.elem+1), *(L.elem+2));
    ElemType e = 2;
    insert_elem_to_list(L, 1, e); // (1,2,null,3)
    printf("%d %d %d %d\n", *L.elem, *(L.elem+1), *(L.elem+2), *(L.elem+3));
    insert_elem_to_list(L, 1, e); // (1,2,2,null,3)
    // null 在按%d打印出来时会变成0, %c啥也没有, %s是(null)
    printf("%d %d %d %d %d\n", *L.elem, *(L.elem+1), *(L.elem+2), *(L.elem+3), *(L.elem+4));
    delete_elem_to_list(L, 3); // (1,2,2,3)
    printf("%d %d %d %d\n", *L.elem, *(L.elem+1), *(L.elem+2), *(L.elem+3));
}