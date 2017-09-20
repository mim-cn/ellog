#ifndef ELLOG_H
#define ELLOG_H
#include <iostream>
#include <string>
#include "easylogging++.h"

class ellog
{
public:
    ellog(const std::string& confile): _confile(confile){
        _conf = el::Configurations(_confile);
        el::Loggers::reconfigureAllLoggers(_conf);
    }
public:
    bool log(el::Level lev, const std::string& msg);
public:
    void glog(const std::string& msg){ log(el::Level::Global, msg); }
    void trace(const std::string& msg){ log(el::Level::Trace, msg);}
    void debug(const std::string& msg){ log(el::Level::Debug, msg); }
    void fatal(const std::string& msg){ log(el::Level::Fatal, msg);}
    void error(const std::string& msg){ log(el::Level::Error, msg); }
    void warn(const std::string& msg){ log(el::Level::Warning, msg); }
    void verbose(const std::string& msg){ log(el::Level::Verbose, msg); }
    void info(const std::string& msg){ log(el::Level::Info, msg); }
private:
    el::Configurations  _conf;
    std::string         _confile;
};

#endif // ELLOG_H
