//
// Created by nickmint on 12/13/20.
//

#include "account.hpp"
const std::string& account::get_broker() const { return broker; }
void account::set_broker(const std::string& b) { broker = b; }
const std::vector<std::string>& account::get_filenames() const {
  return filenames;
}
const std::string& account::get_number() const { return number_str; }
void account::set_number(const std::string& n) { number_str = n; }

void account::add_filename(const std::string& f) {
  filenames.push_back(f);
}

std::ostream& operator<<(std::ostream& out, account& acc) {
  out << "broker:"<< acc.broker
      << " account:" << acc.number_str
      << " files:" << acc.filenames.size()
      << " lastdate: " << acc.last_date << std::endl;
  return out;
}

std::ostream& account::print_info(std::ostream& out) {
  return out;
}

void account::find_last_date()
{
  last_date = get_date(filenames[0]);
  for (auto f : filenames)
  {
    f = get_date(f);
    if (last_date < f) last_date = f;
  }
}
std::string account::get_date(const std::string& filename) const {
  std::string date = filename.substr(filename.find('_') + 1,
                                     filename.find('.'));
  date = date.substr(date.find('_') + 1, date.size()-1);
  return date;
  //return filename;
}
