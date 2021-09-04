// 2 4 8 9 12 13 14 17 21
// ���� ������ Ž��
// ��Ʈ ��庸�� ������ ���� ����Ʈ��
// ��Ʈ ��庸�� ũ�� ������ ����Ʈ��
// �˻� �� ���� ���� ���� �� "�˻��� ���� �������ϴ�."
// �˻� �� ���� ���� ���� �� "�˻��� ���� �������� �ʽ��ϴ�."
// ����Լ�
#define _CRT_SECURE_NO_WARINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}NODE;

NODE* memory_alloc();
void add_tree(int num);
NODE* inorder_print(NODE* root);
NODE* search(int num, NODE* root);
void delete_node(int num);

NODE* tree;

int main()
{
	tree = memory_alloc();
	int a;

	add_tree(12);
	add_tree(8);
	add_tree(17);
	add_tree(4);
	add_tree(9);
	add_tree(10);
	add_tree(2);
	add_tree(7);
	add_tree(13);
	add_tree(21);
	add_tree(14);

	printf("������ȸ : ");
	inorder_print(tree);

	while (1)
	{
		printf("\n\n0�̸� ����\n");
		printf("�˻��� ���� : ");
		scanf("%d", &a);
		if (a == 0) break;
		search(a, tree);
	}

	while (1)
	{
		printf("\n\n0�̸� ����\n");
		printf("������ ���� : ");
		scanf("%d", &a);
		if (a == 0) break;
		delete_node(a);
	}

	return 0;
}

NODE* memory_alloc()
{
	NODE* temp;
	temp = malloc(sizeof(NODE));
	temp->data = 0;
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
		if (tree_tail->left == NULL || tree_tail->right == NULL)
			break;

		if (num < tree_tail->data && tree_tail->left != NULL)
			tree_tail = tree_tail->left;
		else if (num > tree_tail->data && tree_tail->right != NULL)
			tree_tail = tree_tail->right;
	}
	
	if (tree_tail->data == 0)
	{
		tree_tail->data = num;
		return;
	}
	if (num < tree_tail->data && tree_tail->left == NULL)
	{
		tree_tail->left = memory_alloc();
		tree_tail->left->data = num;
	}
	else if (num > tree_tail->data && tree_tail->right == NULL)
	{
		tree_tail->right = memory_alloc();
		tree_tail->right->data = num;
	}

	return;
}

NODE* inorder_print(NODE* root)
{
	if (root->left != NULL)
		inorder_print(root->left);
	printf("%d  ", root->data);
	if (root->right != NULL)
		inorder_print(root->right);
}

NODE* search(int num, NODE* root)
{
	if (root == NULL)
	{
		printf("�˻��� ���� �������� �ʽ��ϴ�.");
		return;
	}

	if (num != root->data && num < root->data)
		search(num, root->left);

	if (num == root->data)
		printf("�˻��� ���� ���� �մϴ�.");

	if (num != root->data && num > root->data)
		search(num, root->right);
}

void delete_node(int num)
{
	NODE* tree_tail;
	tree_tail = tree;
	NODE* freenode;

	while (1)
	{
		if (tree_tail->left->data == num || tree_tail->right->data == num)break;
		if (tree_tail->left->data != num && num < tree_tail->data)
			tree_tail = tree_tail->left;
		else if (tree_tail->right->data != num && num > tree_tail->data)
			tree_tail = tree_tail->right;
	}
	// �����尡 �Ѵ� ���� ��
	if (tree_tail->left->data == num && tree_tail->left->left == NULL && tree_tail->left->right == NULL)
	{
		freenode = tree_tail->left;
		free(freenode);
		freenode = NULL;
		tree_tail->left = NULL;
	}
	if (tree_tail->right->data == num && tree_tail->right->left == NULL && tree_tail->right->right == NULL)
	{
		freenode = tree_tail->right;
		free(freenode);
		freenode = NULL;
		tree_tail->right = NULL;
	}
	// �����尡 �ϳ��� ���� ��
	else if (tree_tail->left->data == num && (tree_tail->left->left == NULL && tree_tail->left->right != NULL))
	{
		freenode = tree_tail->left;
		tree_tail->left = tree_tail->left->right;
		free(freenode);
		freenode = NULL;
	}
	else if (tree_tail->left->data == num && (tree_tail->left->left != NULL && tree_tail->left->right == NULL))
	{
		freenode = tree_tail->left;
		tree_tail->left = tree_tail->left->left;
		free(freenode);
		freenode = NULL;
	}
	else if (tree_tail->right->data == num && (tree_tail->right->left == NULL && tree_tail->right->right != NULL))
	{
		freenode = tree_tail->right;
		tree_tail->right = tree_tail->right->right;
		free(freenode);
		freenode = NULL;
	}
	else if (tree_tail->right->data == num && (tree_tail->right->left != NULL && tree_tail->right->right == NULL))
	{
		freenode = tree_tail->right;
		tree_tail->right = tree_tail->right->left;
		free(freenode);
		freenode = NULL;
	}
	// �����尡 �Ѵ� ���� ��
	else if (tree_tail->left->data == num && tree_tail->left->left != NULL && tree_tail->left->right != NULL)
	{
		freenode = tree_tail->left;
		tree_tail->left = tree_tail->left->right;
		tree_tail->left->right->left = tree_tail->left->left;
		free(freenode);
		freenode = NULL;
	}
	else if (tree_tail->right->data == num && tree_tail->left->left != NULL && tree_tail->left->right != NULL)
	{
		freenode = tree_tail->right;
		tree_tail->right = tree_tail->right->right;
		tree_tail->right->right->left = tree_tail->right->left;
		free(freenode);
		freenode = NULL;
	}

	return;
}