%{
	#include<stdio.h>
%}
%%
[a][b][c] {printf("ABC");}
%%
int main()
{
	yylex();
}