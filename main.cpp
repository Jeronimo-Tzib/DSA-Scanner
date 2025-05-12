#include <iostream>
#include <vector>
#include "lexer.h"

using namespace std;

int main(){

    string expression;

    cout << "Enter expression: ";

    getline(cin, expression);

    vector<LexUnit> symbols;
    size_t position = 0;

    //symbol collection loop

    do{
        LexUnit symbol = parseNextSymbol(expression, position);

        if(symbol.category == LexCategories::STREAM_END) break;
        symbols.push_back(symbol);

    }while(true);

    //display extracted symbols
    for(const auto& unit : symbols){

        cout << "[";
        switch(unit.category){
            case LexCategories::PAREN_OPEN:    cout << "PAREN_OPEN"; break;
            case LexCategories::PAREN_CLOSE:   cout << "PAREN_CLOSE"; break;
            case LexCategories::OP_PLUS:      cout << "ADD_OP"; break;
            case LexCategories::OP_MINUS:     cout << "SUB_OP"; break;
            case LexCategories::OP_MULTIPLY:  cout << "MUL_OP"; break;
            case LexCategories::OP_DIVIDE:    cout << "DIV_OP"; break;
            case LexCategories::NUM_LIT:       cout << "NUMBER"; break;
            case LexCategories::INVALID:       cout << "INVALID"; break;
            default:                          cout << "UNKNOWN";
        }
        cout << "] Value: '" << unit.content << "'\n";
    }

    return 0;
}