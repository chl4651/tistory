#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>


char* trim(char *s);
char* ltrim(char *s);
char* rtrim(char *s);


int main(int argc, char* argv[])
{

	FILE *p1 = NULL;
	FILE *p2 = NULL;
	char *tmp;
	char *tmp2;
	char A[1000][512];
	char B[1000][512];
	char *string1; //first string
	char *string2; //second string
	char *string3; //third string
	int i;
	int count = 0;
	int count2 = 0;

	char command1[150] = "git ls-files `git rev-parse --show-toplevel` --full name";
	char command2[1024] = "grep -n -i ";
	strcat(command2,argv[1]);

	p1 = popen(command1,"r");

	while(fgets(A[count],512,p1))
	{
		count++;
	}

	pclose(p1);

	
	strcat(command2," ");
	for(i=0;i<count;i++){
		tmp = strtok(A[i],"\n");
		strcat(command2, " ");
		strcat(command2, tmp);
	}

	p2 = popen(command2,"r");

	while(fgets(B[count2],512,p2))
	{
		count2++;
	}
	pclose(p2);
	


	for(i=0;i<count2;i++){
		if(!strcmp(B[i],""))
			break;
		else
		{
			string1 =strtok(B[i],":");
			string2 =strtok(NULL,":");
			string3 =strtok(NULL,"\0");
			tmp2 = trim(string3);

			printf("%s:%s:%s\n",string1,string2,tmp2);
		}
	}

	return 0;
}

char* rtrim(char *s){
	char t[1024];
	char *end;

	strcpy(t,s);
	end=t+strlen(t)-1;
	while(end!=t&&isspace(*end))
		end--;
	*(end+1)='\0';
	s=t;

	return s;
}


char* ltrim(char *s){
	while(*s)
	{
		if(!isspace(*s))
		{
			return s;
		}
		s++;
	}
	
	return (char*)"";
}

char* trim(char *s){
	return rtrim(ltrim(s));
}

