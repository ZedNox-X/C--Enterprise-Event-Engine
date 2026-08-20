#include "engine/cpu_rule.hpp"
namespace engine { RuleResult HighCpuRule::evaluate(const Event&e)const{return e.event_type=="CPU_HIGH"&&e.value>=threshold_?RuleResult{true,"CREATE_ALERT"}:RuleResult{false,"IGNORE"};} }
