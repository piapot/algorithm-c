#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "__export.h"
#include <stdlib.h>

// 队列
typedef struct _Queue
{
    void **data;
    int front;
    int rear;
    unsigned int capacity;
    int size;
} Queue;

// 创建队列
__export Queue *queue_create(unsigned int capacity);

// 销毁队列
__export void queue_destroy(Queue *queue);

// 入队
__export void queue_enqueue(Queue *queue, void *data);

// 出队
__export void *queue_dequeue(Queue *queue);

// 获取队首元素
__export void *queue_front(Queue *queue);

// 获取队尾元素
__export void *queue_rear(Queue *queue);

// 队列是否为空
__export int queue_is_empty(Queue *queue);

// 队列是否已满
__export int queue_is_full(Queue *queue);

#endif // __QUEUE_H__
