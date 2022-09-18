#include "ast.h"

std::unique_ptr<ExprAST> ParseExpression();         // INTERFACE

std::unique_ptr<ExprAST> ParseBinOpRHS(int ExprPrec, 
                        std::unique_ptr<ExprAST> LHS);  // parse and merge BinopExpr

// paser guide: 
//      1. Number 2. Identifier 3. ParentExpr
std::unique_ptr<ExprAST> ParsePrimary();

std::unique_ptr<ExprAST> ParseNumberExpr();         // number
std::unique_ptr<ExprAST> ParseIdentifierExpr();     // var or function Call
std::unique_ptr<ExprAST> ParseParentExpr();         // `(` expr `)`


std::unique_ptr<PrototypeAST> ParsePrototype();     // function prototype
std::unique_ptr<FunctionAST> ParseDefinition();     // `def`

std::unique_ptr<FunctionAST> ParseTopLevelExpr();   // direct expr

std::unique_ptr<PrototypeAST> ParseExtern();         // extern