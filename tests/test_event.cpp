#include "engine/event.hpp"
#include <gtest/gtest.h>
TEST(Event,Valid){EXPECT_TRUE((engine::Event{1,"D","CPU_HIGH",95}).valid());}
TEST(Event,Invalid){EXPECT_FALSE((engine::Event{1,"","CPU_HIGH",95}).valid());}
