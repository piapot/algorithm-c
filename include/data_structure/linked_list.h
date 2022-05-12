#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include "__export.h"
#include <stdio.h>
#include <stdlib.h>

// 单链表节点
typedef struct _LinkedListNode
{
    void *data;
    struct _LinkedListNode *next;
} LinkedListNode;

//  单链表结构
typedef struct _LinkedList
{
    LinkedListNode *head;
    LinkedListNode *tail;
    unsigned int size;
} LinkedList;

// 创建单链表
__export LinkedList *linked_list_create();

// 销毁单链表
__export void linked_list_destroy(LinkedList *list);

// 在单链表头部插入节点
__export void linked_list_insert_head(LinkedList *list, void *data);

// 在单链表尾部插入节点
__export void linked_list_insert_tail(LinkedList *list, void *data);

// 在单链表指定位置插入节点
__export void linked_list_insert(LinkedList *list, void *data, unsigned int index);

// 删除单链表指定位置的节点
__export void linked_list_remove(LinkedList *list, unsigned int index);

// 获取单链表指定位置的节点
__export LinkedListNode *linked_list_get(LinkedList *list, unsigned int index);

#endif // __LINKED_LIST_H__
