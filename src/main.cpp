#include "engine/cpu_rule.hpp"
#include "engine/metrics.hpp"
#include "engine/rule_engine.hpp"
#include "engine/thread_pool.hpp"
#include <iostream>
#include <memory>
int main(){engine::RuleEngine rules;rules.add_rule(std::make_unique<engine::HighCpuRule>(90));engine::ThreadPool pool(4,1024);engine::Metrics m;for(std::uint64_t i=1;i<=10;++i){engine::Event e{i,"DEV-"+std::to_string(i),"CPU_HIGH",91.0+static_cast<double>(i)};m.received();pool.submit([e,&rules,&m]{for(const auto&r:rules.evaluate(e))if(r.matched)std::cout<<"event="<<e.id<<" action="<<r.action<<'\n';m.processed();});}pool.stop();std::cout<<"received="<<m.received_count()<<" processed="<<m.processed_count()<<" failed="<<m.failed_count()<<'\n';}
