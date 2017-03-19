#include<stdio.h>
#include<stdlib.h>
struct link {
	struct link *next;
	struct link *prev;
};
struct task {
	//long state;
	//int pid;
	int flags;
	int prio;
	//unsigned char fpu_counter;
	struct link tasks;
	char rcu_read;
	int tgid;
	//char comm[16];
	//unsigned int rt_prio;
};

int main( void )
{
	int i = 0;
	struct task new_node;
	struct link *head;
	unsigned int p;
	unsigned int q;
	while(i < 1){
		printf("Enter The FlagI:");
		scanf("%d",&new_node.flags);
		
		printf("Enter The prioI:");
		scanf("%d",&new_node.prio);

		(new_node.tasks).prev = NULL;
		(new_node.tasks).next = NULL;

		printf("Enter The RCU_read:");
		scanf(" %c",&new_node.rcu_read);

		printf("Enter The tgidI:");
		scanf("%d",&new_node.tgid);

		if(head == NULL){
			head = &(new_node.tasks);
			//printf("%p\n",head);
			//printf("%p\n",&(new_node->tasks));
		}
		/*else{
			(new_node->tasks).next = head;
			head->prev = &(new_node->tasks).next;
			head = &(new_node->tasks);
		}*/
		i++;		
	}
	p = &new_node;
	q = &(new_node.tasks);
	unsigned int ptr1 = &(new_node.tasks); 
	struct task *ptr = ptr1 - (q-p);
	printf("%d\n",(ptr+1)->prio);
	printf("%p\n",(q-p));
	return 0;
}
