 
%{
#include <stdio.h>
#include <string.h>
#include "hw4.h"
  void yyerror(const char *s){//called by yyparse on error
    printf("%s\n", s);
  }
  TreeNode *rootPtr;
  int searchElement(char q[100]);
  TreeNode * genConst(int crn);
  TreeNode * genCourse(Attribute *,TreeNode *);
  TreeNode *mergeClass(TreeNode *,TreeNode *);
  TreeNode *mergeItem(TreeNode *,TreeNode *);
  TreeNode *mergeCourse(TreeNode *,TreeNode *);
  TreeNode *genClass(Attribute *,TreeNode *);
  int semanticCheck();
  TreeNode *genConstraint(TreeNode *);
  TreeNode *genMeeting(Attribute *);
    TreeNode *genItem(Attribute *);
  TreeNode *mergeMeet(TreeNode *,TreeNode *);
  Attribute *makeAttr(ELEMTYPE,Tracker,int);
  Attribute *connectAttr(Attribute *,Attribute *);
  void printTree(TreeNode *);
  char *dicty[15] =  {"COURSE", "CONSTRAINT","MEETING","CODE","TYPE","NAME","CLASS","ITEM","SECTION","CAPACITY","CRN","INSTRUCTOR","START","END_T","DAY"};//MORE TO COME     
  char *definedElements[1000];
  int current_index = 0;
  int size(char *);
  void pretty_print();
    %}
%union {
  Tracker coll;
  TreeNode *treeptr;
  Attribute *attr;
}


%type <attr> courseAttr
%type <attr> courseAttrList
%type <treeptr> elementList
%type <treeptr> element
%type <treeptr> classList
%type <treeptr> class
%type <treeptr> itemList
%type <treeptr> item
%type <treeptr> meetingList
%type <treeptr> meeting
%type <attr> beginCourse
%type <attr> classAttrList
%type <attr> classAttr
%type <attr> meetingAttrList
%type <attr> meetingAttr
%type <attr> itemAttr
%type <coll> beginClass

%type <coll> day
%token <coll> tSTRING
%token <coll> tMON
%token <coll> tTUE
%token <coll> tWED
%token <coll> tTHU
%token <coll> tFRI
%token <coll> tNUM
%token <coll> tTIME
 //add dem nums
%token <coll> tMEETING
%token <coll> tCOURSE
%token <coll> tCLASS
%token tOPEN  tCLOSE tEND tCODE  tNAME tTYPE  tSECTION  tINSTRUCTOR tCRN  tCAPACITY tSELF tDAY tSTART tEND_A tCONSTRAINT tITEM

%%
prog :  elementList {rootPtr = $1;} | ;
elementList :  element{$$ = mergeCourse($1,NULL);} | element elementList{$$ = mergeCourse($1,$2); };
element : beginCourse classList endCourse{$$ = genCourse($1,$2);} | beginConstraint itemList endConstraint {$$ = genConstraint($2);};
beginCourse : tOPEN tCOURSE courseAttrList tCLOSE {$$ = $3;printf("OLALA %d \n",$2.lineNum);};
endCourse : tEND tCOURSE tCLOSE;
courseAttrList :  courseAttr{ $$ = connectAttr($1,NULL); } |  courseAttr  courseAttrList {$$ = connectAttr($1,$2);};
courseAttr : tCODE tSTRING {$$ = makeAttr(CODE,$2,0);}| tNAME tSTRING{$$=makeAttr(NAME,$2,0);}|tTYPE tSTRING{$$=makeAttr(TYPE,$2,0); };
classList : class{$$ =mergeClass($1,NULL);}

| class classList{$$ = mergeClass($1,$2);};

