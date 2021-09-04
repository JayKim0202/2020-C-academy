// 전위순회
// 추가할때 분모 노드와 비교
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	int data;
	struct node* root;
	struct node* left;
	struct node* right;
}NODE;

NODE* memory_alloc();
void add_tree(int num);
void change_order(NODE* root, NODE* current_node);
void print(NODE* root);
void delete_node();
void change_order_delete(NODE* current_node);

NODE* tree;

int main()
{
	tree = memory_alloc();
	
	add_tree(1);
	add_tree(4);
	add_tree(7);
	add_tree(8);
	add_tree(9);
	add_tree(12);
	add_tree(13);
	add_tree(15);
	add_tree(3);

	print(tree);
	printf("\n");

	delete_node();

	print(tree);

	return 0;
}

NODE* memory_alloc()
{
	NODE* temp;
	temp = malloc(sizeof(NODE));
	temp->data = 0;
	temp->root = NULL;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void add_tree(int num)
{
	NODE* tree_tail;
	tree_tail = tree;

	while (1)
	{
		if (tree_tail->left == NULL || tree_tail->right == NULL) break;

		if (/*num > tree_tail->data && */(tree_tail->left->left == NULL || tree_tail->left->right == NULL))
			tree_tail = tree_tail->left;
		else if (/*num > tree_tail->data && */(tree_tail->right->left == NULL || tree_tail->right->right == NULL))
			tree_tail = tree_tail->right;
		else if (/*num > tree_tail->data && */tree_tail->right->right != NULL)
			tree_tail = tree_tail->left;
	}

	if (tree_tail->data == 0)
		tree_tail->data = num;
	else if (tree_tail->left == NULL)
	{
		tree_tail->left = memory_alloc();
		tree_tail->left->data = num;
		tree_tail->left->root = tree_tail;
		if (num < tree_tail->data)
			change_order(tree_tail, tree_tail->left);
	}
	else if (tree_tail->left != NULL && tree_tail->right == NULL)
	{
		tree_tail->right = memory_alloc();
		tree_tail->right->data = num;
		tree_tail->right->root = tree_tail;
		if (num < tree_tail->data)
			change_order(tree_tail, tree_tail->right);
	}
}

void change_order(NODE* root, NODE* current_node)
{
	int temp;

	if (root->data > current_node->data)
	{
		temp = root->data;
		root->data = current_node->data;
		current_node->data = temp;
	}
	else if (root->data < current_node->data)
		return;

	change_order(root->root, root);
}

void print(NODE* root)
{
	printf("%d\t", root->data);
	if (root->left != NULL)
		print(root->left);
	if (root->right != NULL)
		print(root->right);
}


void delete_node()
{
	NODE* tree_tail;
	tree_tail = tree;

	while (1)
	{
		if (tree_tail->left != NULL && tree_tail->left->left != NULL)
			tree_tail = tree_tail->left;
		else if (tree_tail->right != NULL)
			break;
	}
	tree->data = 0;
	tree->data = tree_tail->right->data;
	tree_tail->right = NULL;

	change_order_delete(tree);

	return;
}

void change_order_delete(NODE* current_node)
{
	int temp;
	int a = 0;

	if (current_node->data < current_node->left->data)
	{
		if (current_node->right == NULL) return;
	}

	if ((current_node->left->data > current_node->right->data) && (current_node->data > current_node->right->data))
	{
		temp = current_node->data;
		current_node->data = current_node->right->data;
		current_node->right->data = temp;
		a = 1;
	}
	else if ((current_node->left->data < current_node->right->data) && (current_node->data > current_node->left->data))
	{
		temp = current_node->data;
		current_node->data = current_node->left->data;
		current_node->left->data = temp;
		a = 2;
	}
	

	if (a == 1)
		change_order_delete(current_node->right);
	else if (a == 2)
		change_order_delete(current_node->left);
	/*else if ((current_node->data < current_node->left->data) && (current_node->data < current_node->right->data))
		return;*/
}