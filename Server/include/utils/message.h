#ifndef MESSAGE_H
#define MESSAGE_H

#include <variant>
#include <string>

enum MessageType {
    CHAR_ARR = 0,
    INT_ARR = 1,
    DOUBLE_ARR = 2,
    CHAR = 3,
    INT = 4,
    DOUBLE = 5
};

/** 
 * @struct Message Char Array
 * 
 * @brief Create messages of type char array (strings)
 * 
 * @public
 * 
 * @param type : Integer which is mapped to a type through enum
 * @param length : Length of message to be sent
 * @param id : Each client with have a unique ID. This is used to understand who sent the message
 * @param message : The message that is being sent
 * 
 * @function MessageCharArray(const int length) : Defulat constructor to get the length and initialize message array
 * @function void addMessage(******) : Gets the message that is being sent and copies it to the structs message
 * 
 */
struct Message {
    int type;
    int length;
    std::string id;

    using messageType = std::variant<char*, int*, double*>;

    messageType message;

    /** 
     * @function MessageCharArray
     * 
     * @brief Initnialize message array with length and assign length
     * 
     * @param length = Length of array
     * 
     * @return Nothing
     */
    Message(const int type, const int length, const std::string id);

    /** 
     * @function addCharArrMessage
     * 
     * @brief Add the message to the message array in the structures
     * 
     * @param message = Message to be sent to another client
     * 
     * @return Nothing
     */
    void addMessage(const char *message);

     /** 
     * @function addIntArrMessage
     * 
     * @brief Add the message to the message array in the structures
     * 
     * @param message = Message to be sent to another client
     * 
     * @return Nothing
     */
    void addMessage(const int *message);

     /** 
     * @function addDoubleArrMessage
     * 
     * @brief Add the message to the message array in the structures
     * 
     * @param message = Message to be sent to another client
     * 
     * @return Nothing
     */
    void addMessage(const double *message);

     

    /** 
     * @function ~MessageCharArray
     * 
     * @brief Deletes the array since it was allocated to the heap
     * 
     * @return Nothing
     */
    ~Message();

};

#endif