FROM ubuntu:24.04 AS build
RUN apt-get update && apt-get install -y build-essential cmake ninja-build && rm -rf /var/lib/apt/lists/*
WORKDIR /src
COPY . .
RUN cmake --preset default && cmake --build --preset default
FROM ubuntu:24.04
WORKDIR /app
COPY --from=build /src/build/event-engine /app/event-engine
USER 10001
ENTRYPOINT ["/app/event-engine"]
