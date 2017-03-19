#include <stdio.h>
#include <stdlib.h>

#define STARTOFF(type, member, addr) ((char *)addr - (char *)(&(((type *)0) -> member)))
struct link {
	struct link *next;
	struct link *prev;
};

struct task {
	long state;
	int pid;
	int flags;
	int prio;
	unsigned char fpu_counter;
	struct link tasks;
	char rcu_read;
	int tgid;
	char comm[16];
	unsigned int rt_prio;
}initial = {.state = 55000, .pid = 150, .flags = 10, .prio = 54, .fpu_counter = 65};

int main()
{

	struct task *start_addr = (struct task*)STARTOFF(struct task, tasks, &(initial.tasks));
	printf("Start Address : %ld\n", start_addr -> state);
	printf("pid : %d\n", start_addr -> pid);
	printf("flags : %d\n", start_addr -> flags);
	printf("priority : %d\n", start_addr -> prio);
	printf("fpu_counter  : %c\n", start_addr -> fpu_counter);
	
	return 0;
}
