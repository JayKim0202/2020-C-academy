#ifndef __BINARY_SEARCH_TREE3__
#define __BINARY_SEARCH_TREE3__

#include "BinaryTree3.h"

typedef BTData BSTData;

// ���� Ž�� Ʈ���� ���� �� �ʱ�ȭ
void BSTMakeAndInit(BTreeNode** pRoot);

// ��忡 ����� ������ ��ȯ
BSTData BSTGetNodeData(BTreeNode* bst);

// ���� Ž�� Ʈ���� ������� ������ ����(����� �������� ����)
void BSTInsert(BTreeNode** pRoot, BSTData data);

// ���� Ž�� Ʈ���� ������� ������ Ž��
BTreeNode* BSTSearch(BTreeNode* bst, BSTData Target);

// Ʈ������ ��带 �����ϰ� ���ŵ� ����� �ּ� ���� ��ȯ�Ѵ�.
BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData Target);

// ���� Ž�� Ʈ���� ����� ��� ����� �����͸� ����Ѵ�.
void BSTShowAll(BTreeNode* bst);

#endif