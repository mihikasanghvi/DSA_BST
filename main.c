/*#include<stdio.h>
#include<stdlib.h>
#include"bst2.h"

int main(){
	int flag = 0;
	node *t = NULL;
    t= initBST(t);
    t = insertNode(t,112003084, "mihika");
	t = insertNode(t,112003043, "shrushti");
	t = insertNode(t,112003003, "om");
	t = insertNode(t,112003008, "ishan");
	t = insertNode(t,112003093, "nidhi");
	t = insertNode(t,112003087, "anushka");
	printf("Printing the binary tree\n");
	inorder(t);
	printf("\n");
	flag = search(t, 112003008);
	if (flag == 1){
		printf("Element found\n");
	}
	else
		printf("Element not found\n");
    printf("Deleting 112003043\n");
    t = deleteNode(t,112003043);
    inorder(t);
    printf("\nLevel node:\n");
    LevelDisplay(t,1,0);
    printf("\nPost order traversal of binary tree is :\n");
    postOrderIterative(t);
    deleteTree(t);
    printf("\nTree deleted\n");
    return 0;
}*/

#include<stdio.h>
#include<stdlib.h>
#include"bst2.h"

int main(){
	int flag = 0;
	node *t = NULL;
    t= initBST(t);
    t = insertNode(t,112003084, "mihika");
	t = insertNode(t,112003043, "shrushti");
	t = insertNode(t,112003003, "om");
	t = insertNode(t,112003008, "ishan");
	t = insertNode(t,112003093, "nidhi");
	t = insertNode(t,112003087, "anushka");
	/*printf("Printing the binary tree\n");
	inorder(t);
	printf("\n");
	flag = search(t, 112003008);
	if (flag == 1){
		printf("Element found\n");
	}
	else
		printf("Element not found\n");
        printf("Deleting 112003043\n");
        t = deleteNode(t,112003043);
        inorder(t);
        printf("\nLevel node:\n");
        LevelDisplay(t,1,0);
        printf("\nPost order traversal of binary tree is :\n");
        postOrderIterative(t);
        deleteTree(t);
        printf("\nTree deleted\n");*/
	int i;
	int n;

	while(1){
        printf("\nChoose the option:\n");
		printf("1: Insert data\n");
		printf("2: Search data\n");
		printf("3: Delete data\n");
		printf("4: Display Level Nodes:\n");
		printf("5: Post Order:\n");
		printf("6: destroy tree\n");
		printf("7: Quit\n");
		scanf("%d",&i);
		switch(i){
			case 1:
			    printf("Enter a number to be inserted: ");
				scanf("%d ", &n);
				t = insertNode(t, n, "new");
				printf("Inserted %d\n", n);
				inorder(t);
				break;
			case 2:
			    printf("Enter the number you want to search: ");
				scanf("%d" , &n);
				flag = search(t, n);
       				if (flag == 1){
                        printf("Element found\n");
                    }
                    else
                        printf("Element not found\n");
				break;
			case 3:
			    printf("ENter the number to delete: ");
                scanf("%d",&n);
                t = deleteNode(t, n);
                printf("%d is deleted",n);
                break;
			case 4:
			    printf("\nLevel node:\n");
                LevelDisplay(t,1,0);
                break;
			case 5:
			    printf("\nPost order traversal of binary tree is :\n");
                postOrderIterative(t);
				break;
			case 6:
			    deleteTree(t);
                printf("\nTree deleted\n");
				break;
            case 7:
                exit(0);
			default:
			    printf("Choose another number:");
			 	break;
		}
	}
        return 0;
}


