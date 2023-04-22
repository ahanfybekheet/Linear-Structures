cmake_minimum_required(VERSION 3.21)
project(Linear_Structures)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Linear_Structures
        CircularLinkedList.cpp
        CircularLinkedList.h
        "Combine Nodes Between Zeros.cpp"
        "Convert the infix expression to postfix expression.cpp"
        DoublyLinkedList.cpp
        DoublyLinkedList.h
        "Generate Binary Numbers from 1 to n.cpp"
        "Implement a stack.cpp"
        implementation.cpp
        List.cpp
        List.h
        "Longest Valid Parentheses.cpp"
        "Merge K sorted linked lists.cpp"
        Queue.cpp
        Queue.h
        SingleLinkedList.cpp
        SingleLinkedList.h
        "Sorting a Queue.cpp"
        Stack.cpp
        Stack.h)
