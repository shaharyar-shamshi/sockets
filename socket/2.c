#include"ds.h"
int main()
{
	struct sockaddr_un addr;
	int skret,cfd,len;
	char *ch,*c;
	ch=(char*)malloc(sizeof(char)*50);
	c=(char*)malloc(sizeof(char)*50);
	//ch="long note book";
	skret=socket(AF_UNIX,SOCK_STREAM,0);
	
	addr.sun_family=AF_UNIX;
	strcpy(addr.sun_path,"SERVER_SOCKET");
	len=strlen(addr.sun_path);
	scanf("%s",ch);
	cfd=connect(skret,(struct sockaddr *) & addr,len);
	write(skret,ch,50);
	read(skret,c,50);
	printf("read val =%s\n",c);
}
	

