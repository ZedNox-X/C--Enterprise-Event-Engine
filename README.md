# C++ Enterprise Event Engine

Production-oriented C++20 event-processing platform demonstrating systems programming, concurrency, performance engineering, observability, testing, containers, and cloud-native deployment.

## Highlights

- Modern C++20, RAII and explicit ownership.
- Bounded producer/consumer queue with `std::jthread`
- Concurrent worker pool and pluggable rule engine
- PostgreSQL/Redis integration boundaries
- Structured logging and Prometheus-ready metrics
- GoogleTest and Google Benchmark integration
- CMake presets
- AddressSanitizer/UBSan CI
- Docker and Kubernetes deployment
- GitHub Actions CI

- <img width="1536" height="1024" alt="C++ Enterprise Event Engine Infographic" src="https://github.com/user-attachments/assets/8434ea38-61ea-4cb1-8bc8-b519168f9483" />


> Portfolio/reference implementation. External device actions are simulated.

## Architecture
```text
REST/TCP Ingestion -> Validation -> Bounded Queue -> Worker Pool
                                                -> Rule Engine
                                                     |-> PostgreSQL
                                                     |-> Redis
                                                     `-> Metrics
```

## Build
Requirements: C++20, CMake 3.24+, Ninja.

```bash
cmake --preset default
cmake --build --preset default
ctest --test-dir build --output-on-failure
./build/event-engine
```

## Docker
```bash
docker compose up --build
```

## Engineering decisions
- **Bounded queue:** provides backpressure and prevents unbounded memory growth.
- **RAII:** resource ownership is explicit; `std::unique_ptr` is the default ownership model.
- **Concurrency:** shared mutable state is minimized; worker lifecycle uses `std::jthread`.
- **Performance:** benchmark before introducing lock-free complexity.
- **Observability:** metrics and structured logging are first-class concerns.

## Production roadmap
Add Boost.Asio/Beast networking, libpqxx PostgreSQL adapter, Redis adapter, OpenTelemetry, authenticated APIs, mTLS, durable event transport, Kubernetes HPA/KEDA, image scanning and full integration/E2E environments.
Version 1.0.22