class :  beginClass classAttrList endClass meetingList closeClass {$$ = genClass($2,$4);};
beginClass  : tOPEN tCLASS;
endClass :  tCLOSE;
closeClass : tEND tCLASS tCLOSE;
classAttrList :  classAttr {$$ = connectAttr($1,NULL);} | classAttr classAttrList {$$= connectAttr($1,$2);};
classAttr : tSECTION tSTRING {$$ = makeAttr(SECTION,$2,0);}| tINSTRUCTOR tSTRING {$$ = makeAttr(INSTRUCTOR,$2,0); }|tCRN tNUM {$$ = makeAttr(CRN,$2,0);}| tCAPACITY tNUM {$$ = makeAttr(CAPACITY,$2,0);};
meetingList : meeting {$$=mergeMeet($1,NULL);} |meeting  meetingList {$$ = mergeMeet($1,$2);};
meeting : beginMeeting meetingAttrList endMeeting{$$=genMeeting($2);};
beginMeeting :  tOPEN tMEETING ;
endMeeting :tSELF ;
meetingAttrList : meetingAttr{$$ = connectAttr($1,NULL);} | meetingAttr meetingAttrList {$$ = connectAttr($1,$2);};
meetingAttr : tDAY day {$$ = makeAttr(DAY,$2,0);} | tSTART tTIME {$$ = makeAttr(START,$2,0);} | tEND_A tTIME{$$ = makeAttr(END_T,$2,0);};
day : tMON  | tTUE  | tWED  | tTHU | tFRI;
beginConstraint : tOPEN tCONSTRAINT tCLOSE;
endConstraint : tEND tCONSTRAINT  tCLOSE;
itemList :  item {$$ = mergeItem($1,NULL);} | item itemList {$$ = mergeItem($1,$2);};
item :  beginItem itemAttr endItem {$$ = genItem($2);};
beginItem : tOPEN tITEM;
endItem : tSELF;
itemAttr: tCODE tSTRING {$$ = makeAttr(CODE,$2,1);}| tCRN tNUM {$$ = makeAttr(CRN,$2,1);} ;
%%
TreeNode *genItem(Attribute *attrs){

  TreeNode *ret = (TreeNode *)malloc(sizeof(TreeNode));
  ret->thisElemType = ITEM;
  ret->node = (wildCard *)malloc(sizeof(wildCard));
  ret->node->item.attr = attrs;
  ret->next = NULL;

  return ret;
}
int searchElement(char elem[100]){
  for(int i = 0;i<current_index+1 && definedElements[i]!=NULL;i++)
    {
      //      printf("ALALALA %s %s\n",definedElements[i],elem);
      

      int res = strcmp( definedElements[i],elem);
      if(res == 0)
	return 1;
      


    }

  return 0;


}
int semanticCheck(){
  int ret = 1;
  TreeNode *ptr = rootPtr;
  while(ptr){
    //printf("%s \n",dicty[ptr->thisElemType]);
    if(ptr->thisElemType == COURSE)
      {
	// printf("here we go \n");
	courseNode current = ptr->node->course;
	int codeCount = 0;
	int nameCount = 0;
	int typeCount = 0;
	Attribute *attrs  = current.attr;
	int ck1 = 0;
	int ck2 = 0;
	int ck3 = 0;
	while(attrs !=NULL){
	  ELEMTYPE ch;
	  ch = attrs->type;
	  if(ch == CODE)
	    codeCount+=1;
	  else if(ch==NAME)
	    nameCount +=1;
	  else if(ch == TYPE)
	    typeCount+=1;
	  attrs = attrs->next;
	} 
	if(typeCount>1 || typeCount < 1 && ck1 == 0)
	  {
	    printf("ERROR: course element at line %d has %d occurrences of type type \n",current.attr->lineNumber,typeCount);
	    ck1=1;
	    ret = 0;
	  }	
	if(codeCount>1 || codeCount < 1 && ck2 == 0)
	  {
	    printf("ERROR: course element at line %d has %d occurrences of type code \n",current.attr->lineNumber,codeCount);
	    ck2 = 1;
	    ret = 0;
	  }
	if(nameCount>1 || nameCount < 1 && ck3 == 0)
	  {
	  printf("ERROR: course element at line %d has %d occurrences of type name \n",current.attr->lineNumber,nameCount);
	  ck3 = 1;
	  ret = 0;
	  }
	
	//CLASS CHECK
	
	TreeNode *cls_list = current.classes;
	
	while(cls_list != NULL){

	  int section = 0;
	  int inst = 0;
	  int crn = 0;
	  int cap = 0;
	  ck1 = ck2 = ck3 = 0;
	  int ck4 = 0;
	  attrs = cls_list->node->class.attr;
	  while(attrs !=NULL){
	    ELEMTYPE ch;
	    ch = attrs->type;
	  if(ch == SECTION)
	    section+=1;
	  else if(ch==INSTRUCTOR)
	    inst +=1;
	  else if(ch == CAPACITY)
	    cap+=1;
	  else if(ch == CRN)
	    crn+=1;
	
	  attrs = attrs->next;
	  }
	  
	if(section>1 || section < 1 && ck1 == 0)
	  {
	    printf("ERROR: class element at line %d has %d occurrences of type section \n",cls_list->node->class.attr->lineNumber,section);
	    ck1=1;
	    ret = 0;
	  }	
	if(inst>1 || inst < 1 && ck2 == 0)
	  {
	    printf("ERROR: class element at line %d has %d occurrences of type instructor \n",cls_list->node->class.attr->lineNumber,inst);
	    ck2 = 1;
	    ret = 0;
	  }
	if(cap>1 || cap < 1 && ck3 == 0)
	  {
	    printf("ERROR: class element at line %d has %d occurrences of type capacity \n",cls_list->node->class.attr->lineNumber,cap);
	  ck3 = 1;
	  ret = 0;
	  }
	if(crn>1 || crn < 1 && ck4 == 0)
	  {
	    printf("ERROR: class element at line %d has %d occurrences of type name \n",cls_list->node->class.attr->lineNumber,crn);
	    ck4 = 1;
	    ret = 0;}

	
	//check for meetings here
	TreeNode *meety = cls_list->node->class.meetings;
	while(meety != NULL){
	  int lineNum = meety->node->meeting.attr->lineNumber;
	  int start = 0;
	  int end = 0;
	  int day = 0;
	  ck1 = ck2 = ck3 = 0;
	  attrs = meety->node->meeting.attr;
	  while(attrs != NULL)
	    {
	      ELEMTYPE ch;
	      ch = attrs->type;
	      if(ch == START)
		start+=1;
	      else if(ch==END_T)
		end +=1;
	      else if(ch == DAY)
		day+=1;
	      
	      attrs = attrs->next;
	      
	    }
	  ///////////////////////////////////
	  if(start>1 || start < 1 && ck1 == 0)
	    {
	      printf("ERROR: meeting element at line %d has %d occurrences of type start \n",lineNum,start);
	      ck1=1;
	      ret = 0;
	    }	
	  if(end>1 || end < 1 && ck2 == 0)
	    {
	      printf("ERROR: meeting  element at line %d has %d occurrences of type end \n",lineNum,end);
	      ck2 = 1;
	      ret = 0;
	    }
	  if(day>1 || day < 1 && ck3 == 0)
	    {
	      printf("ERROR: meeting element at line %d has %d occurrences of type day \n",lineNum,day);
	      ck3 = 1;
	    ret = 0;
	    }
	  
	  
	  
	  ///////////////////////////////////
	  meety = meety->next;
	}
	cls_list = cls_list->next;
	}
      }
    else{
      
      TreeNode * items = ptr->node->constraint.items;
      
      while(items != NULL){
	Attribute *curr  = items->node->item.attr;
	
	
	if(curr->type == CRN)
	  {
	    if(searchElement(curr->str) == 0)
	      {
		printf("ERROR: constraint at line %d refers to an  undefined crn= \n",curr->lineNumber);
		ret = 0;
	      }
	    
	    
	  }
	else if(curr->type == CODE){
	  //printf("item CODE %s \n",curr->str);
	  if(searchElement(curr->str) == 0)
	    {
	      printf("ERROR: constraint at line %d refers to an  undefined code= \n",curr->lineNumber);
	      ret = 0;
	    }
	}
	//constraint thingy here
	items = items->next;
      }
    }
    ptr = ptr->next;
  }
  return ret;
}
TreeNode *genConstraint(TreeNode *items){
  
  TreeNode *ret = (struct TreeNode *)malloc(sizeof(TreeNode));
  ret ->thisElemType = CONSTRAINT;
  ret->node = (wildCard *)malloc(sizeof(wildCard));
  ret->node->constraint.items = items;
  ret->next = NULL;
  return ret;



}

