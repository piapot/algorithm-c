#include "data_structure/linked_list.h"

// 创建单链表
LinkedList *linked_list_create()
{
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

// 销毁单链表
void linked_list_destroy(LinkedList *list)
{
    LinkedListNode *node = list->head;
    while (node)
    {
        LinkedListNode *next = node->next;
        free(node);
        node = next;
    }
    free(list);
}

// 从单链表头部插入节点
void linked_list_insert_head(LinkedList *list, void *data)
{
    LinkedListNode *node = (LinkedListNode *)malloc(sizeof(LinkedListNode));
    node->data = data;
    node->next = list->head;
    list->head = node;
    if (list->tail == NULL)
    {
        list->tail = node;
    }
    list->size++;
}

// 从单链表尾部插入节点
void linked_list_insert_tail(LinkedList *list, void *data)
{
    LinkedListNode *node = (LinkedListNode *)malloc(sizeof(LinkedListNode));
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

// 从单链表的指定位置插入节点
void linked_list_insert(LinkedList *list, void *data, unsigned int index)
{
    if (index == 0)
    {
        linked_list_insert_head(list, data);
    }
    else if (index == list->size)
    {
        linked_list_insert_tail(list, data);
    }
    else
    {
        LinkedListNode *node = list->head;
        for (unsigned int i = 0; i < index - 1; i++)
        {
            node = node->next;
        }
        LinkedListNode *next = node->next;
        LinkedListNode *new_node = (LinkedListNode *)malloc(sizeof(LinkedListNode));
        new_node->data = data;
        new_node->next = next;
        node->next = new_node;
        list->size++;
    }
}

// 从单链表的指定位置删除节点
void linked_list_remove(LinkedList *list, unsigned int index)
{
    if (index == 0)
    {
        LinkedListNode *node = list->head;
        list->head = node->next;
        free(node);
        list->size--;
    }
    else if (index == list->size - 1)
    {
        LinkedListNode *node = list->head;
        while (node->next->next)
        {
            node = node->next;
        }
        free(node->next);
        node->next = NULL;
        list->tail = node;
        list->size--;
    }
    else
    {
        LinkedListNode *node = list->head;
        for (unsigned int i = 0; i < index - 1; i++)
        {
            node = node->next;
        }
        LinkedListNode *next = node->next;
        node->next = next->next;
        free(next);
        list->size--;
    }
}

// 从单链表的指定位置获取节点
LinkedListNode *linked_list_get(LinkedList *list, unsigned int index)
{
    LinkedListNode *node = list->head;
    for (unsigned int i = 0; i < index; i++)
    {
        node = node->next;
    }
    return node;
}

// 遍历单链表
void linked_list_foreach(LinkedList *list, void (*callback)(void *data))
{
    LinkedListNode *node = list->head;
    while (node)
    {
        callback(node->data);
        node = node->next;
    }
}
