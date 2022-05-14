#include "data_structure/stack.h"

// 创建栈
Stack *stack_create(unsigned int size)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->size = size;
    stack->top = -1;
    stack->data = (void **)malloc(sizeof(void *) * size);
    return stack;
}

// 销毁栈
void stack_destroy(Stack *stack)
{
    free(stack->data);
    free(stack);
}

// 压栈
void stack_push(Stack *stack, void *data)
{
    if (stack->top == stack->size - 1)
    {
        return;
    }
    stack->top++;
    stack->data[stack->top] = data;
}

// 出栈
void *stack_pop(Stack *stack)
{
    if (stack->top == -1)
    {
        return NULL;
    }
    void *data = stack->data[stack->top];
    stack->top--;
    return data;
}

// 获取栈顶元素
void *stack_top(Stack *stack)
{
    if (stack->top == -1)
    {
        return NULL;
    }
    return stack->data[stack->top];
}

// 栈是否空
int stack_is_empty(Stack *stack)
{
    return stack->top == -1;
}

// 栈是否满
int stack_is_full(Stack *stack)
{
    return stack->top == stack->size - 1;
}
