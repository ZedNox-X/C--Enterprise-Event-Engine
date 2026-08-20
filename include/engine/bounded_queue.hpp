#pragma once
#include <condition_variable>
#include <cstddef>
#include <deque>
#include <mutex>
#include <optional>
#include <stop_token>
namespace engine { template<class T> class BoundedQueue { std::size_t cap_; std::deque<T> q_; std::mutex m_; std::condition_variable_any cv_; bool closed_{false}; public: explicit BoundedQueue(std::size_t c):cap_(c){} bool push(T v){std::unique_lock l(m_); cv_.wait(l,[this]{return closed_||q_.size()<cap_;}); if(closed_)return false; q_.push_back(std::move(v)); cv_.notify_all(); return true;} std::optional<T> pop(std::stop_token st={}){std::unique_lock l(m_); cv_.wait(l,st,[this]{return closed_||!q_.empty();}); if(q_.empty())return std::nullopt; T v=std::move(q_.front());q_.pop_front();cv_.notify_all();return v;} void close(){ {std::lock_guard l(m_);closed_=true;} cv_.notify_all();} }; }
