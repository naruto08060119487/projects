cmake_minimum_required(VERSION 3.29)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp
        current_account.cpp
        current_account.h
        savings_account.cpp
        savings_account.h
        Account.cpp
        Account.h
        Transactions.cpp
        Transactions.h
        current_account.cpp
        Transactions.cpp
        Isa.cpp
        Isa.h
)
