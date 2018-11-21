#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int ls(char *argv)
{
	DIR	 *pdir;
	struct dirent *pde;
	struct stat buf;
	
	int i = 0;
	int count = 0;
	char *dir_name[255];

	memset(dir_name, '\0', sizeof(dir_name));
	memset(&pde, '\0', sizeof(pde));
	memset(&buf, '\0', sizeof(buf));

	if((pdir = opendir(argv)) < 0)
	{
		perror("opendir");
