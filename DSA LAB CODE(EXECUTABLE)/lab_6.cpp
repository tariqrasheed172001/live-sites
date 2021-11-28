/*AIM: Represent a polynomial as a linked list and writing a function
for polynomial addition.

ALGORITHEM:
Step 1: loop around all values of linked list and follow step 2& 3.
Step 2: if the value of a node’s exponent. is greater copy this node 
to result node and head towards the next node.
Step 3: if the values of both node’s exponent is same add the coefficients 
and then copy the added value with node to the result.
Step 4: Print the resultant node.

*/ 
#include <iostream>
#include<math.h>
using namespace std;

struct Node {
	int coeff;
	int pow;
	struct Node* next;
};

void create_node(int x, int y, struct Node** temp)
{
	struct Node *r, *z;
	z = *temp;
	if (z == NULL) {
		r = (struct Node*)malloc(sizeof(struct Node));
		r->coeff = x;
		r->pow = y;
		*temp = r;
		r->next = (struct Node*)malloc(sizeof(struct Node));
		r = r->next;
		r->next = NULL;
	}
	else {
		r->coeff = x;
		r->pow = y;
		r->next = (struct Node*)malloc(sizeof(struct Node));
		r = r->next;
		r->next = NULL;
	}
}

void polyadd(struct Node* poly1, struct Node* poly2,
			struct Node* poly)
{
	while (poly1->next && poly2->next) {

		if (poly1->pow > poly2->pow) {
			poly->pow = poly1->pow;
			poly->coeff = poly1->coeff;
			poly1 = poly1->next;
		}

		else if (poly1->pow < poly2->pow) {
			poly->pow = poly2->pow;
			poly->coeff = poly2->coeff;
			poly2 = poly2->next;
		}

		else {
			poly->pow = poly1->pow;
			poly->coeff = poly1->coeff + poly2->coeff;
			poly1 = poly1->next;
			poly2 = poly2->next;
		}
		poly->next
			= (struct Node*)malloc(sizeof(struct Node));
		poly = poly->next;
		poly->next = NULL;
	}
	while (poly1->next || poly2->next) {
		if (poly1->next) {
			poly->pow = poly1->pow;
			poly->coeff = poly1->coeff;
			poly1 = poly1->next;
		}
		if (poly2->next) {
			poly->pow = poly2->pow;
			poly->coeff = poly2->coeff;
			poly2 = poly2->next;
		}
		poly->next
			= (struct Node*)malloc(sizeof(struct Node));
		poly = poly->next;
		poly->next = NULL;
	}
}

void show(struct Node* node)
{
	while (node->next != NULL) {
		printf("%dx^%d", node->coeff, node->pow);
		node = node->next;
		if (node->coeff >= 0) {
			if (node->next != NULL)
				printf("+");
		}
	}
}

int main()
{
	struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL;

	// Create first list of 5x^2 + 4x^1 + 2x^0
	create_node(5, 2, &poly1);
	create_node(4, 1, &poly1);
	create_node(2, 0, &poly1);

	// Create second list of -5x^1 - 5x^0
	create_node(-5, 1, &poly2);
	create_node(-5, 0, &poly2);

	printf("1st Number: ");
	show(poly1);

	printf("\n2nd Number: ");
	show(poly2);

	poly = (struct Node*)malloc(sizeof(struct Node));

	// Function add two polynomial numbers
	polyadd(poly1, poly2, poly);

	// Display resultant List
	printf("\nAdded polynomial: ");
	show(poly);
	cout<<endl;
	return 0;
}
