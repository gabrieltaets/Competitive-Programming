#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cctype>


int main(const int argc, const char *argv[])
{
	std::string str;
	std::cin >> str;
  bool change=false, flag2 = true;
  for (int i=0; i<str.length(); ++i) {
    if (str.at(i)-96 < 0) {
      change=true;
      for (int j=i; j<str.length(); ++j)
        if (str.at(j)-96 > 0) {
          change=false;
          flag2 = false;
        }
      if(flag2 == false) break;
    }
  }
  if(str.length()==1) change = true;
  if (change) {
    for (int i=0; i<str.length(); ++i) {
      if(str[i] == tolower(str[i])) str[i] = std::toupper(str[i]);
      else str[i] = std::tolower(str[i]);
    }
  }
	std::cout << str << std::endl;
	return 0;
}