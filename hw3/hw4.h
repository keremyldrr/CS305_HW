#ifndef HW4_HEADER
#define HW4_HEADER

typedef enum {courseAttr,classAttr,meetingAttr,itemAttr}attrType;
typedef enum {meeting,course,class,item}listType;
typedef enum {COURSE, CONSTRAINT}ELEMTYPE;
typedef enum {CRN,CODE}itemAttrType;


typedef struct{
  int crncnt;
  int codecnt;
}constNode;

typedef struct{
  int val;
}
  courseNode;

typedef union{
 courseNode course;
 constNode constraint;
}wildCard;

typedef struct TreeNode{
  ELEMTYPE thisElemType;
  wildCard *node;
  struct TreeNode *next;
}TreeNode;

#endif
