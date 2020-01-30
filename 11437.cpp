#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Stack
{
private:
	typedef struct _node {
		int data;
		struct _node* link;
	}node;
	int m_size;
	node* stack;
public:
	Stack()
	{
		m_size = 0;
		stack = NULL;
	}

	int empty() {
		return (stack == NULL);
	}

	void push(int data) {
		node* temp = (node*)malloc(sizeof(node));
		temp->data = data;
		temp->link = NULL;
		if (empty()) {
			stack = temp;
		}
		else {
			temp->link = stack;
			stack = temp;
		}
		m_size++;
		//printf("pushed data: %d\n", data);
	}

	int pop() {
		node* temp = NULL;
		if (empty()) {
			//printf("error : trying to pop from empty stack\n");
		}
		else {
			temp = stack;
			stack = temp->link;
			//printf("poped data: %d\n", temp->data);
			m_size--;
		}
		int popdata = temp->data;
		free(temp);
		return popdata;
	}

	int top() {
		node* temp = stack;
		if (empty()) {
			//printf("error : trying to top from empty stack\n");
			return NULL;
		}
		else {
			//printf("top data: %d\n", temp->data);
			return temp->data;
		}
	}	

	int size() {
		//printf("stack size: %d\n", m_size);
		return m_size;
	}
};


void lca() {
	int nodenum, findnum, node1, node2;
	int *pnode, *depth;
	Stack *connect;

	scanf("%d", &nodenum);	// input node number
	pnode = (int*)malloc((nodenum+1)*sizeof(int)); // use 1~n make 0~n list (== pnode[nodenum+1])
	depth = (int*)malloc((nodenum+1)*sizeof(int));
	memset(pnode, 0, (nodenum+1)*sizeof(int) );
	memset(depth, 0, (nodenum+1)*sizeof(int) );
	connect = (Stack*)malloc((nodenum+1)*sizeof(Stack)); // use 1~n make 0~n list connect (== *connect[nodenum+1])
	memset(connect, 0, (nodenum+1)*sizeof(int*) );
	
	for(int i = 1; i <= nodenum; i++) // make connect list (== connect[nodenum+1][nodenum+1])
		*(connect+i) = Stack();

	for(int i = 1; i < nodenum; i++) { // loop nodenum-1 time
		scanf("%d %d", &node1, &node2);
		// Preventing 1 parenting
		if (node2 != 1)
			(connect+node1)->push(node2);
		if (node1 != 1)
			(connect+node2)->push(node1);
	}

	Stack stn = Stack();
	stn.push(1);
	int noden1, noden2;
	while(!(stn.empty()))
	{
		noden1 = stn.pop();
		while(!((connect+noden1)->empty()))
		{
			noden2 = (connect+noden1)->pop();
			if(*(pnode+noden2) == 0)
			{
				stn.push(noden2);
				*(pnode+noden2) = noden1;
				*(depth+noden2) = *(depth+noden1)+1;	
			}
		}
		//printf("%d %d\n", noden1, noden2);
	}
	free(connect);
	// for(int i = 0; i <= nodenum; i++)
	// {
	// 	printf("%d %d\n", *(pnode+i), *(depth+i));
	// }

	scanf("%d", &findnum);	// input Number of pairs wanting to know common ancestry

	while(findnum--) 
	{ // loop findnum time
		scanf("%d %d", &node1, &node2); // input two node number
		//find same depth
		while( (*(depth+node1)) > (*(depth+node2)) )
			node1 = *(pnode+node1);
		while( (*(depth+node2)) > (*(depth+node1)) )
			node2 = *(pnode+node2);
		//find same depth end

		while(node1 != node2)	//find same parent
		{
			node1 = *(pnode+node1);
			node2 = *(pnode+node2);
		}
		printf("%d\n", node1);
	}
	free(pnode);
	free(depth);
}	

int main(int argc, char const *argv[])
{
	lca();
	return 0;
}