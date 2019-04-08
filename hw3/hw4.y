
%{
#include <stdio.h>
#include "hw4.h"
  void yyerror(const char *s){//called by yyparse on error
    printf("%s\n", s);
  }

  TreeNode *rootPtr;
  TreeNode * genConst(int crn);
  void printTree(TreeNode *);
  
  %}

%union {

  int crn;
  TreeNode *treeptr;

}
%type <treeptr> itemAttr
%token tOPEN tCOURSE tCLOSE tEND tCODE tCLASS  tNAME tTYPE tSTRING tSECTION  tINSTRUCTOR tCRN  tCAPACITY tMEETING tSELF tDAY tSTART tTIME  tEND_A tMON  tTUE  tWED  tTHU  tFRI tCONSTRAINT tITEM 
%token <crn> tNUM
%%
prog :  elementList | ;
elementList :  element | element elementList;
element : beginCourse classList endCourse | beginConstraint itemList endConstraint;
beginCourse : tOPEN tCOURSE  courseAttrList tCLOSE;
endCourse : tEND tCOURSE tCLOSE;
courseAttrList :  courseAttr |  courseAttr  courseAttrList;
courseAttr : tCODE tSTRING | tNAME tSTRING |tTYPE tSTRING;
classList : class | class classList;
class :  beginClass classAttrList endClass meetingList closeClass;
beginClass  : tOPEN tCLASS;
endClass :  tCLOSE;
closeClass : tEND tCLASS tCLOSE;
classAttrList :  classAttr | classAttr classAttrList;
classAttr : tSECTION tSTRING | tINSTRUCTOR tSTRING |tCRN tNUM | tCAPACITY tNUM;
meetingList : meeting |meeting  meetingList;
meeting : beginMeeting meetingAttrList endMeeting;
beginMeeting :  tOPEN tMEETING ;
endMeeting :tSELF ;
meetingAttrList : meetingAttr | meetingAttr meetingAttrList;
meetingAttr : tDAY day | tSTART tTIME | tEND_A tTIME;
day : tMON | tTUE | tWED | tTHU | tFRI;
beginConstraint : tOPEN tCONSTRAINT tCLOSE;
endConstraint : tEND tCONSTRAINT  tCLOSE;
itemList :  item | item itemList;
item :  beginItem itemAttr endItem {rootPtr = $2;};
beginItem : tOPEN tITEM;
endItem : tSELF;
itemAttr: tCODE tSTRING {} | tCRN tNUM {$$ = genConst($2);};
%%

TreeNode * genConst(int crn)
{
    printf("val is %d \n",crn);
  TreeNode *ret = (TreeNode *)malloc(sizeof(TreeNode));
  ret->thisElemType = CONSTRAINT;
  ret->node = (wildCard *)malloc(sizeof(wildCard));
  ret->node->course.val = crn;

  return ret;


}
int main(){
	if(yyparse()){
		printf("ERROR\n");
		return 1;		
	}else{
		printf("OK\n");
		printf("%d ",rootPtr->node->course.val);
		return 0;
	}	
} 
