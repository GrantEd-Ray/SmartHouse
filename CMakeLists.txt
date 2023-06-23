cmake_minimum_required(VERSION 3.24)
project(SmartHouse)

set(CMAKE_CXX_STANDARD 17)

include_directories("Texts/")

add_executable(SmartHouse main.cpp)

file(COPY Texts/Config DESTINATION "/")
file(COPY Texts/Energy_Counter_Devices DESTINATION "/")
file(COPY Texts/Input_Devices DESTINATION "/")
file(COPY Texts/Temp_Devices DESTINATION "/")