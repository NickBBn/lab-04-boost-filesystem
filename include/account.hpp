//
// Created by nickmint on 12/13/20.
//

#ifndef TEMPLATE_ACCOUNT_HPP
#define TEMPLATE_ACCOUNT_HPP
#include <iostream>
#include <vector>

class account
{
 public:
  const std::vector<std::string>& get_filenames() const;
  void add_filename(const std::string& f);
  const std::string& get_broker() const;
  void set_broker(const std::string& broker);
  friend std::ostream& operator<<(std::ostream &out, account& acc);
  const std::string& get_number() const;
  void set_number(const std::string& number);
  void find_last_date();
  std::string get_date(const std::string& filename) const;

 private:
  std::string number_str;
  std::string broker;
  std::string last_date;
  std::vector<std::string> filenames;
};

#endif  // TEMPLATE_ACCOUNT_HPP
