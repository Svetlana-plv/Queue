#include "queue.h"
#include <gtest.h>

TEST(TQueue, can_create_defolt_queue){

	ASSERT_NO_THROW(TQueue<int> queue);
}

TEST(TQueue, can_create_queue_with_positive_lenght) {

	ASSERT_NO_THROW(TQueue<int> queue(5));
}

TEST(TQueue, can_create_queue_with_negative_lenght) {

	ASSERT_ANY_THROW(TQueue<int> queue(-5));
}

TEST(TQueue, can_get_size_from_empty_queue) {

	TQueue<int> queue(5);

	EXPECT_EQ(0, queue.Size());
}

TEST(TQueue, can_get_size) {

	TQueue<int> queue(5);
	queue.Push(7);

	EXPECT_EQ(1, queue.Size());
}

TEST(TQueue, can_check_empty_stack) {

	TQueue<int> queue(5);

	ASSERT_NO_THROW(queue.Empty());
}

TEST(TQueue, stack_is_empty) {

	TQueue<int> queue(5);

	EXPECT_TRUE(queue.Empty());
}

TEST(TQueue, can_check_full_stack) {

	TQueue<int> queue(5);

	ASSERT_NO_THROW(queue.Full());
}

TEST(TQueue, stack_is_full) {

	TQueue<int> queue(5);

	for (int i = 0; i < 5; i++) queue.Push(i);

	EXPECT_TRUE(queue.Full());
}

TEST(TQueue, can_clear_stack) {

	TQueue<int> queue(5);
	queue.Push(5);
	queue.Push(7);

	ASSERT_NO_THROW(queue.Clear());
}

TEST(TQueue, cleared_stack_is_empty) {

	TQueue<int> queue(5);
	queue.Push(5);
	queue.Push(7);

	queue.Clear();

	EXPECT_TRUE(queue.Empty());
}

TEST(TQueue, can_get_top_element) {

	TQueue<int> queue(5);
	queue.Push(3);
	queue.Push(7);

	ASSERT_NO_THROW(queue.Top());
}

TEST(TQueue, top_element_correct) {

	TQueue<int> queue(5);
	queue.Push(3);
	queue.Push(7);

	EXPECT_EQ(3, queue.Top());
}

TEST(TQueue, cant_top_element_from_empty_queue) {

	TQueue<int> queue(5);

	ASSERT_ANY_THROW(queue.Top());
}

TEST(TQueue, can_push_element) {

	TQueue<int> queue(5);

	ASSERT_NO_THROW(queue.Push(7));
}

TEST(TQueue, pushed_element_is_correct) {

	TQueue<int> queue(5);

	queue.Push(3);
	queue.Push(7);

	EXPECT_EQ(3, queue.Top());
}

TEST(TQueue, can_pop_element) {

	TQueue<int> queue(5);
	queue.Push(5);
	queue.Push(7);

	ASSERT_NO_THROW(queue.Pop());
}

TEST(TQueue, cant_pop_element_from_empty_queue) {

	TQueue<int> queue(5);

	ASSERT_ANY_THROW(queue.Pop());
}

TEST(TQueue, can_repack_queue) {

	size_t size = 5;
	TQueue<int> queue(size);

	for(int i=0;  i<=size; i++) queue.Push(i);

	EXPECT_EQ(size*2, queue.GetMemSize());
}
