typedef enum {courseAttr,classAttr,meetingAttr,itemAttr}attrType;
typedef enum {meeting,course,class,item}listType;
typedef enum {COURSE, CONSTRAINT}ELEMTYPE;
typedef enum {CRN,CODE}itemAttrType;

typedef struct{

  int crncnt;
  int codecnt;
  
}constNode;
  
typedef struct{
 
}courseNode;


typedef struct{

  ELEMTYPE thisElemType;
  wildCard *node;
  //elementNode *elemNodePtr;
  struct TreeNode *next;
  //bu galiba elementList
}TreeNode;

typedef union{
  courseNode course;
  constNode constraint;
}wildCard;

/*

typedef struct{
  itemAttrType type;
  int count; //buralar daha cok gelisicek
  struct itemNode *next;
}itemNode;

typedef struct{
  itemNode *itemList;
}constNode;

typedef union{
  //courseNode course;
  constNode  constraint;

}elementNode;

typedef struct{
  ELEMTYPE type;
  elementNode *elems;

}elementList;

typedef struct{

  elementList *elems;

}program;

typedef struct{
  courseAttrNode attrlist;
  classListNode classes;
}courseNode;

typedef struct{
  elementList *next = nullptr;
  elementNode  elem;
  
}elementList;

typedef struct{
  int codeCount;
  int typeCount;
  int nameCount;
}courseAttrNode;


typedef struct{
  int codeCount;
  int typeCount;
  int nameCount;
}classAttrNode;

typedef struct{
  int codeCount;
  int typeCount;
  int nameCount;
}meetingAttrNode;
*/

