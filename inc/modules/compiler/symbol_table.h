#ifndef __GAMBIT_COMPILER_MODULE_SYMBOL_TABLEH
#define __GAMBIT_COMPILER_MODULE_SYMBOL_TABLEH 1

#include "common.h"
#include "modules/parser/ast/node.h"

typedef struct GambitSymbolTableNode {

  char* name;
  NODE_TYPE type;
  void* data;
  struct GambitSymbolTableNode *left, *right;

} SymbolTableNode, *SymbolTableNodePtr;

typedef struct GambitSymbolTable {

  SymbolTableNodePtr globals;
  SymbolTableNodePtr locals;
  SymbolTableNodePtr constants;

} SymbolTable, *SymbolTablePtr;

SymbolTablePtr init_symbol_table();
SymbolTableNodePtr search_symbol_table(const char *name, SymbolTableNodePtr nodep);
SymbolTableNodePtr insert_symbol_table(const char *name, SymbolTableNodePtr *nodepp);
void free_symbol_table(SymbolTablePtr table);


#endif