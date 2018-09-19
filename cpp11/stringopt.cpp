#include <chrono>
#include <string>
#include <iostream>

class watch {
public:
    using clock = std::chrono::steady_clock;

    watch() {
        begin_ = clock::now();
    }

    long long stop() {
        const std::chrono::time_point<clock> end = clock::now();
        return std::chrono::duration_cast<std::chrono::microseconds>(end - begin_).count();
    }

    void reset() {
        begin_ = clock::now();
    }

private:
    std::chrono::time_point<std::chrono::steady_clock> begin_;
};

std::string remove_ctrl(std::string s);

std::string remove_ctrl_mutating(std::string s);

std::string remove_ctrl_reserve(std::string s);

std::string remove_ctrl_ref_args(const std::string &s);

std::string remove_ctrl_ref_args_it(const std::string &s);

void remove_ctrl_ref_result_it(std::string &ret, const std::string &s);

void remove_ctrl_cstring(char *dest, const char *src, size_t size);

int main() {
    std::string input("ABCEDFksjdfklaksdX\njflkajsdlkfj\taksdlfjkalsd\tkjf\tklsdkjf");
    watch w{};
    remove_ctrl(input);
    long dur = w.stop();
    std::cout << "remove_ctrl: " << dur << std::endl;
    w.reset();
    remove_ctrl_mutating(input);
    long dur1 = w.stop();
    std::cout << "remove_ctrl_mutating: " << dur1 << std::endl;
    w.reset();
    remove_ctrl_reserve(input);
    long dur2 = w.stop();
    std::cout << "remove_ctrl_reserve: " << dur2 << std::endl;
    w.reset();
    remove_ctrl_ref_args(input);
    long dur3 = w.stop();
    std::cout << "remove_ctrl_ref_args: " << dur3 << std::endl;
    w.reset();
    remove_ctrl_ref_args_it(input);
    long dur4 = w.stop();
    std::cout << "remove_ctrl_ref_args_it: " << dur4 << std::endl;
    w.reset();
    std::string out;
    remove_ctrl_ref_result_it(out, input);
    long dur5 = w.stop();
    std::cout << "remove_ctrl_ref_result_it: " << dur5 << std::endl;
    w.reset();
    char buf[input.length()];
    remove_ctrl_cstring(buf, input.c_str(), input.length());
    long dur6 = w.stop();
    std::cout << "remove_ctrl_cstring: " << dur6 << std::endl;
}


std::string remove_ctrl(std::string s) {
    std::string ret;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] > 0x20) {
            ret = ret + s[i];
        }
    }
    return ret;
}

std::string remove_ctrl_mutating(std::string s) {
    std::string ret;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] > 0x20) {
            ret += s[i];
        }
    }
    return ret;
}

std::string remove_ctrl_reserve(std::string s) {
    std::string ret;
    ret.reserve(s.length());
    for (int i = 0; i < s.length(); i++) {
        if (s[i] > 0x20) {
            ret += s[i];
        }
    }
    return ret;
}

std::string remove_ctrl_ref_args(const std::string &s) {
    std::string ret;
    ret.reserve(s.length());
    for (int i = 0; i < s.length(); i++) {
        if (s[i] > 0x20) {
            ret += s[i];
        }
    }
    return ret;
}

std::string remove_ctrl_ref_args_it(const std::string &s) {
    std::string ret;
    ret.reserve(s.length());
    for (auto it = s.begin(); it != s.end(); ++it) {
        if (*it > 0x20) {
            ret += *it;
        }
    }
    return ret;
}

void remove_ctrl_ref_result_it(std::string &ret, const std::string &s) {
    ret.clear();
    ret.reserve(s.length());
    for (auto it = s.begin(); it != s.end(); ++it) {
        if (*it > 0x20) {
            ret += *it;
        }
    }
}

void remove_ctrl_cstring(char *dest, const char *src, size_t size) {
    for (size_t i = 0; i < size; i++) {
        if (src[i] > 0x20) {
            *dest++ = src[i];
        }
    }
}
