%token DIGIT LETTER NL UND
%%
stmt : variable NL { 
printf("\nValid Identifier\n\n"); exit(0);}
 ;

variable : LETTER alphanumeric
 ;
alphanumeric: LETTER alphanumeric
 | DIGIT alphanumeric
 | UND alphanumeric
 | LETTER
 | DIGIT
 | UND
 ;
%%
int yyerror(char *msg)
{
 printf("\nInvalid Identifier\n");
 exit(0);
}
void main ()
{
 printf("Enter the variable name : ");
 yyparse();
} 