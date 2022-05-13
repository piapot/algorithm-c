#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include "__export.h"
#include <stdlib.h>

// 单链表节点
typedef struct _LinkedListNode
{
    void *data;
    struct _LinkedListNode *next;
} LinkedListNode;

// 单链表
typedef struct _LinkedList
{
    unsigned int size;
    LinkedListNode *head;
    LinkedListNode *tail;
} LinkedList;

// 创建单链表
__export LinkedList *linked_list_create();

// 销毁单链表
__export void linked_list_destroy(LinkedList *list);

// 从单列表头部插入节点
__export void linked_list_insert_head(LinkedList *list, void *data);

// 从单列表尾部插入节点
__export void linked_list_insert_tail(LinkedList *list, void *data);

// 从单链表的指定位置插入节点
__export void linked_list_insert(LinkedList *list, void *data, unsigned int index);

// 从单链表的指定位置删除节点
__export void linked_list_remove(LinkedList *list, unsigned int index);

// 从单链表的指定位置获取节点
__export LinkedListNode *linked_list_get(LinkedList *list, unsigned int index);

#endif // __LINKED_LIST_H__
