#include <string>
using std::string;

#include <iostream>

#include <cctype> // for isalpha

#include "algebraic_expressions.hpp"

bool isoperator(char ch) {
  return ((ch == '+') || (ch == '-') || (ch == '/') || (ch == '*'));
}

int endPost(string s, int last) {
  int first = 0;

  if ((first > last)) {
    return -1;
  }

  char ch = s[last];
  if (isalpha(ch)) {
    return last;
  } else {
    if (isoperator(ch)) {
      int lastEnd = endPost(s, last - 1);
      if (lastEnd > -1) {
        return endPost(s, lastEnd - 1);
      } else {
        return -1;
      }
    } else {
      return -1;
    }
  }
}

bool isPost(string s) {
  int firstChar = endPost(s, s.size() - 1);

  return (firstChar == 0);
}

void convert(string &postfix, string &prefix) {

  // TODO
    int lengthPostfix = postfix.size(); //length of postfix
    char ch = postfix[lengthPostfix -1]; // last char of prefix

    prefix.append(1,ch);
    if(isoperator(ch))
    {
      //beginning of postfix2
      int beginning = endPost(postfix, lengthPostfix-2);


      //convert postfix1 into prefix version
      string postfix1;
      postfix1 = postfix.substr(0, beginning);
      convert(postfix1,prefix);

      //convert postfix2 into prefix version
      int lengthPostfix2;
      lengthPostfix2 = lengthPostfix - beginning - 1;
      string postfix2;
      postfix2 = postfix.substr(beginning,lengthPostfix2);
      convert(postfix2, prefix);


    }


    return;
  
  
}
