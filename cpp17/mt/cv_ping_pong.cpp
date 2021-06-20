// ping pong

#include <condition_variable>
#include <iostream>
#include <atomic>
#include <thread>

bool dataReady{false};

std::mutex mutex_;
std::condition_variable condVar1;          // (1)
std::condition_variable condVar2;          // (2)

std::atomic<int> counter{};
constexpr int countlimit = 1'000'000;

void ping() {

    while(counter <= countlimit) {
        {
            std::unique_lock<std::mutex> lck(mutex_);
            condVar1.wait(lck, []{return dataReady == false;});
            dataReady = true;
        }
        ++counter;
        condVar2.notify_one();              // (3)
  }
}

void pong() {

    while(counter < countlimit) {
        {
            std::unique_lock<std::mutex> lck(mutex_);
            condVar2.wait(lck, []{return dataReady == true;});
            dataReady = false;
        }
        condVar1.notify_one();            // (3)
  }

}

int main(){

    auto start = std::chrono::system_clock::now();

    std::thread t1(ping);
    std::thread t2(pong);

    t1.join();
    t2.join();

    std::chrono::duration<double> dur = std::chrono::system_clock::now() - start;
    std::cout << "Duration: " << dur.count() << " seconds" << std::endl;

}