#include <iostream>
#include "easylogging++.h"

using namespace std;

INITIALIZE_EASYLOGGINGPP

int main(int argc, char** argv) {
    el::Configurations conf("../ellog/config.conf");
    el::Loggers::reconfigureAllLoggers(conf);
    LOG(TRACE)   << "***** trace log  *****";
    LOG(DEBUG)   << "***** debug log  *****";
    LOG(ERROR)   << "***** error log  *****";
    LOG(WARNING) << "***** warning log  *****";
    LOG(INFO)    << "***** info log  *****";
    el::Logger* log = el::Loggers::getLogger("default");
    log->info("My first ultimate log message %% %%v %v %v", 123, 222);
}
