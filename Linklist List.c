#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node* next;
};
typedef struct node Node;
int main() {
	Node a, b, c;
	Node* ptr = &a;
	
	a.data = 12;
	a.next = &b;
	
	b.data = 30;
	b.next = &c;

	c.data = 64;
	c.next = NULL;

	while (ptr != NULL) {
		printf("address=%p, ", ptr); //�L�X�`�I����} 
		printf("data=%d ", ptr->data); //�L�X�`�I����� 
		printf("next=%p\n", ptr->next); //�L�X�U�@�Ӹ`�I��} 
		ptr = ptr->next;  //�Nptr���V�U�@�Ӹ`�I 
	}
	system("pause");
}