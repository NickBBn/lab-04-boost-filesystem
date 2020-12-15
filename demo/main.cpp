// Copyright 2020 NickBBn nickgeo.winner@gmail.com

#include <boost/filesystem.hpp>
#include <finance_analyzer.hpp>
#include <iostream>

namespace fs = boost::filesystem;
int main(int argc, char* argv[])
{
  fs::path path_to_ftp;
  if (argc == 1) path_to_ftp = fs::current_path();
  else if (argc == 2) path_to_ftp = argv[1];
  else {
    std::cout << "Error: too many parameters" << std::endl;
    return -1;
  }
  finance_analyzer example;
  try {
    example.analyze(path_to_ftp);
    std::cout << example << std::endl;
  } catch (const std::string& error) {
    std::cout << error << std::endl;
    return -1;
  }
  return 0;
}
