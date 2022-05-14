#include "data_structure/stack.h"

// 创建栈
Stack *stack_create(unsigned int capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL)
    {
        return NULL;
    }
    stack->capacity = capacity;
    stack->size = 0;
    stack->top = -1;
    stack->data = (void **)malloc(sizeof(void *) * capacity);
    return stack;
}

// 销毁栈
void stack_destroy(Stack *stack)
{
    if (stack == NULL)
    {
        return;
    }
    free(stack->data);
    free(stack);
}

// 压栈
void stack_push(Stack *stack, void *data)
{
    if (stack == NULL)
    {
        return;
    }
    if (stack_is_full(stack))
    {
        return;
    }
    stack->top++;
    stack->data[stack->top] = data;
    stack->size++;
}

// 出栈
void *stack_pop(Stack *stack)
{
    if (stack == NULL)
    {
        return NULL;
    }
    if (stack_is_empty(stack))
    {
        return NULL;
    }
    void *data = stack->data[stack->top];
    stack->top--;
    stack->size--;
    return data;
}

// 获取栈顶元素
void *stack_top(Stack *stack)
{
    if (stack == NULL)
    {
        return NULL;
    }
    if (stack_is_empty(stack))
    {
        return NULL;
    }
    return stack->data[stack->top];
}

// 栈是否空
int stack_is_empty(Stack *stack)
{
    if (stack == NULL)
    {
        return 1;
    }
    return stack->size == 0;
}

// 栈是否满
int stack_is_full(Stack *stack)
{
    if (stack == NULL)
    {
        return 1;
    }
    return stack->size == stack->capacity;
}
