#ifndef HW4_HEADER
#define  HW4_HEADER
 

typedef enum {COURSE, CONSTRAINT,MEETING,CODE,TYPE,NAME,CLASS,ITEM}ELEMTYPE;//MORE TO COME


typedef struct Attribute{
  ELEMTYPE type;
  struct Attribute *next;
}Attribute;

typedef struct constNode{
  int crncnt;
  int codecnt;
}constNode;


typedef struct courseNode{
  struct Attribute *attr;
  struct TreeNode *classes;
  
}courseNode;


typedef struct classNode{
  struct Attribute *attr;
  struct TreeNode *meetings;
}classNode;

typedef struct meetNode{
  struct TreeNode *attribs;
  int start;
  int end;
  int day; 
}meetNode;
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
