#include <stdio.h>
#include <stdlib.h>

struct AccountDetails
{
	char name[20];
	int num;
	float bal;
	struct AccountDetails* next;
};
typedef AccountDetails AD;

void Add_begining(AD** head) //verified
{

	AD* new_node = (AD*)malloc(sizeof(AD));
	printf("Enter name ");
	scanf("%s", new_node->name);
	printf("Enter accno ");
	scanf("%d", &new_node->num);
	printf("Enter balance ");
	scanf("%f", &new_node->bal);
	new_node->next = *head;
	*head = new_node;
	printf("Added to start successfully.\n");


}


void display(AD* head) //verified
{

	if (head == NULL)
	{
		printf("Empty list\n");
	}
	else
	{
		printf("Accounts: \n");
		printf("ACC NO      | NAME        | BALANCE\n");
		while (head != NULL)
		{
			printf("  %d    |", head->num);
			printf("  %s    |", head->name);
			printf("  %f    |\n", head->bal);

			head = head->next;
		}
		printf("\n");
	}
}

AD* position(AD* head, int n)  //verified
{
	for (int i = 1; i < n; i++)
	{
		head = head->next;
	}
	return head;
}

void insert(AD* prev_node)
{
	if (prev_node == NULL)
	{
		printf("invalid position");
	}
	else
	{
		AD* new_node = (AD*)malloc(sizeof(AD));
		printf("Enter name ");
		scanf("%s", new_node->name);
		printf("Enter accno ");
		scanf("%d", &new_node->num);
		printf("Enter balance ");
		scanf("%f", &new_node->bal);

		new_node->next = prev_node->next;
		prev_node->next = new_node;
		printf("Inserted successfully");
	}
}

void del_begining(AD** head)
{
	if (*head == NULL)
	{
		printf("Cant delete from empty list\n");
	}
	else
	{
		//check!how to fo free added this now many not work
		*head = (*head)->next;
		printf("Deleted successfully\n");
	}

}



void del_num(AD** head,int anum)  //verified
{
	int i = 0;
	AD* temp = *head;
	if (temp->num == anum)
	{
		*head = (*head)->next;
	}
	else {
		while ((temp->next)->num != anum)
		{
			temp = temp->next;
		}
		temp->next = NULL;
		free(temp->next);
	}	
	printf("Deleted successfully\n");
}

int main()
{
	AD* head = NULL;
	int n = 6;

	while (n != 0)
	{
		printf("\n");
		printf("Bank Operations:\n");
		printf("Enter1: Add at begining\n");
		printf("Enter2: Insert\n");
		printf("Enter3: Delete via acc num\n");
		printf("Enter4: delete at start\n");
		printf("Enter 5: To display\n");
		printf("Enter0: To exit\n");

		scanf("%d", &n);

		switch (n)
		{
		case 1:
			Add_begining(&head);
			break;

		case 2:
		{
			int p;
			printf("Enter number of nodes after which you wish to enter");
			scanf("%d", &p);
			if (p == 0)
			{
				Add_begining(&head);
			}
			else
			{
				insert(position(head, p));
				break;
			}
		}
		case 3:
		{
			int anum;
			printf("Enter accnum you wish to delete");
			scanf("%d", &anum);
			del_num(&head, anum);
			break;
		}

		case 4:
		{
			del_begining(&head);
			break;
		}

		case 5:
		{
			display(head);
			break;
		}

		}
	}
	return 0;
}
