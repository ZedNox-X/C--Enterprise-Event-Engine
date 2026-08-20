#include "engine/bounded_queue.hpp"
#include <gtest/gtest.h>
TEST(Queue,PushPop){engine::BoundedQueue<int>q(2);ASSERT_TRUE(q.push(42));auto v=q.pop();ASSERT_TRUE(v);EXPECT_EQ(*v,42);}
TEST(Queue,Closed){engine::BoundedQueue<int>q(2);q.close();EXPECT_FALSE(q.push(1));}
