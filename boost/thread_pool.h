#pragma once

#include <iostream>
#include <thread>

#include "boost/asio.hpp"
#include "boost/thread.hpp"

class ThreadPool {
public:
    ThreadPool() = default;
    ThreadPool(ThreadPool const& other) = delete;
    ThreadPool(ThreadPool&& other) = delete;
    ThreadPool& operator=(ThreadPool const& other) = delete;
    ThreadPool& operator=(ThreadPool&& other) = delete;
    ThreadPool(std::size_t threads) : io_service_(), work_(std::make_unique<boost::asio::io_service::work>(io_service_)){
        for(std::size_t i = 0; i < threads; ++i) {
            thread_group_.add_thread(new boost::thread([this]() {
                io_service_.run();
            }));
        }
    }
    ~ThreadPool() noexcept {
        work_.reset();
        thread_group_.join_all();
        io_service_.stop();
    };

    template <class F>
    void submit(F&& f) {
        io_service_.post(f);
    }
private:
    boost::asio::io_service io_service_{};
    boost::thread_group thread_group_{};
    std::unique_ptr<boost::asio::io_service::work> work_{}; // work to keep service running

};
