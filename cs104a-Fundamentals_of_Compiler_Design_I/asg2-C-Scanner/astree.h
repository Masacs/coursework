/***********************************************************************
 * $Id: astree.h,v 1.2 2011-10-22 22:57:21-07 dmfrank - $
 * Derek Frank, dmfrank@ucsc.edu
 *
 * NAME
 *   astree.h - interface file for the abstract syntax tree (AST)
 *
 * DESCRIPTIONS
 *   Abstract syntax tree.
 *
 **********************************************************************/

#ifndef __ASTREE_H__
#define __ASTREE_H__

#include "auxlib.h"

typedef struct astree_rep *astree;

bool is_astree (void *object);

astree new_astree (int symbol, int filenr, int linenr, int offset,
                   char *lexinfo);

astree adopt (astree root, /*ASTree*/ ... /*, NULL */);

astree adopt2 (astree root, astree left, astree right);

astree adopt1 (astree root, astree child);

astree adopt1sym (astree root, astree child, int symbol);

void dump_astree (FILE *outfile, astree root);

void yyprint (FILE *outfile, unsigned short toknum, astree yyvaluep);

void freeast (astree tree);

#define freeast2(T1,T2) { freeast (T1); freeast (T2); }

#endif
