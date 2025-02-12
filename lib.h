#ifndef LIB_H
#define LIB_H

#include <iostream>
#include <Windows.h>
#include <string>
#include <random>

using std::cout;
using std::endl;
using std::cin;

using std::string;
using std::to_string;
using std::stoi;

using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::uniform_real_distribution;

#define CREATE_INFO(message) Logger::log(message, InfoADD)
#define INFO(message) Logger::log(message, Info)
#define ERROR(message) Logger::log(message, Error)
#define WARNING(message) Logger::log(message, Warning)
#define LOG_DEFAULT(message) Logger::log(message, DefaultLogger)
#define LOG_OWN(message, color) Logger::log(message, Own, color)

#endif