#include "lexer.h"

int get_tok()
{
    int LastChar = ' ';
    while (isspace(LastChar))
    {
        LastChar = getchar();
    }
    if (isalpha(LastChar))
    {
        IdentifierStr = LastChar;
        while(isalnum((LastChar = getchar())))
            IdentifierStr += LastChar;
        if (IdentifierStr == "def")
            return tok_def;
        if (IdentifierStr == "extern")
            return tok_extern;
        return tok_identifier;  // var name
    } else if (isdigit(LastChar) || LastChar == '.')
    {
        // number 
        std::string NumStr;
        do
        {
            NumStr += LastChar;
            LastChar = getchar();
        } while (isdigit(LastChar) || LastChar == '.');
        NumVal = strtod(NumStr.c_str(), nullptr);
        return tok_number;
    } else if (LastChar == '#')
    {
        // comments
        do 
            LastChar = getchar();
        while (LastChar != EOF && LastChar != '\n' && LastChar != '\r');
        if (LastChar != EOF)
            return get_tok();
    }
    if (LastChar == EOF)
        return tok_eof;
    int ThisChar = LastChar;    // just ASCII val, like '+'
    LastChar = getchar();
    return ThisChar;
}