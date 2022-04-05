#include<stdio.h>
#include<stdlib.h>

typedef struct _Node{
	int data;
	struct _Node *left;
	struct _Node *right;
}Node;

void constructTree(Node** head);
void printInfix(Node *root);
void freeTree(Node *root);

char bolstr[3005];


void constructTree(Node** head)
{
	int num;
	char c;
	if((*head) == NULL)
	{
		(*head) = (Node*)malloc(sizeof(Node));
		scanf("%d", &num);
		(*head) -> data = num;
		c = getchar();
		(*head) -> left = (*head) -> right = NULL;
		
		if((*head) -> left == NULL && c == '?') constructTree(&(*head) -> left);
		if((*head) -> right == NULL && c == '?') constructTree(&(*head) -> right);
	}
}

void freeTree(Node *root)
{
    if (root!=NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

//void printInfix(Node *root)
//{
// if (root!=NULL)
//   printf("%d ",root->data);
//    if (root->left != NULL) 
//  printInfix(root->left);
// if (root->right !=NULL)
//   printInfix(root->right);
//}

int CallInfix(Node* root)
{	
	if(root -> left == NULL && root -> right == NULL) 
	{
		//printf("root -> data: %d\n", root -> data);
		return(bolstr[root -> data-1] == '1');
	}
	if(root -> left != NULL && bolstr[root -> data-1] == '1') //////else?
	{
		//printf("2, root -> data: %d\n", root -> data);
		return CallInfix(root -> left);	
	}
	if(root -> right != NULL && bolstr[root -> data-1] == '0')
	{
		//printf("3, root -> data: %d\n", root -> data);
		return CallInfix(root -> right);
	}
}

int main()
{
	int num;
	Node* root = NULL;
	constructTree(&root);
	scanf("%d", &num);
	getchar();
	while(num>0)
    {
    	int i = 0;
        //fgets(bolstr, 3001, stdin);
        while((bolstr[i]=getchar())!='\n')
        {
        	i++;
		}
        printf("%d\n",CallInfix(root));
        num--;
        
    }
	freeTree(root);
	return 0;
}