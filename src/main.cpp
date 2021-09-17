
#include <iostream>
#include <fstream>
#include "Stack.hpp"

#define OPEN_BRACKET(c) (c == '{' || c == '(' || c == '[' )
#define CLOSED_BRACKET(c) (c == '}' || c == ')' || c == ']')


int main(int ac, char **av)
{
    Stack *stack = new Stack();
    char c;
    bool valid_file = true;

    //open file
    std::ifstream file(av[1]);
    if (file.is_open())
    {
        //do while does something first, and THEN repeats
        while((!file.eof(), file.eof()) == false){

            //std::cout << c << std::endl;

            if(OPEN_BRACKET(c))
            {
                char *temp = new char;
                *temp = c;
                stack->push(temp);
            }
            if (CLOSED_BRACKET(c))
            {
                char *to_check = (char*)stack->pop();
                

                if(to_check == nullptr)
                {
                    std::cout << "nullpointer" << std::endl;
                }
                 
                std::cout << c << ' ';
                std::cout << *to_check << std::endl;

                //compare
                switch(c)
                {
                    case ']': if (*to_check != '[') { valid_file = false;}
                        break;
                    case ')': if (*to_check != '(') { valid_file = false;}
                        break;
                    case '}': if (*to_check != '{') { valid_file = false;}
                        break;
                }
            }
        }

        file.close();

        if (valid_file && stack->isEmpty())
            std::cout << "file was valid" << std::endl;
        else
            std::cout << "file was invalid" << std::endl;
        delete stack;
        return 0;


        // do{
        //     c = fgetc(file);
        //     std::cout << c << std::endl;
        // } while (c != EOF);
        // //end of file
        // file.close();
        //another way to do this:
        //char *mem = new char[5];
        //file.read(num, 1)
    }

    //loop through each character
    //check if open or closed bracket
    //do stuff with that

    //switch statement
    // switch(c)
    // {
    //     case '{': if (c = '}')
    //         break;
    //     case '[': //compare to ]
    //         break;
    //     case '(': //compare to )
    //         break;
    //     //if none of the other cases work
    //     default: break;
    // }

    // delete stack;
    // return 0;
}

//never use this: goto
//to go to a specific line of code
//NEVER USE THIS

//push is add
//pop is remove