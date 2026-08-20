#pragma once
#include <atomic>
#include <cstdint>
namespace engine { class Metrics{std::atomic<std::uint64_t> received_{0},processed_{0},failed_{0};public:void received();void processed();void failed();std::uint64_t received_count()const;std::uint64_t processed_count()const;std::uint64_t failed_count()const;}; }
