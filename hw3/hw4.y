 
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
  TreeNode *genMeeting(Attribute *);
  TreeNode *mergeMeet(TreeNode *,TreeNode *);
  Attribute *makeAttr(ELEMTYPE,char strink[100]);
  Attribute *connectAttr(Attribute *,Attribute *);
  void printTree(TreeNode *);
  char *dicty[15] =  {"COURSE", "CONSTRAINT","MEETING","CODE","TYPE","NAME","CLASS","ITEM","SECTION","CAPACITY","CRN","INSTRUCTOR","START","END_T","DAY"};//MORE TO COME     

  int size(char *);
    %}
%union {
  char  str[100];
  int lineNum;//buralar degiscek
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

%type <str> day

%token <str> tSTRING
%token <str> tMON
%token <str> tTUE
%token <str> tWED
%token <str> tTHU
%token <str> tFRI
%token <str> tNUM
%token <str> tTIME
%token tOPEN tCOURSE tCLOSE tEND tCODE tCLASS  tNAME tTYPE  tSECTION  tINSTRUCTOR tCRN  tCAPACITY tMEETING tSELF tDAY tSTART tEND_A tCONSTRAINT tITEM

%%
prog :  elementList | ;
elementList :  element{rootPtr = $1;} | element elementList;
element : beginCourse classList endCourse{$$ = genCourse($1,$2);} | beginConstraint itemList endConstraint;
beginCourse : tOPEN tCOURSE courseAttrList tCLOSE {$$ = $3;};
endCourse : tEND tCOURSE tCLOSE;
courseAttrList :  courseAttr{ $$ = connectAttr($1,NULL); } |  courseAttr  courseAttrList {$$ = connectAttr($1,$2);};
courseAttr : tCODE tSTRING {$$ = makeAttr(CODE,$2);}| tNAME tSTRING{$$=makeAttr(NAME,$2);}|tTYPE tSTRING{$$=makeAttr(TYPE,$2); };
classList : class{$$ =mergeClass($1,NULL);}

| class classList{$$ = mergeClass($1,$2);};

class :  beginClass classAttrList endClass meetingList closeClass {$$ = genClass($2,$4);};
beginClass  : tOPEN tCLASS;
endClass :  tCLOSE;
closeClass : tEND tCLASS tCLOSE;
classAttrList :  classAttr {$$ = connectAttr($1,NULL);} | classAttr classAttrList {$$= connectAttr($1,$2);};
classAttr : tSECTION tSTRING {$$ = makeAttr(SECTION,$2);}| tINSTRUCTOR tSTRING {$$ = makeAttr(INSTRUCTOR,$2); }|tCRN tNUM {$$ = makeAttr(CRN,$2);}| tCAPACITY tNUM {$$ = makeAttr(CAPACITY,$2);};
meetingList : meeting {$$=mergeMeet($1,NULL);} |meeting  meetingList {$$ = mergeMeet($1,$2);};
meeting : beginMeeting meetingAttrList endMeeting{$$=genMeeting($2);};
beginMeeting :  tOPEN tMEETING ;
endMeeting :tSELF ;
meetingAttrList : meetingAttr{$$ = connectAttr($1,NULL);} | meetingAttr meetingAttrList {$$ = connectAttr($1,$2);};
meetingAttr : tDAY day {$$ = makeAttr(DAY,$2);} | tSTART tTIME {$$ = makeAttr(START,$2);} | tEND_A tTIME{$$ = makeAttr(END_T,$2);};
day : tMON  | tTUE  | tWED  | tTHU | tFRI;
beginConstraint : tOPEN tCONSTRAINT tCLOSE;
endConstraint : tEND tCONSTRAINT  tCLOSE;
itemList :  item | item itemList;
item :  beginItem itemAttr endItem;
beginItem : tOPEN tITEM;
endItem : tSELF;
itemAttr: tCODE tSTRING | tCRN tNUM ;
%%
Attribute * makeAttr(ELEMTYPE elem,char strink[100]){
  
  Attribute *ret = (Attribute *)malloc(sizeof(Attribute));
  ret->type = elem;
  ret->next = NULL;
  //&ret->str[0] = (char *)malloc(sizeof(char)*100);
  strcpy(ret->str,strink);
  printf("%s %s \n ",ret->str,dicty[elem]);
  memset(&strink[0], 0, sizeof(char)*100);

  return ret;

}

Attribute * connectAttr(Attribute *a1,Attribute *a2){
  
  
  a1->next = a2;
  return a1;



}
 TreeNode* genCourse(Attribute *attributes,TreeNode *classes)
{
  TreeNode *ret = (struct TreeNode *)malloc(sizeof(TreeNode));
  ret ->thisElemType = COURSE;
  ret->node = (wildCard *)malloc(sizeof(wildCard));
  ret->node->course.attr =attributes;
  ret->node->course.classes = classes;
 
  return ret;
}


TreeNode *mergeClass(TreeNode *a1,TreeNode *a2){
  
  a1->next = a2;
  return a1;
  
}
TreeNode *genClass(Attribute * attributes,TreeNode *meetings){
  
  TreeNode *ret = (TreeNode *)malloc(sizeof(TreeNode));
  ret->thisElemType = CLASS;
  
  Attribute *p = (Attribute *)malloc(sizeof(Attribute));
  
  ret->node = (wildCard *)malloc(sizeof(wildCard));
  
  ret->node->class.attr = attributes;

  ret->node->class.meetings = meetings;


  //set meetings here
  return ret;
}
TreeNode *mergeMeet(TreeNode *a1,TreeNode *a2){
  a1->next = a2;
  return a1;
  
}
TreeNode *genMeeting(Attribute * attributes){
  
  TreeNode *ret = (TreeNode *)malloc(sizeof(TreeNode));
  ret->thisElemType = MEETING;
  
 
  
  ret->node = (wildCard *)malloc(sizeof(wildCard));
 
  ret->node->meeting.attr = attributes;  
  return ret;
}
int size(char *ptr){
  //variable used to access the subsequent array elements.
  int offset = 0;
  //variable that counts the number of elements in your array
  int count = 0;

  //While loop that tests whether the end of the array has been reached
  while (*(ptr + offset) != '\0')
    {
      //increment the count variable
      ++count;
      //advance to the next element of the array
      ++offset;
    }
    //return the size of the array
  return count;
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
	    printf("clsattr %d \n",pp->type);
	    pp = pp->next;
	  }
	TreeNode *pp2 = p->node->class.meetings;
	while(pp2!= NULL)
	  {

	    Attribute * pp3 = pp2->node->meeting.attr;
	    while(pp3 != NULL)
	      {
		//		printf("meetattr %s \n",pp3->str);
		pp3 = pp3->next;
	      }
	    printf("\n");
	    pp2 = pp2->next;
	  }
	p = p->next;
	}
    
    return 0;
  }	
} 
