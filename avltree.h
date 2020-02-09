#ifndef avltree
#define avltree


typedef struct Node *AVLTree;
struct Node
{
	char title[100];
	int year;
	char ID[100];
	char link[500];
	AVLTree left;
	AVLTree right;
	int height;
};

AVLTree insert_movie(char*, int, char*,char*, AVLTree);
int height(AVLTree);
int getbalance(AVLTree);
AVLTree SingleRotateWithLeft(AVLTree);
AVLTree SingleRotateWithRight(AVLTree);
int Max(int, int);
void DisplayTreeStructure(AVLTree t, int depth);

int Max(int x, int y)
{
    //For finding max number

	if (x >= y)
		return x;
	else
		return y;
}
int height(AVLTree t)
{
    //For finding height
    if (t == NULL)
        return 0;
    else
        return t->height;
}
AVLTree SingleRotateWithLeft(AVLTree k2)
{
    //Rotates tree to right

	AVLTree temp;
    temp = k2->left;
    k2->left = temp->right;
    temp->right = k2;
    k2->height = Max(height(k2->left), height(k2->right)) + 1;
    temp->height = Max(height(temp->left), k2->height) + 1;
    return temp;
}

AVLTree SingleRotateWithRight(AVLTree k1)
{
    //Rotates tree to left

	AVLTree temp;
	temp = k1->right;
	k1->right = temp->left;
	temp->left = k1;
	k1->height = Max(height(k1->left), height(k1->right)) + 1;
    temp->height = Max(height(temp->right), k1->height) + 1;
    return temp;
}


int getbalance(AVLTree node)
{
    //For checking the balance

    if(node==NULL)
        return 0;
    return height(node->left) - height(node->right);

}


void DisplayTreeStructure(AVLTree t, int depth)
{
	int i;

	if (t != NULL)
	{
		DisplayTreeStructure(t->right, depth + 1);

		for (i = 0; i < depth; i++)
			printf("   ");
		printf("%d)%s\n",i, t->title);

		DisplayTreeStructure(t->left, depth + 1);
	}
}



#endif // avltree
