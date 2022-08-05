#include "processor.h"
#include "linux_parser.h"


// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
  vector<string> cpuUtilizationTime = LinuxParser::CpuUtilization();

  int user = std::stoi(cpuUtilizationTime.at(0));
  int nice = std::stoi(cpuUtilizationTime.at(1));
  int system = std::stoi(cpuUtilizationTime.at(2));
  int idle = std::stoi(cpuUtilizationTime.at(3));
  int ioWait = std::stoi(cpuUtilizationTime.at(4));
  int irq = std::stoi(cpuUtilizationTime.at(5));
  int softIrq = std::stoi(cpuUtilizationTime.at(6));
  int steal = std::stoi(cpuUtilizationTime.at(7));

  int realIdle = idle + ioWait;
  int nonIdle = user + nice + system + irq + softIrq + steal;
  int total = realIdle + nonIdle;

  int totald = total - prevTotal;
  int idled = realIdle - prevRealIdle;

  float result = (float)((totald - idled) / totald);
//  float result = (float)((total - idle) / total);
  prevTotal = total;
  prevRealIdle = realIdle;
  return result;
}