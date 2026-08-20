#pragma once
#include "engine/rule_engine.hpp"
namespace engine { class HighCpuRule final:public Rule{double threshold_;public:explicit HighCpuRule(double t):threshold_(t){} RuleResult evaluate(const Event&)const override;}; }
