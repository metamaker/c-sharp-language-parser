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
 
 Parse tree and utility functions for it.
 
********************************************************************************************/

#ifndef C_SHARP_PARSE_TREE_H
#define C_SHARP_PARSE_TREE_H

#include "NonTerminalPositionType.h"

#include <string>
#include <ostream>

using std::string;
using std::ostream;

class SyntaxParseTree
{
public:
    struct Node {
        Node* left;
        Node* right;
        NonTerminalPositionType value;

        Node(const NonTerminalPositionType& nodeValue) : left(nullptr), right(nullptr), value(nodeValue) {}
    };

private:
    Node* m_root;

public:
    SyntaxParseTree();
    SyntaxParseTree(const SyntaxParseTree& tree);
    ~SyntaxParseTree();

    Node* GetRoot();
    const Node* GetRoot() const;

    Node* InsertChildNode(Node* parentNode, const NonTerminalPositionType& value);
    bool Empty() const;

    SyntaxParseTree& operator=(const SyntaxParseTree& tree);

private:
    void FreeNode(Node* node);

    void DeepCopyNode(const Node* from, Node* where);
};

void DisplaySyntaxParseTreeAsText(ostream& out, const SyntaxParseTree& tree);

#endif // C_SHARP_PARSE_TREE_H