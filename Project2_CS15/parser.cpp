/* PROJ2
 * Tansu Erin Sarlak
 * 05/01/2022
 * ParseRString Function
 */
#include "Datum.h"
#include "DatumStack.h"
#include <istream>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
#include <iostream>



// std::string parseRString(std::istream &input);

// int main(){
//     std::string message = parseRString(std::cin);
//     std::cout << message << std::endl;
//     return 0;
// }


std::string parseRString(std::istream &input)
{
    std::stringstream ss;
    std::string message;
    
   
    ss << " ";

  
    while ((input >> message) and (message != "}")){
      
        if (message == "{"){
          
            ss << parseRString(input) << " ";
        } else {
            ss << message << " ";
        }

    }


    ss << "}";


    return "{" + ss.str();
}