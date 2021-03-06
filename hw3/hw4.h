#ifndef HW4_HEADER
#define  HW4_HEADER
 

typedef enum {COURSE, CONSTRAINT,MEETING,CODE,TYPE,NAME,CLASS,ITEM,SECTION,CAPACITY,CRN,INSTRUCTOR,START,END_T,DAY}ELEMTYPE;//MORE TO COME



typedef struct Attribute{
  ELEMTYPE type;
  struct Attribute *next;
  int lineNumber;
  char  str[100];
}Attribute;
//this will be corrected


typedef struct courseNode{
  struct Attribute *attr;
  struct TreeNode *classes;
  int lineNumber;
}courseNode;

typedef struct constraint{

  struct TreeNode *items;

}constNode;
typedef struct classNode{
  struct Attribute *attr;
  struct TreeNode *meetings;
  int lineNumber;
}classNode;

typedef struct meetNode{
  struct Attribute  *attr;
  int lineNumber;
}meetNode;
typedef struct{
  Attribute *attr;

}itemNode;
typedef union{
 courseNode course;
 constNode constraint;
 classNode class;
 meetNode meeting;
 itemNode item;
 }wildCard;
typedef struct Tracker{

  char str[100];
  int lineNum;

}Tracker;
typedef struct TreeNode{
  ELEMTYPE thisElemType;
  wildCard *node;
  struct TreeNode *next;
  int lineNumber;
}TreeNode;

#endif
