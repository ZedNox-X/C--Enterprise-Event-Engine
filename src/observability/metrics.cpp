#include "engine/metrics.hpp"
namespace engine { void Metrics::received(){++received_;} void Metrics::processed(){++processed_;} void Metrics::failed(){++failed_;} std::uint64_t Metrics::received_count()const{return received_.load();} std::uint64_t Metrics::processed_count()const{return processed_.load();} std::uint64_t Metrics::failed_count()const{return failed_.load();} }
