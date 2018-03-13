#include"ds.h"
int main()
{
	struct sockaddr_in addr;
	int skret,cfd,len;
	char *ch,*c;
	ch=(char*)malloc(sizeof(char)*50);
	c=(char*)malloc(sizeof(char)*50);
	//ch="long note book";
	skret=socket(AF_INET,SOCK_STREAM,0);
	
	addr.sin_family=AF_INET;
	addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	addr.sin_port=htons(4000);
	len=sizeof(struct sockaddr_in);
	scanf("%s",ch);
	printf("client\n");
	cfd=connect(skret,(struct sockaddr *) & addr,len);
	if(cfd == -1)
	{
		perror("error in connect");
	}
	printf("client----%d\n",cfd);
	write(skret,ch,1);
	read(skret,c,1);
	printf("read val =%s\n",c);
}	
