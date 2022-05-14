#include "data_structure/queue.h"

// 创建队列
Queue *queue_create(unsigned int capacity)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if (queue == NULL)
    {
        return NULL;
    }
    queue->data = (void **)malloc(sizeof(void *) * capacity);
    if (queue->data == NULL)
    {
        free(queue);
        return NULL;
    }
    queue->front = -1;
    queue->rear = -1;
    queue->capacity = capacity;
    queue->size = 0;
    return queue;
}

// 销毁队列
void queue_destroy(Queue *queue)
{
    if (queue == NULL)
    {
        return;
    }
    free(queue->data);
    free(queue);
}

// 入队
void queue_enqueue(Queue *queue, void *data)
{
    if (queue == NULL)
    {
        return;
    }
    if (queue_is_full(queue))
    {
        return;
    }
    queue->rear++;
    queue->size++;
    queue->data[queue->rear] = data;
}

// 出队
void *queue_dequeue(Queue *queue)
{
    if (queue == NULL)
    {
        return NULL;
    }
    if (queue_is_empty(queue))
    {
        return NULL;
    }
    queue->front++;
    queue->size--;
    return queue->data[queue->front];
}

// 获取队首元素
void *queue_front(Queue *queue)
{
    if (queue == NULL)
    {
        return NULL;
    }
    if (queue_is_empty(queue))
    {
        return NULL;
    }
    return queue->data[queue->front + 1];
}

// 获取队尾元素
void *queue_rear(Queue *queue)
{
    if (queue == NULL)
    {
        return NULL;
    }
    if (queue_is_empty(queue))
    {
        return NULL;
    }
    return queue->data[queue->rear];
}

// 队列是否为空
int queue_is_empty(Queue *queue)
{
    if (queue == NULL)
    {
        return -1;
    }
    return queue->size == 0;
}

// 队列是否已满
int queue_is_full(Queue *queue)
{
    if (queue == NULL)
    {
        return -1;
    }
    return queue->size == queue->capacity;
}
