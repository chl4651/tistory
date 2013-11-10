#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_LEN 4000

char* trim(char *s);
char* ltrim(char *s);
char* rtrim(char *s);
char* cut(char *s);
void DeleteBlank(char *input);

int main(int argc, char* argv[])
{
	char output[1024];
	size_t readsize = 0;
	FILE *p1 = NULL;
	FILE *p2 = NULL;
	FILE *p = NULL;
	char *tmp;
	char tmp2[512];
	char *tmp3;
	char A[1000][512];
	char B[1000][512];
	char string1[100]; //first string
	char string2[100]; //second string
	char string3[512]; //third string
	int i, count = 0;
	int count2 = 0;

	/*
	p = popen("pwd","r");
	fgets(B,1024,p);
	printf("%s",B);
	pclose(p);
	*/
	char command1[150] = "git ls-files `git rev-parse --show-toplevel` --full name";
	char command2[1024] = "grep -n ";
	strcat(command2,argv[1]);

	p1 = popen(command1,"r");
	//p = popen("ls","r");
	//if(!p1)
	//{
	//	printf("ERROR1\n");
	//	return -1;
	//}
	//readsize = fread((void*)output,sizeof(char),1024-1,p1);
	while(fgets(A[count],512,p1))
	{
		count++;
	}
	//if(readsize == 0)
	//{
	//	pclose(p1);
	//	printf("ERROR2\n");
	//	return -1;
	//}
	
	pclose(p1);
	//output[readsize]=0;
	//tmp = strtok(output,"\0");

	//while(tmp!=NULL)
	//{
	//	//strcpy(A[count],tmp);
	//	printf("%s\n",tmp);
	//	tmp = strtok(NULL,"\0");
	//	count++;
	//}
	//printf("%d",count);
	
	strcat(command2," ");
	for(i=0;i<count;i++){
		tmp = strtok(A[i],"\n");
		strcat(command2, " ");
		strcat(command2, tmp);
	}
	//printf("%s",command2);
	
	p2 = popen(command2,"r");
	/*
	if(!p2)
	{
		printf("ERROR1\n");
		return -1;
	}
	readsize = fread((void*)output,sizeof(char),1024-1,p2);
	
	if(readsize == 0)
	{
		pclose(p2);
		printf("ERROR2\n");
		return -1;
	}
	*/
	while(fgets(B[count2],512,p2))
	{
		count2++;
	}
	pclose(p2);
	//output[readsize]=0;
	//printf("%s",output);
	
	for(i=0;i<count;i++)
		printf("%s",B[i]);


	for(i=0;i<count;i++){
		//strcpy(tmp2, cut(B[i]));
		strcpy(string1,strtok(B[i],":"));
		strcpy(string2,strtok(NULL,":"));
		strcpy(string3,strtok(NULL,"\0"));
		tmp3 = trim(string3);
		printf("%s",tmp3);
		//printf("%s:%s:%s",string1,string2,trim(string3));
	}
	//strcpy(tmp2, "   addPanel   ");
	//printf("%s", trim(tmp2));
	return 0;
}

char* rtrim(char *s){
	char t[MAX_STR_LEN];
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
	char* begin;
	begin = s;

	while(*begin!='\0'){
		if(isspace(*begin))
			begin++;
		else{
			s=begin;
			break;
		}
	}	
	return s;
}

char* trim(char *s){
	return rtrim(ltrim(s));
}
/*
void DeleteBlank(char *input)
{
	char buffer[128];
	char *p, *q;
	
	p = input;
	q = buffer;
	while(*p != '\0')
	{
		if(!isspace(*p))
		{
			*(q++) = *(p++);
		}
		else
		{
			p++;
		}
	}
	*q = '\0';
	strcpy(input,buffer);
}
*/
/*
char* cut(char *s){
	int count = 0;
	char token[1024];

	strcpy(token, strtok(s,":"));
	
	while(!strcmp(token, NULL)){

		strcpy(token, strtok(NULL,":"));
	}
	return token;
}
*/
