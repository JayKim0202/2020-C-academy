#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct vertex
{
	int value;
	struct vertex* next;
	struct Edge* head;
} vertex;

typedef struct Edge
{
	struct vertex* start;
	struct vertex* end;
	struct Edge* nextEdge;
}Edge;

vertex* MemAlloc();
Edge* MemEdge();
vertex* AddVertex(vertex* para);
Edge* AddEdge(vertex* start, vertex* end);
void ViewGraph(vertex* para);
int Input();

int mian()
{
	vertex* node[6] = { 0 };
	
	node[0] = AddVertex(NULL);
	node[1] = AddVertex(node[0]);
	node[2] = AddVertex(node[0]);
	node[3] = AddVertex(node[0]);
	node[4] = AddVertex(node[0]);
	node[5] = AddVertex(node[0]);

	AddEdge(node[0], node[1]);
	AddEdge(node[0], node[2]);
	AddEdge(node[0], node[3]);
	AddEdge(node[0], node[5]);

	AddEdge(node[1], node[0]);
	AddEdge(node[1], node[2]);

	AddEdge(node[2], node[0]);
	AddEdge(node[2], node[1]);
	AddEdge(node[2], node[4]);

	AddEdge(node[3], node[0]);
	AddEdge(node[3], node[5]);

	AddEdge(node[4], node[2]);
	AddEdge(node[4], node[5]);

	AddEdge(node[5], node[0]);
	AddEdge(node[5], node[3]);
	AddEdge(node[5], node[4]);

	ViewGraph(node[0]);

	return 0;
}


Edge* AddEdge(vertex* start, vertex* end)
{
	Edge* newline;
	Edge* temp;

	newline = MemEdge();
	newline->start = start;
	newline->end = end;

	temp = start->head;

	if (temp == NULL)
		start->head = newline;
	else
	{
		while (temp->nextEdge != NULL)
			temp = temp->nextEdge;
		temp->nextEdge = newline;
	}

	return newline;
}

Edge* MemEdge()
{
	Edge* temp;
	temp = (Edge*)malloc(sizeof(Edge));
	temp->start = 0;
	temp->end = 0;
	temp->nextEdge = 0;
	return temp;
}

int Input()
{
	int temp;

	printf("input data :");
	scanf("%d", &temp);

	return temp;
}

vertex* MemAlloc()
{
	vertex* temp;

	temp = (vertex*)malloc(sizeof(vertex));

	temp->value = 0;
	temp->next = 0;
	temp->head = 0;

	return temp;
}

vertex* AddVertex(vertex* para)
{
	vertex* newnode;

	newnode = MemAlloc();
	newnode->value = Input();
	//newnode->head = MemEdge();

	if (para != NULL)
		while (para->next != NULL)
			para = para->next;

	para->next = newnode;
}

void ViewGraph(vertex* para)
{
	Edge* temp;
	while (para != NULL)
	{
		printf("(vertex)%d", para->value);
		temp = para->head;
		while (temp != NULL)
		{
			printf("-(Edge)%d", temp->end->value);
			temp = temp->nextEdge;
		}
		printf("\n");
		para = para->next;
	}

	return;
}