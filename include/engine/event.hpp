#pragma once
#include <cstdint>
#include <string>
namespace engine { struct Event { std::uint64_t id{}; std::string device_id; std::string event_type; double value{}; [[nodiscard]] bool valid() const noexcept; }; }
