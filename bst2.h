typedef struct node{
        int mis;
        char *name;
        struct node *left;
        struct node *right;
        struct node *parent;
}node;

struct Stack
{
    int size;
    int top;
    node **array;
};
node *initBST(node *t);
node *newNode(int mis, char *name);
void inorder(node* t);
node *insertNode(node *t, int mis, char *name);
void inorder(node *t);
int search(node *t, int mis);
node* deleteNode(node* t, int mis);
node* minNode(node* n);
void deleteTree(node* node);
void LevelDisplay(node *t, int level, int currLevel);
struct Stack* createStack(int size);
int isFull(struct Stack* stack);
int isEmpty(struct Stack* stack);
void push(struct Stack* stack, node* node);
node* pop(struct Stack* stack);
node* peek(struct Stack* stack);
void postOrderIterative(node* t);




