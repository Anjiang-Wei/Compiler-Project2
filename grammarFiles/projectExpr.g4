grammar projectExpr;

prog    : pBegin ;
pBegin  : stmt pBeginR ;
pBeginR : stmt pBeginR
	    |
	    ;
stmt    : lhs '=' rhsE ';' ;
lhs     : tRef ;
rhsE    : rhsI rhsER;
rhsER	: '+' rhsE
        | '-' rhsE
	    |
	    ;
rhsI	: '(' rhsE ')' rhsIR
        | tRef rhsIR
        | sRef rhsIR
        | conVal rhsIR
	    ;
rhsIR	: '*' rhsI
        | '/' rhsI 
        | '%' rhsI 
        | '//' rhsI
	    |
	    ;
tRef    : ID '<' cList '>' '[' aList ']';
sRef    : ID '<' cList '>';
cList   : IntV cListR;
cListR	: ',' IntV cListR
	    |
	    ;
aList   : idExprE aListR;
aListR	: ',' idExprE aListR
	    |
	    ;
idExprE	: idExprI idExprER;
idExprER	: '+' idExprE
		| '-' idExprE
		|
		;
idExprI	: ID idExprIR
	    | '(' idExprE ')' idExprIR
	    | IntV idExprIR
	    ;
idExprIR	: '*' idExprI
		| '//' idExprI
		| '%' idExprI
		|
		;
conVal  : FloatV
        | IntV
        ;
IntV    : [0-9]+ ;
FloatV  : [0-9]+ '.' [0-9]* ;
WS      : [ \t\r\n]+ -> skip ;
ID      : [a-zA-Z_] [a-zA-Z0-9_]* ;
