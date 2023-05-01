#include <chrono>
#include <iterator>
#include <iostream>

#define START_COUNT_TIME   TimeCounter tc(__func__)

class TimeCounter
{
  public:
    TimeCounter(const std::string& name):beginTime_(std::chrono::high_resolution_clock::now()), name_(name)
    {
    }
    ~TimeCounter()
    {
      endTime_ = std::chrono::high_resolution_clock::now();
      std::cerr << "running " << name_ << " tooks " 
                <<  std::chrono::duration<double>(endTime_ - beginTime_).count() << " seconds" 
                << std::endl;
    }

  private:
    std::string name_;
    std::chrono::high_resolution_clock::time_point beginTime_;
    std::chrono::high_resolution_clock::time_point endTime_;

};
