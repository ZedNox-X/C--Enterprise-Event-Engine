#include "engine/cpu_rule.hpp"
#include <gtest/gtest.h>
#include <memory>
TEST(Rule,Alert){engine::RuleEngine r;r.add_rule(std::make_unique<engine::HighCpuRule>(90));auto x=r.evaluate({1,"D","CPU_HIGH",97});ASSERT_EQ(x.size(),1);EXPECT_TRUE(x[0].matched);}
TEST(Rule,Ignore){engine::RuleEngine r;r.add_rule(std::make_unique<engine::HighCpuRule>(90));EXPECT_FALSE(r.evaluate({1,"D","CPU_HIGH",40})[0].matched);}
