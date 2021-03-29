echo off
del run.exe
g++ -o run main.cpp accounts.cpp

start run.exe