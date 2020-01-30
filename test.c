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
	node* top;
public:
	Stack()
	{
		m_size = 0;
		top = NULL;
	}

	int empty() {
		return (top == NULL);
	}

	void push(int data) {
		node* temp = (node*)malloc(sizeof(node));
		temp->data = data;
		temp->link = NULL;
		if (empty()) {
			top = temp;
		}
		else {
			temp->link = top;
			top = temp;
		}
		m_size++;
		printf("pushed data: %d\n", data);
	}

	node* pop() {
		node* temp = NULL;
		if (empty()) {
			printf("error : trying to pop from empty stack\n");
		}
		else {
			temp = top;
			top = temp->link;
			printf("poped data: %d\n", temp->data);
			m_size--;
		}
		return temp;
	}
	int size() {
		printf("stack size: %d\n", m_size);
		return m_size;
	}
};

int main(int argc, char const *argv[])
{
	Stack st = Stack();
	Stack st2 = Stack();
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