digit		[0-9]
alpha		[a-fA-F]

%%
{digit}		printf("Found number value %s !", yytext);
{alpha}		printf("Found alpha value %s !", yytext);
%%

main()
{
	printf("Input:\n");
	yylex();
}
