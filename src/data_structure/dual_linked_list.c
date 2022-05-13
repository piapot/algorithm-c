#include "data_structure/dual_linked_list.h"

// 创建双向链表
DualLinkedList *dual_linked_list_create()
{
    DualLinkedList *list = (DualLinkedList *)malloc(sizeof(DualLinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

// 销毁双向链表
void dual_linked_list_destroy(DualLinkedList *list)
{
    DualLinkedListNode *node = list->head;
    while (node)
    {
        DualLinkedListNode *next = node->next;
        free(node);
        node = next;
    }
    free(list);
}

// 从双向链表头部插入节点
void dual_linked_list_insert_head(DualLinkedList *list, void *data)
{
    DualLinkedListNode *node = (DualLinkedListNode *)malloc(sizeof(DualLinkedListNode));
    node->data = data;
    node->prev = NULL;
    node->next = list->head;
    if (list->head)
    {
        list->head->prev = node;
    }
    list->head = node;
    if (list->tail == NULL)
    {
        list->tail = node;
    }
    list->size++;
}

// 从双向链表尾部插入节点
void dual_linked_list_insert_tail(DualLinkedList *list, void *data)
{
    DualLinkedListNode *node = (DualLinkedListNode *)malloc(sizeof(DualLinkedListNode));
    node->data = data;
    node->prev = list->tail;
    node->next = NULL;
    if (list->tail)
    {
        list->tail->next = node;
    }
    list->tail = node;
    if (list->head == NULL)
    {
        list->head = node;
    }
    list->size++;
}

// 从双向链表的指定位置插入节点
void dual_linked_list_insert(DualLinkedList *list, void *data, unsigned int index)
{
    if (index == 0)
    {
        dual_linked_list_insert_head(list, data);
    }
    else if (index == list->size)
    {
        dual_linked_list_insert_tail(list, data);
    }
    else
    {
        DualLinkedListNode *node = (DualLinkedListNode *)malloc(sizeof(DualLinkedListNode));
        node->data = data;
        DualLinkedListNode *prev = list->head;
        for (unsigned int i = 0; i < index; i++)
        {
            prev = prev->next;
        }
        node->prev = prev;
        node->next = prev->next;
        prev->next = node;
        node->next->prev = node;
        list->size++;
    }
}

// 从双向链表的指定位置删除节点
void dual_linked_list_remove(DualLinkedList *list, unsigned int index)
{
    if (index == 0)
    {
        DualLinkedListNode *node = list->head;
        list->head = node->next;
        if (list->head)
        {
            list->head->prev = NULL;
        }
        free(node);
        list->size--;
    }
    else if (index == list->size - 1)
    {
        DualLinkedListNode *node = list->tail;
        list->tail = node->prev;
        if (list->tail)
        {
            list->tail->next = NULL;
        }
        free(node);
        list->size--;
    }
    else
    {
        DualLinkedListNode *node = list->head;
        for (unsigned int i = 0; i < index; i++)
        {
            node = node->next;
        }
        node->prev->next = node->next;
        node->next->prev = node->prev;
        free(node);
        list->size--;
    }
}

// 从双向链表的指定位置获取节点
DualLinkedListNode *dual_linked_list_get(DualLinkedList *list, unsigned int index)
{
    DualLinkedListNode *node = list->head;
    for (unsigned int i = 0; i < index; i++)
    {
        node = node->next;
    }
    return node;
}

// 遍历双向链表
void dual_linked_list_foreach(DualLinkedList *list, void (*callback)(void *data))
{
    DualLinkedListNode *node = list->head;
    while (node)
    {
        callback(node->data);
        node = node->next;
    }
}
