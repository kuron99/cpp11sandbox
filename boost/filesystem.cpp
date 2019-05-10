#include "boost/filesystem.hpp"

int main() {
    namespace fs = boost::filesystem;
    fs::create_directories("test123");
    fs::create_directories("test123/aaa");

}