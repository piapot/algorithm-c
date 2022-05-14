#ifndef __STACK_H__
#define __STACK_H__

#include "__export.h"
#include <stdlib.h>

// 栈
typedef struct _Stack
{
    void **data;
    unsigned int capacity;
    int size;
    int top;
} Stack;

// 创建栈
__export Stack *stack_create(unsigned int capacity);

// 销毁栈
__export void stack_destroy(Stack *stack);

// 压栈
__export void stack_push(Stack *stack, void *data);

// 出栈
__export void *stack_pop(Stack *stack);

// 获取栈顶元素
__export void *stack_top(Stack *stack);

// 栈是否为空
__export int stack_is_empty(Stack *stack);

// 栈是否已满
__export int stack_is_full(Stack *stack);

#endif // __STACK_H__
