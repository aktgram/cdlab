%{
	int cons=0,vowels=0;
%}
%%
[aeiouAEIOU] {vowels++;}
[a-zA-Z] {cons++;}
. ;
%%

int main()
{
    printf("\nEnter string: ");
	yylex();
	printf("no. of vowels:%d\nno. of consonants:%d\n",vowels,cons);
}