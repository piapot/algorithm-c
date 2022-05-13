#include <gtest/gtest.h>

extern "C"
{
#include <stdlib.h>
#include "data_structure/circular_linked_list.h"
}

// 测试创建循环链表
TEST(CIRCULAR_LINKED_LIST, CREATE)
{
    CircularLinkedList *circular_linked_list = circular_linked_list_create();
    EXPECT_TRUE(circular_linked_list->head == NULL);
    EXPECT_TRUE(circular_linked_list->tail == NULL);
    EXPECT_EQ(circular_linked_list->size, 0);
    circular_linked_list_destroy(circular_linked_list);
}

// 测试在循环链表头部插入节点
TEST(CIRCULAR_LINKED_LIST, INSERT_HEAD)
{
    CircularLinkedList *circular_linked_list = circular_linked_list_create();
    circular_linked_list_insert_head(circular_linked_list, (void *)1);
    EXPECT_EQ(circular_linked_list->size, 1);
    EXPECT_TRUE(circular_linked_list->head != NULL);
    EXPECT_TRUE(circular_linked_list->tail != NULL);
    EXPECT_EQ(circular_linked_list->head->data, (void *)1);
    EXPECT_EQ(circular_linked_list->tail->data, (void *)1);
    circular_linked_list_destroy(circular_linked_list);
}

// 测试在循环链表尾部插入节点
TEST(CIRCULAR_LINKED_LIST, INSERT_TAIL)
{
    CircularLinkedList *circular_linked_list = circular_linked_list_create();
    circular_linked_list_insert_tail(circular_linked_list, (void *)1);
    EXPECT_EQ(circular_linked_list->size, 1);
    EXPECT_TRUE(circular_linked_list->head != NULL);
    EXPECT_TRUE(circular_linked_list->tail != NULL);
    EXPECT_EQ(circular_linked_list->head->data, (void *)1);
    EXPECT_EQ(circular_linked_list->tail->data, (void *)1);
    circular_linked_list_destroy(circular_linked_list);
}

// 测试在循环链表指定位置插入节点
TEST(CIRCULAR_LINKED_LIST, INSERT)
{
    CircularLinkedList *circular_linked_list = circular_linked_list_create();
    circular_linked_list_insert(circular_linked_list, (void *)1, 0);
    EXPECT_EQ(circular_linked_list->size, 1);
    EXPECT_TRUE(circular_linked_list->head != NULL);
    EXPECT_TRUE(circular_linked_list->tail != NULL);
    EXPECT_EQ(circular_linked_list->head->data, (void *)1);
    EXPECT_EQ(circular_linked_list->tail->data, (void *)1);
    circular_linked_list_destroy(circular_linked_list);
}

// 测试删除循环链表指定位置的节点
TEST(CIRCULAR_LINKED_LIST, REMOVE)
{
    CircularLinkedList *circular_linked_list = circular_linked_list_create();
    circular_linked_list_insert(circular_linked_list, (void *)1, 0);
    circular_linked_list_insert(circular_linked_list, (void *)2, 1);
    circular_linked_list_remove(circular_linked_list, 0);
    EXPECT_EQ(circular_linked_list->head->data, (void *)2);
    circular_linked_list_destroy(circular_linked_list);
}

// 测试获取循环链表指定位置的节点
TEST(CIRCULAR_LINKED_LIST, GET)
{
    CircularLinkedList *circular_linked_list = circular_linked_list_create();
    circular_linked_list_insert(circular_linked_list, (void *)1, 0);
    circular_linked_list_insert(circular_linked_list, (void *)2, 1);
    circular_linked_list_insert(circular_linked_list, (void *)3, 2);
    EXPECT_EQ(circular_linked_list_get(circular_linked_list, 0)->data, (void *)1);
    EXPECT_EQ(circular_linked_list_get(circular_linked_list, 1)->data, (void *)2);
    EXPECT_EQ(circular_linked_list_get(circular_linked_list, 2)->data, (void *)3);
    circular_linked_list_destroy(circular_linked_list);
}

// 测试遍历循环链表
void circular_linked_list_print_data(void *data)
{
    EXPECT_EQ(data, (void *)1);
}

TEST(CIRCULAR_LINKED_LIST, FOREACH)
{
    CircularLinkedList *circular_linked_list = circular_linked_list_create();
    circular_linked_list_insert(circular_linked_list, (void *)1, 0);
    circular_linked_list_insert(circular_linked_list, (void *)1, 1);
    circular_linked_list_insert(circular_linked_list, (void *)1, 2);
    circular_linked_list_foreach(circular_linked_list, circular_linked_list_print_data);
    circular_linked_list_destroy(circular_linked_list);
}
