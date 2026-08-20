#include "engine/event.hpp"
namespace engine { bool Event::valid() const noexcept { return id != 0 && !device_id.empty() && !event_type.empty(); } }
