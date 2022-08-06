#include "process.h"

#include <unistd.h>

#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

// TODO: Return this process's ID
int Process::Pid() { return pid; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() {
  long total_time = LinuxParser::ActiveJiffies(pid);
  cpuUtilization = (float) total_time/uptime;
  return cpuUtilization;
}

// TODO: Return the command that generated this process
string Process::Command() {
  command = LinuxParser::Command(pid);
  return command; }

// TODO: Return this process's memory utilization
string Process::Ram() {
  ram = LinuxParser::Ram(pid);
  return ram;
}

// TODO: Return the user (name) that generated this process
string Process::User() {
  user = LinuxParser::User(pid);
  return user;}

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() {
  uptime = LinuxParser::UpTime(pid);
  return uptime;
}

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const { return this->cpuUtilization < a.cpuUtilization; }

Process::Process(int pid) : pid(pid){
  Process::User();
  Process::Command();
  Process::Ram();
  Process::UpTime();
  Process::CpuUtilization();

}