#include <gtest/gtest.h>

extern "C"
{
#include "data_structure/dual_linked_list.h"
}

// 测试创建双链表
TEST(DUAL_LINKED_LIST_TEST, CREATE)
{
    DualLinkedList *dual_linked_list = dual_linked_list_create();
    EXPECT_TRUE(dual_linked_list->head == NULL);
    EXPECT_TRUE(dual_linked_list->tail == NULL);
    EXPECT_EQ(dual_linked_list->size, 0);
    dual_linked_list_destroy(dual_linked_list);
}

// 测试在双链表头部插入节点
TEST(DUAL_LINKED_LIST_TEST, INSERT_HEAD)
{
    DualLinkedList *dual_linked_list = dual_linked_list_create();
    dual_linked_list_insert_head(dual_linked_list, (void *)1);
    EXPECT_EQ(dual_linked_list->head->data, (void *)1);
    dual_linked_list_destroy(dual_linked_list);
}

// 测试在双链表尾部插入节点
TEST(DUAL_LINKED_LIST_TEST, INSERT_TAIL)
{
    DualLinkedList *dual_linked_list = dual_linked_list_create();
    dual_linked_list_insert_tail(dual_linked_list, (void *)1);
    EXPECT_EQ(dual_linked_list->tail->data, (void *)1);
    dual_linked_list_destroy(dual_linked_list);
}

// 测试在双链表指定位置插入节点
TEST(DUAL_LINKED_LIST_TEST, INSERT)
{
    DualLinkedList *dual_linked_list = dual_linked_list_create();
    dual_linked_list_insert(dual_linked_list, (void *)1, 0);
    EXPECT_EQ(dual_linked_list->head->data, (void *)1);
    dual_linked_list_insert(dual_linked_list, (void *)2, 1);
    EXPECT_EQ(dual_linked_list->head->next->data, (void *)2);
    dual_linked_list_insert(dual_linked_list, (void *)3, 2);
    EXPECT_EQ(dual_linked_list->head->next->next->data, (void *)3);
    dual_linked_list_destroy(dual_linked_list);
}

// 测试删除双链表指定位置的节点
TEST(DUAL_LINKED_LIST_TEST, REMOVE)
{
    DualLinkedList *dual_linked_list = dual_linked_list_create();
    dual_linked_list_insert(dual_linked_list, (void *)1, 0);
    dual_linked_list_insert(dual_linked_list, (void *)2, 1);
    dual_linked_list_insert(dual_linked_list, (void *)3, 2);
    dual_linked_list_remove(dual_linked_list, 0);
    EXPECT_EQ(dual_linked_list->head->data, (void *)2);
    dual_linked_list_remove(dual_linked_list, 1);
    dual_linked_list_destroy(dual_linked_list);
}

// 测试获取双链表指定位置的节点
TEST(DUAL_LINKED_LIST_TEST, GET)
{
    DualLinkedList *dual_linked_list = dual_linked_list_create();
    dual_linked_list_insert(dual_linked_list, (void *)1, 0);
    dual_linked_list_insert(dual_linked_list, (void *)2, 1);
    dual_linked_list_insert(dual_linked_list, (void *)3, 2);
    EXPECT_EQ(dual_linked_list_get(dual_linked_list, 0)->data, (void *)1);
    dual_linked_list_destroy(dual_linked_list);
}

// 测试遍历双链表
void dual_linked_list_print_data(void *data)
{
    EXPECT_EQ(data, (void *)1);
}

TEST(DUAL_LINKED_LIST_TEST, FOREACH)
{
    DualLinkedList *dual_linked_list = dual_linked_list_create();
    dual_linked_list_insert(dual_linked_list, (void *)1, 0);
    dual_linked_list_insert(dual_linked_list, (void *)1, 1);
    dual_linked_list_insert(dual_linked_list, (void *)1, 2);
    dual_linked_list_foreach(dual_linked_list, dual_linked_list_print_data);
}
