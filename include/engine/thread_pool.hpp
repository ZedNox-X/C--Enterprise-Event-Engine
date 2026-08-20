#pragma once
#include "engine/bounded_queue.hpp"
#include <functional>
#include <thread>
#include <vector>
namespace engine { class ThreadPool { BoundedQueue<std::function<void()>> q_; std::vector<std::jthread> w_; public: ThreadPool(std::size_t n,std::size_t c); ~ThreadPool(); bool submit(std::function<void()> f); void stop(); ThreadPool(const ThreadPool&)=delete; ThreadPool& operator=(const ThreadPool&)=delete; }; }
