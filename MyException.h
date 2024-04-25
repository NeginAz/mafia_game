#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include<string>
#include<iostream>
using namespace std;

class MyException {
private:
  string msg;
 public:
   MyException(string msg_i) {msg=msg_i;}
   string  what ();
};
#endif
