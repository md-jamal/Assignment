#include"list.h"
/*Show Menu*/
int menu()
{
	int opt;
	printf("\n\n............Insert Node Option............\n");
	printf("\n1.Add Begin\n2.Add End\n3.Insert Node At Given Position");
	printf("\n4.insert Node Befor given position");
	printf("\n5.insert Node After given Position i");
	printf("\n6.Insert Number Before Given Number"); 
	printf("\n7.Insert Number after Given Number");
	printf("\n8.Insert Node At Middle");
	printf("\n9.Insert Node At penultinate Node");
	printf("\n\n.............Delete Node Option...........\n");
	printf("\n10.Delete Begin");
	printf("\n11.Delete End");
	printf("\n12.Delete N position Node");
	printf("\n13.Delete Befor N Position Node");
	printf("\n14.Delete After N position Node");
	printf("\n15.Delete Befor NUM position Node");
	printf("\n16.Delete After NUM position Node");
	printf("\n17.Delete At Middle");
	printf("\n18.Delete Penultinate Node");
	printf("\n19.Write List To File");
	printf("\n20.Read List From File");
	printf("\n21.Display");
	printf("\n22.EXIT ");
	printf("\nChoose Option::");
	scanf("%d",&opt);
	return opt;
}
