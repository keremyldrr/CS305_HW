
%{
#include <stdio.h>
#include <string.h>
#include "hw4.h"
  void yyerror(const char *s){//called by yyparse on error
    printf("%s\n", s);
  }
  TreeNode *rootPtr;
  TreeNode * genConst(int crn);
  TreeNode * genCourse(Attribute *,TreeNode *);
  TreeNode *mergeClass(TreeNode *,TreeNode *);
  TreeNode *genClass(Attribute *,TreeNode *);
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
%type <treeptr> classList
%type <treeptr> class
%type <treeptr> meetingList
%type <treeptr> meeting
%type <attr> beginCourse
%type <attr> classAttrList
%type <attr> classAttr
%type <attr> meetingAttrList
%type <attr> meetingAttr
%token tOPEN tCOURSE tCLOSE tEND tCODE tCLASS  tNAME tTYPE tSTRING tSECTION  tINSTRUCTOR tCRN  tCAPACITY tMEETING tSELF tDAY tSTART tTIME  tEND_A tMON  tTUE  tWED  tTHU  tFRI tCONSTRAINT tITEM 
%token <crn> tNUM
%%
prog :  elementList | ;
elementList :  element{rootPtr = $1;} | element elementList;
element : beginCourse classList endCourse{$$ = genCourse($1,$2);} | beginConstraint itemList endConstraint;
beginCourse : tOPEN tCOURSE courseAttrList tCLOSE {$$ = $3;};
endCourse : tEND tCOURSE tCLOSE;
courseAttrList :  courseAttr{ $$ = connectAttr($1,NULL); } |  courseAttr  courseAttrList {$$ = connectAttr($1,$2);};
courseAttr : tCODE tSTRING {$$ = makeAttr(CODE);}| tNAME tSTRING{$$=makeAttr(NAME);}|tTYPE tSTRING{$$=makeAttr(TYPE); };
classList : class{$$ =mergeClass($1,NULL);printf("generate %d \n",$1->thisElemType);}

| class classList{$$ = mergeClass($1,$2);printf("merge %d\n",($2->thisElemType));};

class :  beginClass classAttrList endClass meetingList closeClass {$$ = genClass($2,NULL);};
beginClass  : tOPEN tCLASS;
endClass :  tCLOSE;
closeClass : tEND tCLASS tCLOSE;
classAttrList :  classAttr {$$ = connectAttr($1,NULL);} | classAttr classAttrList {$$= connectAttr($1,$2);};
classAttr : tSECTION tSTRING {$$ = makeAttr(SECTION); printf("%d \n",$$->type);}| tINSTRUCTOR tSTRING {$$ = makeAttr(INSTRUCTOR); }|tCRN tNUM {$$ = makeAttr(CRN);}| tCAPACITY tNUM {$$ = makeAttr(CAPACITY);};
 meetingList : meeting {$$=NULL;} |meeting  meetingList {$$ = NULL;};
 meeting : beginMeeting meetingAttrList endMeeting{$$=NULL;};
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
  ret->next = NULL;

  return ret;

}

Attribute * connectAttr(Attribute *a1,Attribute *a2){
  
  
  a1->next = a2;
  return a1;



}
 TreeNode* genCourse(Attribute *attributes,TreeNode *classes)
{
  /*while(attributes)
    {
      printf("ATTR  %d\n ",attributes->type);
      attributes= attributes->next;
    }
   while(classes)
    {
      printf("CLS  %d\n ",classes->thisElemType);

      classes= classes->next;
      }*/
  
  TreeNode *ret = (struct TreeNode *)malloc(sizeof(TreeNode));
  ret ->thisElemType = COURSE;
  ret->node = (wildCard *)malloc(sizeof(wildCard));
  Attribute *p = (Attribute *)malloc(sizeof(Attribute));
  p->type = attributes->type;
  ret->node->course.attr = p;
  attributes = attributes->next;
  
  while(attributes != NULL)
    {
      p->next = (Attribute *)malloc(sizeof(Attribute));
      
      p->next->type =  attributes->type;
      p = p->next;
      attributes = attributes->next;
      
      
    }
  
  //
  
  TreeNode *p2 = (TreeNode *)malloc(sizeof(TreeNode));
  ret->node->course.classes = p2;
  p2->thisElemType = CLASS;
  p2->node = (wildCard *)malloc(sizeof(wildCard));
  p2->node->class.attr = classes->node->class.attr;
  classes = classes->next;
  printf("ks");
  while(classes != NULL)
    {
      printf("ks");
      p2->next = (TreeNode *)malloc(sizeof(TreeNode));
      
      p2->next->thisElemType =  CLASS;
      p2->next->node = (wildCard *)malloc(sizeof(wildCard));
      p2->next->node->class.attr = classes->node->class.attr;
      p2 = p2->next;

      classes = classes->next;
      
      
    }



    
 
  return ret;
}


TreeNode *mergeClass(TreeNode *a1,TreeNode *a2){

  //TreeNode *ptr = (TreeNode *)malloc(sizeof(TreeNode));
  printf("anan %d %d \n ",(a1 == NULL),(a2 == NULL)); 
  // ptr->node = a1->node;
  //if(a2 == NULL)
  //  ptr->next= NULL;
  //else
  //ptr->next = a2;
    //memmove(ptr->next,a2,sizeof(TreeNode));
  a1->next = a2;
  //birden fazla class problemli, meetingler ve itemlardan sonra ilk kisim hallolucak.
  //birden fazla course da dene!!!
  return a1;
  
}
TreeNode *genClass(Attribute * attributes,TreeNode *meetings){
  
  TreeNode *ret = (TreeNode *)malloc(sizeof(TreeNode));
  ret->thisElemType = CLASS;
  
  Attribute *p = (Attribute *)malloc(sizeof(Attribute));
  
  ret->node = (wildCard *)malloc(sizeof(wildCard));
  p = attributes;
  ret->node->class.attr = p;
  p->type = attributes->type;
  
  attributes = attributes->next;
  ret->next = NULL;
  ret->node->class.meetings = meetings;
  while(attributes != NULL)
    {
      
      p->next = (Attribute *)malloc(sizeof(Attribute));
      
      p->next->type =  attributes->type;
      p = p->next;
      attributes = attributes->next;

      
    }

  //set meetings here
  return ret;
}

int main(){
  
  if(yyparse()){
    printf("ERROR\n");
		return 1;		
  }else{
    printf("OK\n");
    
    TreeNode *p = rootPtr->node->course.classes;
    while(p != NULL)
      {
	printf("%d cls  \n",p->thisElemType);
	Attribute *pp = p->node->class.attr;
	while(pp != NULL)
	  {
	    printf("attr %d \n",pp->type);
	    pp = pp->next;
	  }
	p = p->next;
	}
    
    return 0;
  }	
} 
