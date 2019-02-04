#include "glog/logging.h"

int f1() {
   throw 1;
}

int f2() {
    return f1();
}
int main(int argc, char* argv[]) {
    // Initialize Google's logging library.
    google::InitGoogleLogging(argv[0]);
    google::InstallFailureSignalHandler();

    // ...
    LOG(INFO) << "Found " << 333 << " cookies";
    LOG(ERROR) << "Found " << 333 << " cookies";

    f2();
}