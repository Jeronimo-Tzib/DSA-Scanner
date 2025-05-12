# Mathematical Expression Tokenizer/Scanner

## Project Overview
This C++ implementation demonstrates lexical analysis of mathematical expressions by converting input strings into categorized tokens. The system handles numbers (including negatives), operators, parentheses, and identifies invalid characters.

## Owner
- Jeronimo Tzib

## Course Information
- Course: CMPS 2131
- Lecturer: Mr. Dalwin Lewis

## Project Goals
- Implement a lexical analyzer for mathematical expressions
- Handle operator precedence symbols and grouping
- Detect numeric literals and negative values
- Identify unrecognized characters
- Demonstrate tokenization workflows

## Project Deliverables
- [Code Demonstration Video](#) (https://youtu.be/demo-link-here)

## How to Run
### Compilation
g++ main.cpp lexer.cpp -o program

### Execution
./program

## Sample Input/Output
Enter expression: -5 + (3 * x)
[SUB_OP] Value: '-'
[NUMBER] Value: '5'
[ADD_OP] Value: '+'
[PAREN_OPEN] Value: '('
[NUMBER] Value: '3'
[MUL_OP] Value: '*'
[INVALID] Value: 'x'
[PAREN_CLOSE] Value: ')'
