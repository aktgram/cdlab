%{
	int chars=0,words=0,lines=0;
%}
%%
[ ]+ {chars++;words++;}
[\n] {lines++;words++;}
.	{chars++;}
%%
int main()
{
	yylex();
        printf("chars=%d\nwords=%d\nlines=%d\n",chars
        ,words,lines);
}