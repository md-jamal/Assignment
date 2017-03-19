/*	Write macros for the foowing using bitwise operations:
		a. To find maximum and minimum of 2 numbers
		b. To clear right most set bit in a number
		c. To clear left most set bit in a number
		d. To set right most cleared bit in a number
		e. To set left most cleared bit in a number
		f.To set bits from bit position ‘s’ to bit position ‘d’ in a given number and clear rest of the bits
		g. To clear bits from bit position ‘s’ to bit position ‘d’ in a given number and set rest of the bits
		h. To toggle bits from bit position ‘s’ to bit position ‘d’ in a given number 
*/
#include<stdio.h>
//#define clr_r_bit(num) for(i = 0; i <= ((8 * sizeof(void *)) - 1); i++){ if((num & (1 << i))){	num = num & ~(1 << i);	break;	} }    					
		

/*Clear right most set bit */
#if 0
int main()
{
        int num; //User Input
        int i = 0; //Simple Variable for loop

        printf("\nEnter the Number:");
        scanf("%d",&num);

        if(num>=0) {
                	clr_r_bit(num);
                }
                printf("Answer:%d\n",num);

        clr_r_bit(num);
}
#endif
#if 0 
int main()
{
	int num; //User Input
	int i = 0; //Simple Variable for loop
	
	printf("\nEnter the Number:");
	scanf("%d",&num);

	if(num>=0) {     
		for(i = 0; i <= ((8 * sizeof(void *)) - 1); i++){ 
			if((num & (1 << i))){   
				num = num & ~(1 << i);
                               		break;          
                                }               
                        }                      
                }                               
                printf("Answer:%d\n",num);  

	clr_r_bit(num);
}*/
#endif

/*Clear lest most set bit clear*/

#if 0
int main()
{
        int num; //User Input
        int i = 0; //Simple Variable for loop
        
        printf("\nEnter the Number:");
        scanf("%d",&num);

        if(num>=0){     
                for(i = ((8 * sizeof(void *)) - 1); i>=0; i--){
           	      if((num & (1 << i))){
                                num = num & ~(1 << i);
                                break;
                        }
                }
        }

        printf("Answer:%d\n",num);
}
#endif

/*Set right most clear bit*/


#if 0 
int main()
{
        int num; //User Input
        int i = 0; //Simple Variable for loop
        
        printf("\nEnter the Number:");
        scanf("%d",&num);

        if(num>=0){     
                for(i = 0; i <= ((8 * sizeof(void *)) - 1); i++){
                        if(!(num & (1 << i))){
                                num = num ^ (1 << i);
                                break;
                        }
                }
        }

        printf("Answer:%d\n",num);
}
#endif

/*set left most clear bit*/

#if 0
int main()
{
        int num; //User Input
        int i = 0; //Simple Variable for loop
        
        printf("\nEnter the Number:");
        scanf("%d",&num);

        if(num>=0){     
                for(i = ((8 * sizeof(void *)) - 1); i>=0; i--){
                        if(!(num & (1 << i))){
                                num = num ^ (1 << i);
                                break;
                      }
                }
        }

        printf("Answer:%d\n",num);
}
#endif

/*To set bits from bit position s to bit position d in a given number and clear rest of the bits*/

#if 0

int main()
{
        int num; //User Input
        int i = 0; //Simple Variable for loop
	int dest = 0; //User Input : Destination Position
	int srce = 0; //User Input : Source Position
  
        printf("\nEnter the Number:");
        scanf("%d",&num);
	
	printf("\nEnter the destination Position:");
	scanf("%d",&dest);
	
	printf("\nEnter the source position:");
	scanf("%d",&srce);

        if(num>=0){     
                num =((~(~0 << ((srce - dest)+1))) << (srce -dest)) | (num & 0); //set bits operation
        }
	show_bit(num);

        printf("\n");
}
#endif

/*To clear bits from bit position s to bit position d in a given number and set rest of the bits*/

#if 0 

int main()
{
        int num; //User Input
        int i = 0; //Simple Variable for loop
        int dest = 0; //User Input : Destination Position
        int srce = 0; //User Input : Source Position

        printf("\nEnter the Number:");
        scanf("%d",&num);

        printf("\nEnter the destination Position:");
        scanf("%d",&dest);

        printf("\nEnter the source position:");
        scanf("%d",&srce);

        if(num>=0){
                num =(((~0 << ((srce - dest)+1))) << (srce -dest)) | (num & 0); //set bits operation
        }
        show_bit(num);

        printf("\n");
}
#endif


