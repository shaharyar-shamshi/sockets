#include"ds.h"
int main()
{
	int skret,len,acfd,len1;
	struct sockaddr_in skaddr;
	struct sockaddr_in sk;
	skret=socket(AF_INET,SOCK_STREAM,0);
	skaddr.sin_family=AF_INET;
	skaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	skaddr.sin_port=htons(4000);
	len=sizeof(struct sockaddr_in);
	len1=sizeof(struct sockaddr_in);
	bind(skret,(struct sockaddr *) &skaddr,len);
	listen(skret,5);
	while(1)
	{
		char *ch,c;
		ch=(char*)malloc(sizeof(char)*50);
		printf("hello\n");
		acfd=accept(skret,(struct sockaddr *) &sk,&len);
		printf("acfd %d\n",acfd);
		if(acfd==-1)
		{
			perror("accept");
		}
		printf("waiting for client\n");
		read(acfd,&c,1);
		printf("%c\n",c);
		printf("%c\n",c);
		write(acfd,&c,50);
		
	}
	return 0;
}
	
	
