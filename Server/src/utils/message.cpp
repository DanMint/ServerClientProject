#include "../../include/utils/message.h"
#include <iostream>
#include <variant>


Message::Message(const int type, const int length) {
    this->type = type;
    this->length = length;

    if (type == CHAR_ARR)
        message = new char[length];
    
    else if (type == INT_ARR) 
       message = new int[length];
    
    else if (type == DOUBLE_ARR) 
        message = new double[length];
    
    else if (type == CHAR) 
        message = new char;
    
    else if (type == INT) 
        message = new int;
    
    else if (type == DOUBLE) 
        message = new double;
    
}

void Message::addMessage(const char *message) {
    for (int i = 0; i < length; i ++) 
        std::get<char *>(this->message)[i] = message[i];
    
}

void Message::addMessage(const int *message) {
    for (int i = 0; i < length; i ++) 
        std::get<int *>(this->message)[i] = message[i];
}

void Message::addMessage(const double *message) {
    for (int i = 0; i < length; i ++) 
        std::get<double *>(this->message)[i] = message[i];
}

Message::~Message() {
    if (type == CHAR_ARR)
        delete[] std::get<char *>(message);

    else if (type == INT_ARR)
        delete[] std::get<int *>(message);

    else if (type == DOUBLE_ARR)
        delete[] std::get<double *>(message);
    
    else if (type == CHAR)
        delete std::get<char *>(message); 
    
    else if (type == INT)
        delete std::get<int *>(message); 
    
    else if (type == DOUBLE)
        delete std::get<double *>(message); 
}

