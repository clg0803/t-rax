#include "parser.h"

#include <map>

static void HandleDefinition()
{
    if (ParseDefinition())
        fprintf(stderr, "Parsed a function definition.\n");
    else 
        getNextToken();
}

static void HandleExtern() {
    if (ParseExtern())
        fprintf(stderr, "Parsed an extern\n");
    else
        getNextToken();
}

static void HandleTopLevelExpression()
{
    // Evaluate a top-level expression into an anonymous function.
    if (ParseTopLevelExpr())
        fprintf(stderr, "Parsed a top-level expr\n");
    else
        getNextToken();
}

/// top ::= definition | external | expression | ';'
static void MainLoop()
{
    while (true)
    {
        fprintf(stderr, "ready> ");
        switch (CurTok)
        {
            case tok_eof:
                return;
            case ';': // ignore top-level semicolons.
                getNextToken();
                break;
            case tok_def:
                HandleDefinition();
                break;
            case tok_extern:
                HandleExtern();
                break;
            default:
                HandleTopLevelExpression();
                break;
        }
    }
}

int main()
{
    BinopPrecedence['<'] = 10;
    BinopPrecedence['+'] = 20;
    BinopPrecedence['-'] = 20;
    BinopPrecedence['*'] = 40; // highest.

    // Prime the first token.
    fprintf(stderr, "ready> ");
    getNextToken();

    // Run the main "interpreter loop" now.
    MainLoop();
    return 0;    
}