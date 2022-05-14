#include <gtest/gtest.h>

extern "C"
{
#include "data_structure/stack.h"
}

// 测试创建栈
TEST(STACK, CREATE)
{
    Stack *stack = stack_create(3);
    EXPECT_TRUE(stack != NULL);
    EXPECT_EQ(stack->capacity, 3);
    EXPECT_EQ(stack->size, 0);
    EXPECT_EQ(stack->top, -1);
    stack_destroy(stack);
}

// 测试压栈
TEST(STACK, PUSH)
{
    Stack *stack = stack_create(3);

    stack_push(stack, (void *)1);
    EXPECT_EQ(stack->top, 0);
    EXPECT_EQ(stack->data[0], (void *)1);

    stack_push(stack, (void *)2);
    EXPECT_EQ(stack->top, 1);
    EXPECT_EQ(stack->data[0], (void *)1);
    EXPECT_EQ(stack->data[1], (void *)2);

    stack_push(stack, (void *)3);
    EXPECT_EQ(stack->top, 2);
    EXPECT_EQ(stack->data[0], (void *)1);
    EXPECT_EQ(stack->data[1], (void *)2);
    EXPECT_EQ(stack->data[2], (void *)3);

    stack_destroy(stack);
}

// 测试出栈
TEST(STACK, POP)
{
    Stack *stack = stack_create(3);

    stack_push(stack, (void *)1);
    stack_push(stack, (void *)2);
    stack_push(stack, (void *)3);

    void *data = stack_pop(stack);
    EXPECT_EQ(stack->top, 1);
    EXPECT_EQ(stack->data[0], (void *)1);
    EXPECT_EQ(stack->data[1], (void *)2);
    EXPECT_EQ(data, (void *)3);

    data = stack_pop(stack);
    EXPECT_EQ(stack->top, 0);
    EXPECT_EQ(stack->data[0], (void *)1);
    EXPECT_EQ(data, (void *)2);

    data = stack_pop(stack);
    EXPECT_EQ(stack->top, -1);
    EXPECT_EQ(data, (void *)1);

    stack_destroy(stack);
}

// 测试获取栈顶元素
TEST(STACK, TOP)
{
    Stack *stack = stack_create(3);

    stack_push(stack, (void *)1);
    stack_push(stack, (void *)2);
    stack_push(stack, (void *)3);

    void *data = stack_top(stack);
    EXPECT_EQ(stack->top, 2);
    EXPECT_EQ(stack->data[0], (void *)1);
    EXPECT_EQ(stack->data[1], (void *)2);
    EXPECT_EQ(stack->data[2], (void *)3);
    EXPECT_EQ(data, (void *)3);

    stack_destroy(stack);
}

// 测试栈是否为空
TEST(STACK, EMPTY)
{
    Stack *stack = stack_create(3);
    EXPECT_TRUE(stack_is_empty(stack));

    stack_push(stack, (void *)1);
    EXPECT_FALSE(stack_is_empty(stack));

    stack_pop(stack);
    EXPECT_TRUE(stack_is_empty(stack));

    stack_destroy(stack);
}

// 测试栈是否满
TEST(STACK, FULL)
{
    Stack *stack = stack_create(3);
    EXPECT_FALSE(stack_is_full(stack));

    stack_push(stack, (void *)1);
    stack_push(stack, (void *)2);
    stack_push(stack, (void *)3);
    EXPECT_TRUE(stack_is_full(stack));

    stack_pop(stack);
    EXPECT_FALSE(stack_is_full(stack));

    stack_destroy(stack);
}
