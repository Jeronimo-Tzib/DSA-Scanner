#include "lexer.h"
#include <cctype>

using namespace std;

//initialize lexical unit with category and content
LexUnit::LexUnit(LexCategories::Type cat, const string& val) 
    : category(cat), content(val) {}

//symbol extraction logic
LexUnit parseNextSymbol(const string& source, size_t& readpos){

    //ignore whitespace characters
    while(readpos < source.length() && isspace(source[readpos])) 
        readpos++;

    //check for end of input
    if(readpos >= source.length())
        return {LexCategories::STREAM_END, ""};

    char current = source[readpos];

    //handle grouping symbols
    if(current == '('){
        readpos++;
        return {LexCategories::PAREN_OPEN, "("};
    }
    if(current == ')'){
        readpos++;
        return {LexCategories::PAREN_CLOSE, ")"};
    }

    //process arithmetic operators
    switch(current){

        case '+': 
            readpos++;
            return {LexCategories::OP_PLUS, "+"};
        case '-':
            //check if negative number
            if(readpos+1 < source.length() && isdigit(source[readpos+1])){

                string numeral(1, '-');

                readpos++;

                while(readpos < source.length() && isdigit(source[readpos]))
                    numeral += source[readpos++];
                return {LexCategories::NUM_LIT, numeral};
            }

            readpos++;

            return {LexCategories::OP_MINUS, "-"};
        case '*': case 'x': case 'X':

            readpos++;

            return {LexCategories::OP_MULTIPLY, "*"};
        case '/':

            readpos++;

            return {LexCategories::OP_DIVIDE, "/"};
    }

    //extract numeric values
    if(isdigit(current)){

        string numeral;

        while(readpos < source.length() && isdigit(source[readpos]))
            numeral += source[readpos++];

        return {LexCategories::NUM_LIT, numeral};
    }

    //handle unrecognized characters
    return {LexCategories::INVALID, string(1, source[readpos++])};
}