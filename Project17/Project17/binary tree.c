#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree
{
	char c;
	struct tree* left;
	struct tree* right;
}NODE;

NODE* memory_alloc();
NODE* add_node(NODE* parent);
void preorder_traversal(NODE* parent);
void inorder_traversal(NODE* parent);
void postorder_traversal(NODE* parent);

int main()
{
	NODE* node_C, *node_L, *node_R, *node_N, *node_O, *node_D, *node_E;

	node_C = memory_alloc();
	node_C->c = 'C';

	node_L = add_node(node_C);
	node_R = add_node(node_C);
	node_N = add_node(node_L);
	node_O = add_node(node_L);
	node_D = add_node(node_R);
	node_E = add_node(node_R);

	printf("전위 순회: ");
	preorder_traversal(node_C);
	printf("\n");
	printf("중위 순회: ");
	inorder_traversal(node_C);
	printf("\n");
	printf("후위 순회: ");
	postorder_traversal(node_C);
	printf("\n");

	free(node_C);
	free(node_L);
	free(node_R);
	free(node_N);
	free(node_O);
	free(node_D);
	free(node_E);
}

NODE* memory_alloc()
{
	NODE* temp;
	temp = malloc(sizeof(NODE));

	temp->c = NULL;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

NODE* add_node(NODE* parent)
{
	NODE* new_node;
	NODE* temp;
	new_node = memory_alloc();
	printf("input charater : ");
	scanf("%c", &new_node->c);
	getchar();

	if (parent == NULL)
		return new_node;

	if (parent->left == NULL)
		parent->left = new_node;
	else
		parent->right = new_node;

	return new_node;
}

// 전위 순회(preorder traversal)
void preorder_traversal(NODE* parent)
{
	// C-L-N-O-R-D-E
	// 전위 순회는 가장 앞에서 호출
	if (parent == NULL) return;
	printf("%c - ", parent->c);

	if (parent->left != NULL)
	preorder_traversal(parent->left);
	if (parent->right != NULL)
	preorder_traversal(parent->right);
}

// 중위 순회(inorder traversal)

void inorder_traversal(NODE* parent)
{
	// N-L-O-C-D-R-E
	// 중위 순회는 중간에서 호출
	if (parent == NULL) return;

	if(parent->left != NULL)
	inorder_traversal(parent->left);
	printf("%c - ", parent->c);
	if(parent->right != NULL)
	inorder_traversal(parent->right);
}

// 후위 순회(postorder traversal)
void postorder_traversal(NODE* parent)
{
	// N-O-L-D-E-R-C
	// 후위 순회는 가장 뒤에서 호출
	if (parent == NULL) return;

	if (parent->left != NULL)
	postorder_traversal(parent->left);
	if (parent->right != NULL)
	postorder_traversal(parent->right);
	printf("%c - ", parent->c);
}