#ifndef HW4_HEADER
#define  HW4_HEADER
 

typedef enum {COURSE, CONSTRAINT,MEETING,CODE,TYPE,NAME,CLASS,ITEM}ELEMTYPE;//MORE TO COME


typedef struct{
  ELEMTYPE type;
 struct Attribute *next;
}Attribute;
typedef struct{
  int crncnt;
  int codecnt;
}constNode;


typedef struct{
  struct Attribute *attr;
  struct TreeNode *classes;
  
}
  
  courseNode;


typedef struct{
  struct TreeNode *attribs;
  struct TreeNode *meetings;
  int section;
  int instructor;
  int crn;
  int capacity;
}
  classNode;

typedef struct{
  struct TreeNode *attribs;
  int start;
  int end;
  int day; 
}
  meetNode;
typedef struct{}itemNode;
typedef union{
 courseNode course;
 constNode constraint;
 classNode class;
 meetNode meeting;
 itemNode item;
 }wildCard;

typedef struct TreeNode{
  ELEMTYPE thisElemType;
  wildCard *node;
  struct TreeNode *next;
}TreeNode;

#endif
