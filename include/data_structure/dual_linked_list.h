#ifndef __DUAL_LINKED_LIST_H__
#define __DUAL_LINKED_LIST_H__

#include "__export.h"
#include <stdlib.h>

// 双向链表节点
typedef struct _DualLinkedListNode
{
    void *data;
    struct _DualLinkedListNode *prev;
    struct _DualLinkedListNode *next;
} DualLinkedListNode;

// 双向链表
typedef struct _DualLinkedList
{
    unsigned int size;
    DualLinkedListNode *head;
    DualLinkedListNode *tail;
} DualLinkedList;

// 创建双向链表
__export DualLinkedList *dual_linked_list_create();

// 销毁双向链表
__export void dual_linked_list_destroy(DualLinkedList *list);

// 从双向链表头部插入节点
__export void dual_linked_list_insert_head(DualLinkedList *list, void *data);

// 从双向链表尾部插入节点
__export void dual_linked_list_insert_tail(DualLinkedList *list, void *data);

// 从双向链表的指定位置插入节点
__export void dual_linked_list_insert(DualLinkedList *list, void *data, unsigned int index);

// 从双向链表的指定位置删除节点
__export void dual_linked_list_remove(DualLinkedList *list, unsigned int index);

// 从双向链表的指定位置获取节点
__export DualLinkedListNode *dual_linked_list_get(DualLinkedList *list, unsigned int index);

// 遍历双向链表
__export void dual_linked_list_foreach(DualLinkedList *list, void (*callback)(void *data));

#endif // __DUAL_LINKED_LIST_H__
