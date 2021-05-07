#pragma once
//https://stackoverflow.com/questions/10492847/c-namespace-functions

#include <string>
#include <iostream>

namespace EntityEngine{
  void log(const std::string& tag, const std::string& message);
  void log(const std::string& tag, const std::string& message, const std::exception& error);
} // namespace EntityEngine