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

	scanf("%d", &nodenum);	// input node number
	int pnode[nodenum+1];
	int depth[nodenum+1];
	Stack connect[nodenum+1];
	memset(pnode, 0, (nodenum+1)*sizeof(int) ); // reset 0
	memset(depth, 0, (nodenum+1)*sizeof(int) ); // reset 0
	
	for(int i = 1; i <= nodenum; i++) // make connect list (== connect[nodenum+1][nodenum+1])
		connect[i] = Stack(); // make new stack

	for(int i = 1; i < nodenum; i++) { // loop nodenum-1 time
		scanf("%d %d", &node1, &node2);
		// Preventing 1 parenting
		if (node2 != 1)
			connect[node1].push(node2);
		if (node1 != 1)
			connect[node2].push(node1);
	}

	Stack stn = Stack();
	stn.push(1); // root node is 1

	int noden1, noden2;
	while(!(stn.empty())) // save node's parent, depth
	{
		noden1 = stn.pop();
		while(!(connect[noden1].empty()))
		{
			noden2 = connect[noden1].pop();
			if(pnode[noden2] == 0) // node2 != 1 && node2 hasn't parent
			{
				stn.push(noden2);
				pnode[noden2] = noden1;
				depth[noden2] = depth[noden1]+1;
			}
		}
	}

	scanf("%d", &findnum);	// input Number of pairs wanting to know common ancestry

	while(findnum--) 
	{ // loop findnum time
		scanf("%d %d", &node1, &node2); // input two node number
		//find same depth
		while( depth[node1] > depth[node2] )
			node1 = pnode[node1];
		while( depth[node2] > depth[node1] )
			node2 = pnode[node2];
		//find same depth end
		
		while(node1 != node2)	//find same parent
		{
			node1 = pnode[node1];
			node2 = pnode[node2];
		}
		printf("%d\n", node1);
	}
}	

int main(int argc, char const *argv[])
{
	lca();
	return 0;
}