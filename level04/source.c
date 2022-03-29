int main()
{
	char buffer[0x20];
	var child_pid = fork();
	bzero(buffer, 0x20);
	var status = 0;
	if (child_pid == 0)
	{
		prctl(1,1);
		ptrace(0,0,0,0);
		puts("Give me some shellcode, k");
		gets(buffer);
	}
	else
	{
		do
		{
			wait(&status);
			if (status & 0x7f) == 0 || (((status & 0x7f) + 1) >> 1) > 0)
			{
				puts("child is exiting...");
				break;
			}
		} while(0xb != ptrace(3, child_pid, 44, 0));
		puts("no exec() for you");;
		kill(child_pid, 9);
	}
	return 0;
}
