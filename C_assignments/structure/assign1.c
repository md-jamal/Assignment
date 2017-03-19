/*
	Programe : Structure Format
	Author : Pritam Mali
*/


#include<stdio.h>

struct s1
{
	unsigned int GFC : 4;
	unsigned int VPI : 8;
	unsigned int VCI : 16;
	unsigned int PTI : 3;
	unsigned int CLP : 1;
	unsigned int HBC : 8;
};

struct s2
{
	unsigned int srcport : 16;
	unsigned int destport : 16;
	unsigned int seqport : 32;
	unsigned int ACKnum : 32;
	unsigned int Hdrlen : 4;
	unsigned int reserve : 6;
	unsigned int codebits : 6;
	unsigned int window : 16;
	unsigned int chksum : 16;
	unsigned int urgent : 16;
	unsigned int opt : 32;
	unsigned int data : 32;
	
};

struct s3
{

	unsigned int version : 4;
	unsigned int hdrlen : 4;
	unsigned int service_type : 8;
	unsigned int tot_len : 16;
	unsigned int identification : 16;
	unsigned int flg : 3;
	unsigned int frgment : 28;
	unsigned int TTL :8;
	unsigned int protocol : 9;
	unsigned int hdrchksum :32;
	unsigned int srcIPaddr :32 ;
	unsigned int destIPaddr : 32;
	unsigned int opt : 21;
	unsigned int srcport : 11;
	
};

int main()
{

	printf("Size s1::%d\n",sizeof(struct s1));
	printf("Size s2::%d\n",sizeof(struct s2));
	printf("Size s3::%d\n",sizeof(struct s3));
	
	return 0;
}
















