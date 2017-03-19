#define feof(fp) (((p)->flag & _EOF) != 0)
#define ferror(fp) (((p)->flag & _ERR) != 0)
#define fileno(fp) ((fp)->fd)

typedef struct _iobuf {
	int cnt;	/*chracter left*/
	char *ptr;	/*next chracter position*/
	char *base	/*location of buffer*/
	int flag; 	/*mode of file access*/
	int fd;		/*File Decriptor*/
}FILE;

enum _flags {
	_READ 	= 01,		/*File Open For Reading*/
	_WRITE 	= 02,		/*File open for writing*/
	_UNBUF	= 04,		/*File is unbuffered*/
	_EOF    = 010,		/*Eof has occurred on this file*/
	_ERR    = 020,		/*Error occurred in file*/
}