Attribute * makeAttr(ELEMTYPE elem,Tracker tr,int flag){

  //printf("WOWAWO %s %d %s \n",dicty[elem],flag,tr.str);
  if( (elem == CODE  || elem == CRN) && (flag != 1))
    {
      //      printf("adding %s \n ",tr.str);
      definedElements[current_index]=(char *)malloc(sizeof(char)*100);
      strcpy(definedElements[current_index], tr.str);
      current_index++;

    }
  Attribute *ret = (Attribute *)malloc(sizeof(Attribute));
  ret->type = elem;
  ret->next = NULL;
  ret->lineNumber = tr.lineNum;
  // printf("%d NUMLINE",ret->lineNumber);
  //&ret->str[0] = (char *)malloc(sizeof(char)*100);
  strcpy(ret->str,tr.str);
  //printf("%s %s \n ",ret->str,dicty[elem]);
  //  memset(&strink[0], 0, sizeof(char)*100);

  return ret;

}
void pretty_print(){
  TreeNode *ptr = rootPtr;
  while(ptr){
    //printf("%s \n",dicty[ptr->thisElemType]);
    if(ptr->thisElemType == COURSE)
      {
	courseNode current = ptr->node->course;
	printf("<course");
	Attribute *attrs  = current.attr;

	while(attrs !=NULL){
	  ELEMTYPE ch;
	  ch = attrs->type;
	  if(ch == CODE)
	    printf(" code=%s",attrs->str);
	  else if(ch==NAME)
	    printf(" name=%s",attrs->str);//nameCount +=1;
	  else if(ch == TYPE)
	    printf(" type=%s",attrs->str);
	  attrs = attrs->next;
	}
	printf(">\n");
	//CLASS CHECK
	TreeNode *cls_list = current.classes;
	while(cls_list != NULL){
	  printf("\t<class");
	  attrs = cls_list->node->class.attr;
	  while(attrs !=NULL){
	    ELEMTYPE ch;
	    ch = attrs->type;
	  if(ch == SECTION)
	    printf(" section=%s",attrs->str);//section+=1;
	  else if(ch==INSTRUCTOR)
	    printf(" instructor=%s",attrs->str);//inst +=1;
	  else if(ch == CAPACITY)
	    printf(" capacity=%s",attrs->str);//cap+=1;
	  else if(ch == CRN)
	    printf(" crn=%s",attrs->str);//crn+=1;
	  attrs = attrs->next;
	  }
	  printf(">\n");
	//check for meetings here
	TreeNode *meety = cls_list->node->class.meetings;
	while(meety != NULL){
	  printf("\t\t<meeting");
	  attrs = meety->node->meeting.attr;
	  while(attrs != NULL)
	    {
	      ELEMTYPE ch;
	      ch = attrs->type;
	      if(ch == START)
		printf(" start=%s",attrs->str);//start+=1;
	      else if(ch==END_T)
		printf(" end=%s",attrs->str);//end +=1;
	      else if(ch == DAY)
		printf(" day=%s",attrs->str);//day+=1;
	      attrs = attrs->next;
	    }
	  printf("/>\n");
	  meety = meety->next;
	}
	cls_list = cls_list->next;
	printf("\t</class>\n");
	}
	printf("</course>\n");	

      }
    ptr = ptr->next;
  }
  TreeNode *qq = rootPtr;
  
  while(qq!=NULL)
    {
      if(qq->thisElemType == CONSTRAINT){
	printf("<constraint>\n");
	TreeNode * items = qq->node->constraint.items;
	
	while(items != NULL){
	Attribute *curr  = items->node->item.attr;
	
	
	if(curr->type == CRN)
	  {
	    printf("\t<item crn=%s/>\n",curr->str);
	  }
	else if(curr->type == CODE){
	  printf("\t<item code=%s/>\n",curr->str);
	}
	//constraint thingy here
	items = items->next;
	}
	printf("<constraint/>\n");	
      }

      qq = qq->next;
    }
  return 1;
    
    
    
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
TreeNode *mergeItem(TreeNode *a1,TreeNode *a2){
  
  a1->next = a2;
  return a1;
  
}
TreeNode *mergeCourse(TreeNode *a1,TreeNode *a2){
  
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
    printf("SYNTAX OK\n");

       int check = semanticCheck();
       //     semanticCheck();
    /* for(int i=0;i<1000 && definedElements[i]!=NULL;i++)
       printf("%s \n",definedElements[i]);*/
       if(check)
	 pretty_print();
    


    return 0;
  }	
} 
