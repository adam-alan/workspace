#include <iostream>
#include <dirent.h>
#include "base/TimeStamp.h"
#include "base/Log.h"
#include "base/Log.cpp"
using namespace lodestar;

int main() {
    Logger::init();
    LOG_INFO("INFO");
    LOG_INFO("INFO");


    LOG_TRACE("NMSL");
    Logger::unInit();
    return 0;
}