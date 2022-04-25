typedef enum { typeCon, typeId, typeFlt, typeBool,typeString, typeOpr } nodeEnum;
/* constants */
typedef struct {
	int value; /* value of constant */
} conNodeType;
/*float*/
typedef struct {
	float value; /* value of float */
} fltNodeType;
/* identifiers */
typedef struct {
	char i[2024]; /* subscript to sym array */
} idNodeType;
/*boolean*/
typedef struct {
	char val[2024]; /* value of bool */
} boolNodeType;
/* string */
typedef struct {
	char val[2024]; /* value of string */
} stringNodeType;
/* operators */
typedef struct {
	int oper; /* operator */
	int nops; /* number of operands */
	struct nodeTypeTag *op[1]; /* operands, extended at runtime */
} oprNodeType;
typedef struct nodeTypeTag {
	nodeEnum type; /* type of node */
union {
	conNodeType con; /* constants */
	fltNodeType flt; /* float */
	boolNodeType bool; /* boolean */
	stringNodeType str; /*string */
	idNodeType id; /* identifiers */
	oprNodeType opr; /* operators */
};
} nodeType;
extern int sym[26];
