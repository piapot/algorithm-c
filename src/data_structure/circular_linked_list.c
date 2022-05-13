#include "data_structure/circular_linked_list.h"

// 创建循环列表
CircularLinkedList *circular_linked_list_create()
{
    CircularLinkedList *list = (CircularLinkedList *)malloc(sizeof(CircularLinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

// 销毁循环列表
void circular_linked_list_destroy(CircularLinkedList *list)
{
    CircularLinkedListNode *node = list->head;
    while (node)
    {
        CircularLinkedListNode *next = node->next;
        free(node);
        node = next;
    }
    free(list);
}

// 从循环列表头部插入节点
void circular_linked_list_insert_head(CircularLinkedList *list, void *data)
{
    CircularLinkedListNode *node = (CircularLinkedListNode *)malloc(sizeof(CircularLinkedListNode));
    node->data = data;
    node->next = list->head;
    list->head = node;
    if (list->tail == NULL)
    {
        list->tail = node;
    }
    list->size++;
}

// 从循环列表尾部插入节点
void circular_linked_list_insert_tail(CircularLinkedList *list, void *data)
{
    CircularLinkedListNode *node = (CircularLinkedListNode *)malloc(sizeof(CircularLinkedListNode));
    node->data = data;
    node->next = NULL;
    if (list->tail == NULL)
    {
        list->head = node;
    }
    else
    {
        list->tail->next = node;
    }
    list->tail = node;
    list->size++;
}

// 从循环列表的指定位置插入节点
void circular_linked_list_insert(CircularLinkedList *list, void *data, unsigned int index)
{
    if (index == 0)
    {
        circular_linked_list_insert_head(list, data);
    }
    else if (index == list->size)
    {
        circular_linked_list_insert_tail(list, data);
    }
    else
    {
        CircularLinkedListNode *node = (CircularLinkedListNode *)malloc(sizeof(CircularLinkedListNode));
        node->data = data;
        CircularLinkedListNode *prev = list->head;
        for (unsigned int i = 0; i < index - 1; i++)
        {
            prev = prev->next;
        }
        node->next = prev->next;
        prev->next = node;
        list->size++;
    }
}

// 从循环列表的指定位置删除节点
void circular_linked_list_remove(CircularLinkedList *list, unsigned int index)
{
    if (index == 0)
    {
        list->head = list->head->next;
    }
    else if (index == list->size - 1)
    {
        CircularLinkedListNode *previous = list->head;
        for (unsigned int i = 0; i < index - 1; i++)
        {
            previous = previous->next;
        }
        list->tail = previous;
        list->tail->next = NULL;
    }
    else
    {
        CircularLinkedListNode *previous = list->head;
        for (unsigned int i = 0; i < index - 1; i++)
        {
            previous = previous->next;
        }
        previous->next = previous->next->next;
    }
    list->size--;
}

// 从循环列表的指定位置获取节点
CircularLinkedListNode *circular_linked_list_get(CircularLinkedList *list, unsigned int index)
{
    CircularLinkedListNode *node = list->head;
    for (unsigned int i = 0; i < index; i++)
    {
        node = node->next;
    }
    return node;
}
