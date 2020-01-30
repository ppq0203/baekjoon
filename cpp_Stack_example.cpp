#include <stdio.h>
#include <stdlib.h>

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
		printf("pushed data: %d\n", data);
	}

	int pop() {
		node* temp = NULL;
		if (empty()) {
			printf("error : trying to pop from empty stack\n");
		}
		else {
			temp = stack;
			stack = temp->link;
			printf("poped data: %d\n", temp->data);
			m_size--;
		}
		int popdata = temp->data;
		free(temp);
		return popdata;
	}

	int top() {
		node* temp = stack;
		if (empty()) {
			printf("error : trying to top from empty stack\n");
			return NULL;
		}
		else {
			printf("top data: %d\n", temp->data);
			return temp->data;
		}
	}	

	int size() {
		printf("stack size: %d\n", m_size);
		return m_size;
	}
};

int main(int argc, char const *argv[])
{
	Stack st;
	Stack st2;
	st.push(12);
	st.push(3);
	st2.push(100);
	st2.push(90);
	st.push(9);
	st.size();
	st.pop();
	st.pop();
	st.size();
	st.push(7);
	st.pop();
	st.size();
	st.pop();
	st.pop();
	st.pop();
	st.pop();
	st.size();

	return 0;
}
