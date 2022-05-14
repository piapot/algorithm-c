#include <gtest/gtest.h>

extern "C"
{
#include "data_structure/queue.h"
}

// 测试创建队列
TEST(QUEUE, CREATE)
{
    Queue *queue = queue_create(3);
    EXPECT_TRUE(queue != NULL);
    EXPECT_EQ(queue->capacity, 3);
    EXPECT_EQ(queue->size, 0);
    EXPECT_EQ(queue->front, -1);
    EXPECT_EQ(queue->rear, -1);
    queue_destroy(queue);
}

// 测试入队
TEST(QUEUE, ENQUEUE)
{
    Queue *queue = queue_create(3);

    queue_enqueue(queue, (void *)1);
    queue_enqueue(queue, (void *)2);
    queue_enqueue(queue, (void *)3);

    EXPECT_EQ(queue->size, 3);
    EXPECT_EQ(queue->front, -1);
    EXPECT_EQ(queue->rear, 2);

    queue_destroy(queue);
}

// 测试出队
TEST(QUEUE, DEQUEUE)
{
    Queue *queue = queue_create(3);

    queue_enqueue(queue, (void *)1);
    queue_enqueue(queue, (void *)2);
    queue_enqueue(queue, (void *)3);

    void *data = queue_dequeue(queue);
    EXPECT_EQ(data, (void *)1);
    EXPECT_EQ(queue->size, 2);
    EXPECT_EQ(queue->front, 0);
    EXPECT_EQ(queue->rear, 2);

    queue_destroy(queue);
}

// 测试获取队首元素
TEST(QUEUE, FRONT)
{
    Queue *queue = queue_create(3);

    queue_enqueue(queue, (void *)1);
    queue_enqueue(queue, (void *)2);
    queue_enqueue(queue, (void *)3);

    queue_dequeue(queue);

    void *data = queue_front(queue);
    EXPECT_EQ(data, (void *)2);
    EXPECT_EQ(queue->size, 2);
    EXPECT_EQ(queue->front, 0);
    EXPECT_EQ(queue->rear, 2);

    queue_destroy(queue);
}

// 测试获取队尾元素
TEST(QUEUE, REAR)
{
    Queue *queue = queue_create(3);

    queue_enqueue(queue, (void *)1);
    queue_enqueue(queue, (void *)2);
    queue_enqueue(queue, (void *)3);

    queue_dequeue(queue);

    void *data = queue_rear(queue);
    EXPECT_EQ(data, (void *)3);
    EXPECT_EQ(queue->size, 2);
    EXPECT_EQ(queue->front, 0);
    EXPECT_EQ(queue->rear, 2);

    queue_destroy(queue);
}

// 测试队列是否为空
TEST(QUEUE, IS_EMPTY)
{
    Queue *queue = queue_create(3);

    EXPECT_TRUE(queue_is_empty(queue));

    queue_enqueue(queue, (void *)1);
    EXPECT_FALSE(queue_is_empty(queue));

    queue_dequeue(queue);
    EXPECT_TRUE(queue_is_empty(queue));

    queue_destroy(queue);
}

// 测试队列是否已满
TEST(QUEUE, IS_FULL)
{
    Queue *queue = queue_create(3);

    EXPECT_FALSE(queue_is_full(queue));

    queue_enqueue(queue, (void *)1);
    queue_enqueue(queue, (void *)2);
    queue_enqueue(queue, (void *)3);
    EXPECT_TRUE(queue_is_full(queue));

    queue_dequeue(queue);
    queue_dequeue(queue);
    EXPECT_FALSE(queue_is_full(queue));

    queue_destroy(queue);
}
