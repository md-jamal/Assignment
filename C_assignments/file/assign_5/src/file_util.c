#include"file.h"

int main()
{
	eh *eh_ptr = NULL;
	int opt = 0;

/*	while(1){
		printf("\n1.Write\n2.Read\n3.Exit\nChoose Record");
		scanf("%d",&opt);
		
		if(opt > 3)
			break;
		switch(opt){
			case 1:	*/
				eh_ptr = file_write();
			//	break;
		//	case 2:
				file_read();
		/*		break;
		}
	}*/
	return 0;
}
