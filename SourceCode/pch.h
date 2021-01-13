#pragma once
#include <iostream>
#include <Windows.h>
#include <chrono>
#include <thread>

#define SLEEP std::this_thread::sleep_for(std::chrono::seconds(30));