# ADR-002: RAII and ownership

Use RAII and standard ownership semantics. Prefer values and `std::unique_ptr`; use shared ownership only when required. Manage worker lifetime with `std::jthread`.
