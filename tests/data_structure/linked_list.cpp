#include <gtest/gtest.h>

extern "C"
{
#include "data_structure/linked_list.h"
}

// 测试创建单链表
TEST(LINKED_LIST_TEST, CREATE)
{
    LinkedList *linked_list = linked_list_create();
    EXPECT_TRUE(linked_list->head == NULL);
    EXPECT_TRUE(linked_list->tail == NULL);
    EXPECT_EQ(linked_list->size, 0);
    linked_list_destroy(linked_list);
}

// 测试在单链表头部插入节点
TEST(LINKED_LIST_TEST, INSERT_HEAD)
{
    LinkedList *linked_list = linked_list_create();
    linked_list_insert_head(linked_list, (void *)1);
    EXPECT_EQ(linked_list->head->data, (void *)1);
    linked_list_destroy(linked_list);
}

// 测试在单链表尾部插入节点
TEST(LINKED_LIST_TEST, INSERT_TAIL)
{
    LinkedList *linked_list = linked_list_create();
    linked_list_insert_tail(linked_list, (void *)1);
    EXPECT_EQ(linked_list->tail->data, (void *)1);
    linked_list_destroy(linked_list);
}

// 测试在单链表指定位置插入节点
TEST(LINKED_LIST_TEST, INSERT)
{
    LinkedList *linked_list = linked_list_create();
    linked_list_insert(linked_list, (void *)1, 0);
    EXPECT_EQ(linked_list->head->data, (void *)1);
    linked_list_insert(linked_list, (void *)2, 1);
    EXPECT_EQ(linked_list->head->next->data, (void *)2);
    linked_list_destroy(linked_list);
}

// 测试删除单链表指定位置的节点
TEST(LINKED_LIST_TEST, REMOVE)
{
    LinkedList *linked_list = linked_list_create();
    linked_list_insert(linked_list, (void *)1, 0);
    linked_list_insert(linked_list, (void *)2, 1);
    linked_list_insert(linked_list, (void *)3, 2);
    linked_list_remove(linked_list, 1);
    EXPECT_EQ(linked_list->head->next->data, (void *)3);
    linked_list_destroy(linked_list);
}

// 测试获取单链表指定位置的节点
TEST(LINKED_LIST_TEST, GET)
{
    LinkedList *linked_list = linked_list_create();
    linked_list_insert(linked_list, (void *)1, 0);
    linked_list_insert(linked_list, (void *)2, 1);
    linked_list_insert(linked_list, (void *)3, 2);
    EXPECT_EQ(linked_list_get(linked_list, 1)->data, (void *)2);
    linked_list_destroy(linked_list);
}

// 测试遍历单链表
void linked_list_print_data(void *data)
{
    EXPECT_EQ(data, (void *)1);
}

TEST(LINKED_LIST_TEST, FOREACH)
{
    LinkedList *linked_list = linked_list_create();
    linked_list_insert(linked_list, (void *)1, 0);
    linked_list_insert(linked_list, (void *)1, 1);
    linked_list_insert(linked_list, (void *)1, 2);
    linked_list_foreach(linked_list, linked_list_print_data);
    linked_list_destroy(linked_list);
}
