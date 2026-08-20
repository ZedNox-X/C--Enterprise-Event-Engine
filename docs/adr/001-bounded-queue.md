# ADR-001: Bounded queue

Use a bounded producer/consumer queue to provide backpressure and prevent unbounded memory growth. Start with mutex/condition-variable synchronization and introduce lock-free structures only after profiling proves contention is a bottleneck.
