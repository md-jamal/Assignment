#include<stdio.h>

int a;
int b = 0;

static int c;
static int d = 10;

const int e;
const int f = 0;

static const int g = 0;
static const int h = 10;

volatile int i;
volatile int j = 9;

static volatile int k ;
static volatile int l = 8;

static const volatile int m;
static const volatile int n =10;

int main()
{
	;
	return 0;
}

