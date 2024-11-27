/* PROJ2
 * Tansu Erin Sarlak
 * 05/01/2022
 * Implementation for RPNCalc Class
 */

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdio>
#include <fstream>
#include "Datum.h"
#include "DatumStack.h"
#include "RPNCalc.h"

/*
 * name:      RPNCalc
 * purpose:   initializes an RPNCalc instance
 * arguments: none
 * returns:   none
 * effects:   none
 */
RPNCalc::RPNCalc()
{
    s_quit = true;
    
}


/*
 * name:      ~RPNCalc
 * purpose:   recycles any heap-allocated data used in RPNCalc instance
 * arguments: none
 * returns:   none
 * effects:   none
 */
RPNCalc::~RPNCalc()
{


}


/*
 * name:      ~RPNCalc
 * purpose:   reads in commands from standard input (std::cin) 
 *            and executes the commands
 * arguments: none
 * returns:   none
 * effects:   none
 */
void RPNCalc::run()
{
    play(std::cin); 
    std::cerr << "Thank you for using CalcYouLater.\n";
}


/*
 * name:      play
 * purpose:   helps run function to read in commands and execute them
 * arguments: stream type for istream
 * returns:   none
 * effects:   updates datum stack
 */
void RPNCalc::play(std::istream &stream_name)
{
    std::string s_input;
    int i_input;

    //gets input from the stream non-stop
    while (s_quit and stream_name>>s_input )
    {
    
        try{
            if (got_int(s_input, &i_input)){
                    Datum item(i_input);
                    stack.push(item);
            }
            else if (s_input == "#t"){
                is_true();
            }
            else if (s_input == "#f"){
                is_false();
            }
            else if (s_input == "not"){
                is_not();
            }
            else if (s_input == "print"){
                std::cout << stack.top().toString() <<std::endl;
            }
            else if (s_input == "drop"){
                stack.pop();
            }
            else if (s_input == "dup"){
                stack.push(stack.top());
            }
            else if (s_input == "swap"){
                is_swap();
            }
            else if (s_input ==  "clear"){
                stack.clear();
            }
            else if (s_input == "quit"){
                s_quit = false;
                return;
            }
            else if (s_input == "+" or s_input == "-" or s_input == "*" 
                        or s_input == "/" or s_input == "mod" or  s_input == "<"
                        or s_input == ">" or s_input == "<=" or s_input == ">="
                                                            or s_input == "=="){                                           
                is_operation(s_input);
            }
            else if (s_input == "{"){
                stack.push(Datum(parseRString(stream_name)));

            }
            else if (s_input == "exec"){
                is_exec();
            }

            else if (s_input == "file"){
                is_file();
            }
            else if (s_input == "if"){
                is_if();
            }
            else {
                std::cerr << s_input << ": unimplemented" <<std::endl;
            }

            }

            catch (const std::runtime_error &e) {
            std::cerr <<"Error: "<< e.what()<<std::endl;
            }
    
    }
    
}         


/*
 * name:      is_true
 * purpose:   pushes a boolean with the value true to the stack
 * arguments: none
 * returns:   none
 * effects:   updates datum stack
 */
void RPNCalc::is_true(){
    //pushes a boolean of the value true to the stack
    Datum item(true);
    stack.push(item);
}


/*
 * name:      is_false
 * purpose:   pushes a boolean with the value false to the stack
 * arguments: none
 * returns:   none
 * effects:   updates datum stack
 */
void RPNCalc::is_false(){
    //pushes a boolean of the value false to the stack
    Datum item(false);
    stack.push(item);        
    }    


/*
 * name:      is_not
 * purpose:   removes the top bool element and pushes its 
 *            counterpart to the stack
 * arguments: none
 * returns:   none
 * effects:   updates datum stack
 */
void RPNCalc::is_not(){
    //adds the counterpart bool element of the top element
    stack.push(Datum(not(stack.top().getBool())));
    //swaps the originially top element and the newly added 
    is_swap();
    //pops the originally top element
    stack.pop();
}


/*
 * name:      is_swap
 * purpose:   swap the top two elements of the stack
 * arguments: none
 * returns:   none
 * effects:   updates datum stack
 */
void RPNCalc::is_swap(){
    //stores the top element and then pops it
    Datum item1(stack.top());
    stack.pop();
    //stores the top element(originally second) and then pops it
    Datum item2(stack.top());
    stack.pop();
    //adds the elements to the stack in reverse orders
    stack.push(item1);
    stack.push(item2);
}


/*
 * name:      is_operation
 * purpose:   executes the provided operation against the top two elements
 * arguments: none
 * returns:   none
 * effects:   updates datum stack
 */
