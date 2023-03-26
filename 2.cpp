#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account_details {
	char name[20];
	int num;
	float bal;
};
typedef struct Account_details AD;

int main()
{
	FILE* f1w;
	f1w = fopen("file1.txt", "w");
	if (f1w == NULL)
	{
		printf("File1 failed to open to write");
		exit(1);
	}
	fprintf(f1w, "%s ", "writing:");
	fprintf(f1w, "%d ", 5);
	fprintf(f1w, "%f ", 5.01);

	AD acc1;
	//taking entries from user
	printf("enter name ");
	scanf("%s", acc1.name);
	printf("enter ACC_NO ");
	scanf("%d", &acc1.num);
	printf("enter balance ");
	scanf("%f", &acc1.bal);

	fwrite(acc1.name, 20, 1, f1w);
	fwrite(&acc1.num, sizeof(int), 1, f1w);
	fwrite(&acc1.bal, sizeof(float), 1, f1w);
	fclose(f1w);


	fclose(f1w); // contents have been entered to f1
	printf("file 1 has data written successfully\n");

	FILE* f1r;
	f1r = fopen("file1.txt", "r");
	if (f1r == NULL)
	{
		printf("File1 failed to open to read");
		exit(1);
	}

	FILE* f2w;
	f2w = fopen("file2.txt", "w");
	if (f2w == NULL)
	{
		printf("File2 failed to open to write");
		exit(1);
	}
	char string1[50];
	int num;
	float fl;
	fscanf(f1r, "%s", string1);
	fscanf(f1r, "%d", &num);
	fscanf(f1r, "%f", &fl);

	AD accread;
	fread(&accread, sizeof(accread), 1, f1r);
	printf("Account Details:\n");
	printf("Name     |AAC_NO  |Balance\n ");
	printf("%s   |", accread.name);
	printf("%d   |", accread.num);
	printf("%f    |", accread.bal);
	printf("read from file 1 successfully\n");

	fprintf(f2w, "%s ", string1);
	fprintf(f2w, "%d ", num);
	fprintf(f2w, "%f ", fl);
	fwrite(&accread, sizeof(accread), 1, f2w);
	printf("written data into file 2 successfully\n");
	fclose(f2w);
	fclose(f1r);

	return 0;
}