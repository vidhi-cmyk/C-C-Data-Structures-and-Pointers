#include <stdio.h>
#include <stdlib.h>

typedef struct Mylist {
	int data;
	struct Mylist* next;
} CL;


void add_start(CL** tail)
{
	CL* new_node = (CL*)malloc(sizeof(CL));
	printf("Enter value");
	scanf("%d", &new_node->data);

	if (*tail == NULL)	//if empty list
	{
		(*tail) = new_node;
		new_node->next = new_node;
	}
	else
	{
		new_node->next = (*tail)->next;
		(*tail)->next = new_node;
	}
	printf("Added to start successfully\n");
}


void add_end(CL** tail)
{
	CL* new_node = (CL*)malloc(sizeof(CL));
	printf("Enter value");
	scanf("%d", &new_node->data);

	if (*tail == NULL)	//if empty list
	{
		(*tail) = new_node;
		new_node->next = new_node;
	}
	else
	{
		new_node->next = (*tail)->next;
		(*tail)->next = new_node;
		*tail = new_node;
	}
	printf("Added to end successfully\n");
}


void del_start(CL** tail)
{
	if (*tail == NULL)	//if empty list
	{
		printf("Empty List");
	}

	else if ((*tail)->next == *tail)
	{
		free(*tail);
		*tail = NULL;
	}

	else
	{
		CL* temp;
		temp = (*tail)->next;
		(*tail)->next = ((*tail)->next)->next;
		temp->next = NULL;
		free(temp);
	}

	printf("Deleted from start.\n");

}

void del_end(CL** tail)
{
	if (*tail == NULL)	//if empty list
	{
		printf("empty List");
	}

	else if ((*tail)->next == *tail)
	{
		free(*tail);
		*tail = NULL;
	}

	else
	{
		CL* temp;
		temp = (*tail)->next;
		while (temp->next != *tail)
			temp = temp->next;

		temp->next = (*tail)->next;
		(*tail)->next = NULL;
		free(*tail);
		*tail = temp;
	}
	printf("deleted from end\n");
}

void display(CL* tail)
{
	if (tail == NULL)	//if empty list
	{
		printf("Displaying Empty List");
	}
	else if (tail->next == tail)
	{
		printf("%d ", tail->data);
	}
	else
	{
		CL* temp = tail->next; //so that it starts displaying from the top
		do
		{
			printf("%d ", temp->data);
			temp = temp->next;
		} while (temp != tail->next);
	}
	printf("\n");

}

CL* position(CL* tail, int p)
{
	tail = tail->next;
	for (int i = 1; i < p; i++)
	{
		tail = tail->next;
	}
	return tail;
}

int size(CL* tail)
{
	if (tail == NULL)
		return 0;
	else {
		CL* temp = tail;
		int n = 0;
		do
		{
			temp = temp->next;
			n += 1;
		} while (temp != tail);
		return n;
	}

}

void insert(CL* tail, int p)
{
	CL* new_node = (CL*)malloc(sizeof(CL));
	printf("Enter value");
	scanf("%d", &new_node->data);

	CL* prev_node = position(tail, p);
	new_node->next = prev_node->next;
	prev_node->next = new_node;
	printf("inserted successfully\n");
}

void del(CL* tail, int p)
{
	CL* prev_node = position(tail, p);
	prev_node->next = (prev_node->next)->next;
	printf("deleted successfully\n");
}

int main()
{
	
	CL* tail = NULL;

	int n = 8;
	int x;
	while (n != 0)
	{
		printf("\n");
		printf("Linked list Operations:\n");
		printf("Enter1: Add at begining\n");
		printf("Enter2: Add at end\n");
		printf("Enter3: Insert\n");
		printf("Enter4: Delete at beguning\n");
		printf("Enter5: Delete at end\n");
		printf("Enter6: Delete at position\n");
		printf("Enter7: Display\n");
		printf("Enter0: To exit\n");
		scanf("%d", &n);

		switch (n)
		{
		case 1:
		{
			add_start(&tail);
			break;
		}
		case 2:
		{
			add_end(&tail);
			break;
		}
		case 3:
		{
			
			printf("enter position");
			scanf("%d", &x);

			if (x > size(tail) + 1)
			{
				printf("Invalid Index");
			}
			else if (x == 1)
			{
				add_start(&tail);
			}
			else if (x == size(tail) + 1)
			{
				add_end(&tail);
			}
			else
			{
				insert(tail, x-1);
			}
			break;
		}
		case 4:
		{
			del_start(&tail);
			break;
		}
		case 5:
		{
			del_end(&tail);
			break;
		}
		case 6:
		{
			printf("enter position");
			scanf("%d", &x);

			if (x > size(tail) + 1)
			{
				printf("Invalid Index");
			}
			else if (x == 1)
			{
				del_start(&tail);
			}
			else if (x == size(tail) + 1)
			{
			
				del_end(&tail);
			}
			else
			{
		
				del(tail, x - 1);
			}
			break;
		}
		case 7:
		{
			display(tail);
			break;
		}
		}
	}

	return 0;
}
