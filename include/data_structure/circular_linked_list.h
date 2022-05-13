#ifndef __CIRCULAR_LINKED_LIST_H__
#define __CIRCULAR_LINKED_LIST_H__

#include "__export.h"
#include <stdlib.h>

// 循环列表节点
typedef struct _CircularLinkedListNode
{
    void *data;
    struct _CircularLinkedListNode *next;
} CircularLinkedListNode;

// 循环列表
typedef struct _CircularLinkedList
{
    unsigned int size;
    CircularLinkedListNode *head;
    CircularLinkedListNode *tail;
} CircularLinkedList;

// 创建循环列表
__export CircularLinkedList *circular_linked_list_create();

// 销毁循环列表
__export void circular_linked_list_destroy(CircularLinkedList *list);

// 从循环列表头部插入节点
__export void circular_linked_list_insert_head(CircularLinkedList *list, void *data);

// 从循环列表尾部插入节点
__export void circular_linked_list_insert_tail(CircularLinkedList *list, void *data);

// 从循环列表的指定位置插入节点
__export void circular_linked_list_insert(CircularLinkedList *list, void *data, unsigned int index);

// 从循环列表的指定位置删除节点
__export void circular_linked_list_remove(CircularLinkedList *list, unsigned int index);

// 从循环列表的指定位置获取节点
__export CircularLinkedListNode *circular_linked_list_get(CircularLinkedList *list, unsigned int index);

#endif // __CIRCULAR_LINKED_LIST_H__
