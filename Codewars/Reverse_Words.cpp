/*
This is a terrible solution, but it has taught me a lot about strings, so I am happy. Also, notice that you ***cannot*** append chars to strings, only other strings!
*/
#include <string>

std::string reverse_string(std::string str) {
  int size = str.size() - 1;
  std::string new_string;
  
  for (int i = size; i >= 0; i--) {
    new_string += str[i];
  }
  
  return new_string;
}

std::string reverse_words(std::string str) {
  int size = str.size();
  std::string new_string;
  std::string buffer;
  for (int i=0; i < size; i++) {
    if (str[i] == ' ') {
      new_string.append(reverse_string(buffer));
      new_string += ' ';
      buffer = "";
    } else {
      buffer += str[i];
    }
  }
  new_string.append(reverse_string(buffer));
  return new_string;
}