void RPNCalc::is_operation(std::string s_operation){

    //stores top two elements and then deletes them
    Datum item1(stack.top());
    stack.pop(); 

    Datum item2(stack.top());
    stack.pop();

    //applies the operation provided as the argument
    if (s_operation == "+"){
        Datum item3(item1.getInt() + item2.getInt());
        stack.push(item3);
    }
    else if (s_operation == "-"){
        Datum item3(item2.getInt() - item1.getInt());
        stack.push(item3);
    }
    else if (s_operation == "/"){

        if (item1.getInt() == 0){
            std::cerr << "Error: division by 0." <<std::endl;
            return;
        }

        Datum item3(item2.getInt() / item1.getInt());
        stack.push(item3);
    }
    else if (s_operation == "*"){
        Datum item3(item1.getInt() * item2.getInt());
        stack.push(item3);
    }
    else if (s_operation == "mod"){

        if (item1.getInt() == 0){
            std::cerr << "Error: division by 0." <<std::endl;
            return;
        }

        Datum item3(item2.getInt() % item1.getInt());
        stack.push(item3);
    }
    else if (s_operation == "<"){
        Datum item3(item2 < item1);
        stack.push(item3);
    }
    else if (s_operation == ">"){
        Datum item3(not (item2 < item1));
        stack.push(item3);
    }
    else if (s_operation == "<="){
        Datum item3( (item2 < item1) or (item1 == item2));
        stack.push(item3);
    }
    else if (s_operation == ">="){
        Datum item3((not (item2 < item1)) or (item1 == item2));
        stack.push(item3);
    }
    else if (s_operation == "=="){
        Datum item3(item1 == item2);
        stack.push(item3);
    }
}

/*
 * name:      is_RString
 * purpose:   takes the topmost element on the stack and processes its
 *            contents as a sequence of commands.
 * arguments: none
 * returns:   none
 * effects:   updates datum stack, prints error messahe if topmost element
 *            is not an RString
 */
void RPNCalc::is_exec(){
    if (stack.top().isRString()){   
        //extract the Rstring from the stack         
        std::string s_exec = stack.top().getRString();
        //omit the paranthesis around the Rstring
            if(s_exec.size() < 4){
                s_exec = s_exec.substr(1,s_exec.size()-2);            }
            else {
                s_exec = s_exec.substr(2,s_exec.size()-4);
            }
            std::stringstream ss(s_exec);
           
        stack.pop();
        //feed the play function with the RString
        play(ss);
        }
    else{
        stack.pop();
        std::cerr << "Error: cannnot execute non rstring\n" <<std::endl;
        }
}


/*
 * name:      is_file
 * purpose:   The contents of the named file is then read and processed
 *            as if its commands had been typed into the command loop.
 * arguments: none
 * returns:   none
 * effects:   updates datum stack, prints error message if file doesn't open
 */
void RPNCalc::is_file(){
    
    if (stack.top().isRString()){   
        std::ifstream i_file;

        //get the file name from the RString
        std::string s_exec = stack.top().getRString();
        if (s_exec.size() < 4){
            s_exec = s_exec.substr(1,s_exec.size()-2);            
        }
        else {
            s_exec = s_exec.substr(2,s_exec.size()-4);
        }
        stack.pop();
        //open the file and print error message if can"t
        i_file.open(s_exec);
        if (not i_file.is_open()){
            std::cerr << "Unable to read " << s_exec <<std::endl;
        }
        else {
            //passes the file to the command loop
            play(i_file);
            i_file.close();
            }
        }
    else {
        stack.pop();
        std::cerr << "Error: file operand not rstring\n" <<std::endl;
    }
}


/*
 * name:      is_if
 * purpose:   Tests a boolean codition, and if True exec'ds True Case and if
 *            False exec'ds False Case RString
 * arguments: none
 * returns:   none
 * effects:   updates datum stack, prints error message if Datum type is wrong
 */
void RPNCalc::is_if()
{   
    Datum f_case(stack.top());
    stack.pop();
    Datum t_case(stack.top());
    stack.pop();
    Datum condition = stack.top();
    stack.pop();

    //checks if the third element is boolean
    if (not condition.isBool()){
        std::cerr << "Error: expected boolean in if test\n";
    } else if( not (f_case.isRString() and t_case.isRString())){   
    //checks if the top two element are RStrings
        std::cerr << "Error: expected rstring in if branch\n";
        return;
    }    

    //depending on if the condition is true or false,  
    //passes the true or false case to the command loop
    if (condition.getBool()){
        stack.push(t_case);
    }
    else {
        stack.push(f_case);
    }   
        is_exec();
}


/*
 * name:      got_int
 * purpose:   Test whether a string can be interpreted as an integer, and, if 
 *            so, what the value of the integer is
 * arguments: the string to be checked if is an integer equivalent or not, and
 *            the variable to store its value if is an integer equivalent
 * returns:   Return true if the string s can be interpreted as an integer
 *            number, placing the associated integer into the location pointed
 *            to by resultp. Return false if s cannot be interpreted as an 
 *            integer leaving the location pointed to by resultp unmodified.
 * effects:   none
 */
bool RPNCalc::got_int(std::string s, int *resultp)
{
        /* Holds the first non-whitespace character after the integer */
        char extra;

        return sscanf(s.c_str(), " %d %c", resultp, &extra) == 1;
}



/*
 * name:      parseRString
 * purpose:   Assumes this function is called after an initial “{” has been
 *            read from the input stream passed as a parameter. parseRString
 *            continues reading input from the stream until all curly braces
 *            are matched or until it reaches the end of the input. 
 * arguments: type of the istream
 * returns:   an rstring (i.e, an std::string), with the preceding rstring specifications.
 * effects:   none
 */
std::string RPNCalc::parseRString(std::istream &stream_name)
{
    std::stringstream ss;
    std::string string;
    ss << " ";
    while ((stream_name >> string) and (string != "}")){ 
         // if input also includes an opening bracket    
        if (string == "{"){ 
            //invokes the function again, putting a space afterwards
            ss << parseRString(stream_name) << " ";
        } else {
            ss << string << " ";
        }
    }
    //inserts a closing bracket at the end of the input
    ss << "}";
    //adds an opening bracket in front of the string
    return "{" + ss.str();
    
}