/****************************************************************************************//**

 Author of this file is
     __________ _______   __   _____ __ __________ _____ __ __ _____ ______   __ ____   
    / _   _   // ___  /__/ /_ / ___ / // _   _   // ___ / // //____// ____ \ / //___ \  
   / / / / / // /__/_//_  __// /  /  // / / / / // /  /  //   /    / /___/_//   /__/_/  
  / / / / / // /_____  / /_ / /__/  // / / / / // /__/  // /\ \__ / /_____ / /\ \__     
 /_/ /_/ /_/ \______/  \__/ \____/_//_/ /_/ /_/ \____/_//_/  \___/\______//_/  \___/    
                                                                                         
 webpage: http://www.goblinov.net
 email: guru@goblinov.net   

 This file is provided under certain circumstances. For more details see LICENSE file in
 the project's root folder.
  
 \author metamaker
 \brief 
 
 Symbol describes some variable or function which is used in program.
 
********************************************************************************************/

#ifndef C_SHARP_SYMBOL
#define C_SHARP_SYMBOL

#include <string>
#include <vector>
#include <map>

#include "Lexem.h"

using std::string;
using std::vector;
using std::map;

struct SymbolMethod;
struct MethodArgument;
struct SymbolVariable;
struct CodeBlock;

struct SymbolClass
{
    string name;

    map<string, SymbolMethod> functions;
};

struct SymbolMethod
{
    string modifier;
    string returnType;
    string name;
    map<string, MethodArgument> parameters;

    vector<CodeBlock> blocks;
};

struct MethodArgument
{
    string type;
    string name;
};

struct CodeBlock
{
    map<string, SymbolVariable> variables;

    vector<CodeBlock> childrenBlocks;
    CodeBlock* parentBlock;

    int openingBracketPosition;
    int closingBracketPosition;
};

struct SymbolVariable
{
    string type;
    string name;
    int tokenValueStart;
    int tokenValueEnd;
    int variableVisibilityStart;

    int triadId;

    string value;
};

#endif // C_SHARP_SYMBOL