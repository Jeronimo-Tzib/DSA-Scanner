#pragma once
#include <string>

using namespace std;

//lexical categories for expression components
namespace LexCategories{

    enum Type{
        PAREN_OPEN,      //opening parenthesis
        PAREN_CLOSE,     //closing parenthesis
        OP_PLUS,         //addition operator
        OP_MINUS,        //subtraction/negation
        OP_MULTIPLY,     //multiplication
        OP_DIVIDE,       //division
        NUM_LIT,         //numeric value
        INVALID,         //unrecognized symbol
        STREAM_END       //end of input marker
    };
}

//lexical unit container
struct LexUnit{
    LexCategories::Type category;
    string content;
    
    LexUnit(LexCategories::Type cat, const string& val);
};
 
//main lexical processing function
LexUnit parseNextSymbol(const string& source, size_t& readpos);