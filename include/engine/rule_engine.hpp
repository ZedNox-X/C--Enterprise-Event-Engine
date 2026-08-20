#pragma once
#include "engine/event.hpp"
#include <memory>
#include <string>
#include <vector>
namespace engine { struct RuleResult{bool matched{};std::string action;}; class Rule{public:virtual~Rule()=default;virtual RuleResult evaluate(const Event&)const=0;}; class RuleEngine{std::vector<std::unique_ptr<Rule>> r_;public:void add_rule(std::unique_ptr<Rule> r);std::vector<RuleResult> evaluate(const Event&)const;}; }
