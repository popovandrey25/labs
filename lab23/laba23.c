#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main(void) 
{
        printf("\nEnter:\n");
	printf("a) to add element\n");
	printf("p) to print tree\n");
	printf("d) to delete element\n");
	printf("h) to find out the number of nonterminal vertices\n");
	printf("e) to exit\n");
        
	Tree *t = NULL;
	int value;
	char c;
	int h = 0;
	
	
	while ((c = getchar()) != EOF) {
		value = 0;
		if (c == '\n') continue;
		switch (c) {
		case 'a':
			printf("value:");
			scanf("%d", &value);
			t = tree_add_element(t, value);
			break;
		case 'p':
			tree_print(t, 1);
			break;
		case 'd':
			printf("value: ");
			scanf("%d", &value);
			t = delete_element(t, value);
			break;
		case 'h':
			h = NonTerm(t);
			printf("Number of nonterminal vertices: %d\n", h);
			break;
		
		case 'e':
			printf("Exit...\n");
			return 0;
		default:
			printf("Command not exist\n");
			break;
		}
		
	}
}