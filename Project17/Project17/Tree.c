#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct treeNode
{
	char c;
	struct treeNode* sibling;
	struct treeNode* child;
}NODE;

NODE* memory_alloc();
NODE* Add_node(NODE* parent);
void view_tree(NODE* parent);

int main()
{
	NODE* nA, *nB, *nC, *nD, *nE, *nF, *nG, *nH, *nI, *nJ, *nK;

	nA = memory_alloc();
	nA->c = 'A';
	nB = Add_node(nA);
	nC = Add_node(nA);
	nD = Add_node(nB);
	nE = Add_node(nB);
	nF = Add_node(nC);
	nG = Add_node(nC);
	nH = Add_node(nC);
	nI = Add_node(nD);
	nJ = Add_node(nD);
	nK = Add_node(nE);

	view_tree(nA);

	free(nA);
	free(nB);
	free(nC);
	free(nD);
	free(nE);
	free(nF);
	free(nG);
	free(nH);
	free(nI);
	free(nJ);
	free(nK);


	return 0;
}

NODE* memory_alloc()
{
	NODE* temp;
	temp = malloc(sizeof(NODE));

	temp->c = NULL;
	temp->sibling = NULL;
	temp->child = NULL;

	return temp;
}

NODE* Add_node(NODE* parent)
{
	NODE* new_node;
	NODE* temp;

	new_node = memory_alloc();
	printf("input alphabet:");
	scanf("%c", &(new_node->c));
	getchar();

	//temp = parent
	if (parent->child == NULL)
		parent->child = new_node;
	else
	{
		temp = parent->child;
		while (1)
		{
			if (temp->sibling == NULL) break;
			temp = temp->sibling;
		}
		temp->sibling = new_node;
	}

	return new_node;
}


void view_tree(NODE* parent)
{
	printf("%c\n", parent->c);

	if (parent->child != NULL)
		view_tree(parent->child);
	if (parent->sibling != NULL)
		view_tree(parent->sibling);

	return;
}