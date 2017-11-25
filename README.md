# ellog
Thanks for [Easylogging++ v9.80](https://github.com/muflihun/easyloggingpp)
this is some small modified
- modified: void Logger::log_(Level level, int vlevel, const char* s, const T& value, const Args&... args)
  - from 
  ```c++
        b << value;
  ```
  - to 
  ```c++
    if (value == NULL)
    {
         b << "\033[31mExist NULL Pointer, Will Crash!!!\033[00m";
         ELPP_INTERNAL_ERROR("Exist NULL Pointer, Will Crash", true);
         //continue;
    }
    else {
         b << value;
    }
  ```

- Add function timestamp: static inline unsigned long long timestamp()
  ```c++
    static inline unsigned long long timestamp() {
        struct timeval currTime;
        gettimeofday(&currTime);
        time_t t;
  #if ELPP_OS_UNIX
        t = currTime.tv_sec;
  #else
  #   if ELPP_COMPILER_MSVC
        ELPP_UNUSED(currTime);
        _time64(&t);
  #   else
        // For any other compilers that don't have CRT warnings issue e.g, MinGW or TDM GCC- we use different method
        t = currTime.tv_sec;
  #   endif  // ELPP_COMPILER_MSVC
  #endif  // ELPP_OS_UNIX
        return time(&t);
    }
   ```
