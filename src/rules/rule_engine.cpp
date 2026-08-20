#include "engine/rule_engine.hpp"
namespace engine { void RuleEngine::add_rule(std::unique_ptr<Rule> r){r_.push_back(std::move(r));} std::vector<RuleResult> RuleEngine::evaluate(const Event&e)const{std::vector<RuleResult>x;x.reserve(r_.size());for(auto& r:r_)x.push_back(r->evaluate(e));return x;} }
