#ifndef LIB_H
#define LIB_H

#include <iostream>
#include <Windows.h>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

#define CREATE_INFO(message) Logger::log(message, InfoADD)
#define INFO(message) Logger::log(message, Info)
#define ERROR(message) Logger::log(message, Error)
#define WARNING(message) Logger::log(message, Warning)
#define LOG_DEFAULT(message) Logger::log(message, DefaultLogger)
#define LOG_OWN(message, color) Logger::log(message, Own, color)

#endif