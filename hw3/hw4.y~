
%{
#include <stdio.h>
#include "hw4.h"
  void yyerror(const char *s){//called by yyparse on error
    printf("%s\n", s);
  }

  TreeNode *rootPtr;
  TreeNode * genConst(int crn);
  TreeNode * genNode(ELEMTYPE,Attribute *);
  Attribute *makeAttr(ELEMTYPE);
  Attribute *connectAttr(Attribute *,Attribute *);
  void printTree(TreeNode *);
  
  %}

%union {

  int crn;//buralar degiscek
  TreeNode *treeptr;
  Attribute *attr;
}


%type <attr> courseAttr
%type <attr> courseAttrList
%type <treeptr> elementList
%type <treeptr> element
%type <attr> beginCourse

%token tOPEN tCOURSE tCLOSE tEND tCODE tCLASS  tNAME tTYPE tSTRING tSECTION  tINSTRUCTOR tCRN  tCAPACITY tMEETING tSELF tDAY tSTART tTIME  tEND_A tMON  tTUE  tWED  tTHU  tFRI tCONSTRAINT tITEM 
%token <crn> tNUM
%%
prog :  elementList | ;
elementList :  element{rootPtr = $1;} | element elementList;
element : beginCourse classList endCourse{$$ = genNode(COURSE,$1);} | beginConstraint itemList endConstraint;
beginCourse : tOPEN tCOURSE  courseAttrList tCLOSE{$$ = $3;};
endCourse : tEND tCOURSE tCLOSE;
courseAttrList :  courseAttr{$$ = $1 ;} |  courseAttr  courseAttrList{$$ = connectAttr($1,$2);};
courseAttr : tCODE tSTRING {$$ = makeAttr(CODE);}| tNAME tSTRING{$$=makeAttr(NAME);}|tTYPE tSTRING{$$=makeAttr(TYPE);};
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
item :  beginItem itemAttr endItem;
beginItem : tOPEN tITEM;
endItem : tSELF;
itemAttr: tCODE tSTRING | tCRN tNUM ;
%%
Attribute * makeAttr(ELEMTYPE elem){

  Attribute *ret = (Attribute *)malloc(sizeof(Attribute));
  ret->type = elem;
  ret->next = 0;

  return ret;

}

Attribute * connectAttr(Attribute *a1,Attribute *a2){

  a1->next = a2;

  return a1;



}
TreeNode* genNode(ELEMTYPE type,Attribute *attributes)
{
  TreeNode *ret = (struct TreeNode *)malloc(sizeof(TreeNode));
  ret ->thisElemType = type;
  if(type == COURSE){
    ret->node = (wildCard *)malloc(sizeof(wildCard));
    Attribute *p = ret->node->course.attr;
    while(attributes != NULL)
      {
        
	p->next = (Attribute *)malloc(sizeof(Attribute));
	p->next->type =  attributes->type;
	p = p->next;
	attributes = attributes->next;
	

      }
    //    ret->node->course->attr = (Attribute *)malloc(sizeof(Attribute));
    
  }
  return ret;
}

int main(){
	if(yyparse()){
		printf("ERROR\n");
		return 1;		
	}else{
	  printf("OK\n");

	  Attribute *p;
	  
		return 0;
	}	
} 
