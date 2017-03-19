/*	
	Program : Binary Tree Implement
	Author : Pritam Krishna Mali.
*/

#include"btree.h"

int main()
{
	int opt;						/*USER INPUT : Option*/
	int data;						/*ESER INPUT : Data*/
	BT *root = NULL;				/*Root Variable Of Tree*/
	while (1){
		printf("\n1.Insert Node:");
		printf("\n2.Inorder Traverse Tree");
		printf("\n3.Preorder Traverse Tree");
		printf("\n4.Postorder Traverse Tree");
		printf("\n5.Delete");
		printf("\n6.Exit");
		printf("\nChoose option:");
		
		opt = atoimy();
		
		if (opt >= 6)
			break;
		
		switch (opt){
			case 1:
				printf("\nEnter The Data:");	
				data = atoimy();
				root = insert_node(root, data);		/*Insert Node*/
				break;
			case 2:
				printf("\nData:");
				inorder(root);						/*Inorder Traverse*/
				break;
			case 3:
				printf("\nData:");                                              
                preorder(root);                      /*preorder Traverse*/        
                break;
			case 4:                                                             
                printf("\nData:");                                              
                postorder(root);                     /*postorder Traverse*/      
                break;
			case 5:
				printf("\nEnter The Data:");        
				scanf("%d",&data);
				printf("%d",data);
				BT *temp = root;
				root = delete_node(temp,10);
				break;
		}
	}
}
