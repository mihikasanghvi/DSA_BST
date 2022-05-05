#include<stdio.h>
#include<stdlib.h>
#include"bst2.h"
#define MAX_SIZE 100

node *initBST(node *t){
        t = NULL;
        return t;
}

node *newNode(int mis, char *name){
    node *nn = (node *)malloc(sizeof(node));
    nn->mis = mis;
    nn->name = name;
    nn->right = nn->left = nn->parent = NULL;
    return nn;
}
node *insertNode(node *t, int mis,char *name){
    if(!t){
        return newNode(mis,name);
    }
    if(mis < t->mis){
        node *lchild = insertNode(t->left, mis , name);
        t->left = lchild;
        lchild->parent = t;
    }
    else{
        node *rchild = insertNode(t->right, mis,name);
        t->right = rchild;
        rchild->parent=t;
    }
    return t;

}

int search(node *t, int mis){
	node *p = t;
	while(p != NULL){
		if(mis < p -> mis){
			return search(p->left,mis);
		}
		else if(mis > p->mis){
			return search(p->right, mis);
		}
		else{
		       	return 1;
		}
	}
	return 0;
}

void inorder(node *t){
	if(!t){
		return;
	}
	//node *p = t;
	inorder(t->left);
	printf("%d ",t->mis);
	inorder(t->right);
	return;
}

node* minNode(node* n)
{
    node* current = n;


    while (current && current->left != NULL)
        current = current->left;

    return current;
}

node* deleteNode(node* t, int mis)
{
    if (t == NULL)
        return t;

    if (mis < t->mis)
        t->left = deleteNode(t->left, mis);
        if(t->left){
            t->left->parent = t;
        }
    else if (mis > t->mis)
        t->right = deleteNode(t->right, mis);
        if(t->right){
            t->right->parent=t;
        }
    else {
        if (t->left == NULL) {
            node* temp = t->right;
            free(t);
            return temp;
        }
        else if (t->right == NULL) {
            node* temp = t->left;
            free(t);
            return temp;
        }
        node* temp = minNode(t->right);
        t->mis = temp->mis;
        t->right = deleteNode(t->right, temp->mis);
    }
    return t;
}
struct Stack* createStack(int size)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->array = (node**) malloc(stack->size * sizeof(node*));
    return stack;
}

int isFull(struct Stack* stack)
{ return stack->top - 1 == stack->size; }

int isEmpty(struct Stack* stack)
{ return stack->top == -1; }

void push(struct Stack* stack, node* node)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = node;
}
node* pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top--];
}

node* peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top];
}

void LevelDisplay(node *t, int level, int currLevel){
    if(t==NULL){
        return;
    }
    if(currLevel==level){
        printf("[%d][%s] ", t->mis, t->name);
    }
    LevelDisplay(t->left, level, currLevel+1);
    LevelDisplay(t->right, level, currLevel+1);
}

void postOrderIterative(node* t)
{
    // empty tree
    if (t == NULL)
        return;

    struct Stack* stack = createStack(MAX_SIZE);
    do
    {
        while (t)
        {
            if (t->right)
                push(stack, t->right);
            push(stack, t);
            t = t->left;
        }

        t = pop(stack);
        if (t->right && peek(stack) == t->right)
        {
            pop(stack);
            push(stack, t);
            t = t->right;

        }
        else
            {
            printf("%d ", t->mis);
            t = NULL;
        }
    } while (!isEmpty(stack));
}

void deleteTree(node* node)
{
    if (node == NULL) return;

    deleteTree(node->left);
    deleteTree(node->right);

    printf("\n Deleting node: %d", node->mis);
    free(node);
}

