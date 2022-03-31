
int		auth(char *buf, int n)
{
	int	res;
	int	len;

	buf[strcspn(buf, "\n")] = '\0';
	len = strnlen(buf, 32);
	if (len <= 5)
		return 1;
	if (ptrace(0, 0, 1, 0) == -1)
	{
		puts("\033[32m.---------------------------.");
		puts("\033[31m| !! TAMPERING DETECTED !!  |");
		puts("\033[32m'---------------------------'");
		return 1;
	}
	res = (buf[3] ^ 0x1337) + 0x5eeded;
	int	i = 0;
	while (i < len)
	{
		if (buf[i] >= 31)
			return 1;

			res = do_some_magic(res, i, buf);
		i++;
	}
	if (res == n)
		return 0;
	else
		return 1;
}


int		main(int ac, char **av)
{
	char buf[32];
	unsigned int n;

	puts("***********************************");
	puts("*\t\tlevel06\t\t  *");
	puts("***********************************");
	printf("-> Enter Login: ");
	fgets(buf, 32, stdin);
	puts("***********************************");
	puts("***** NEW ACCOUNT DETECTED ********");
	puts("***********************************");
	printf("-> Enter Serial: ");
	scanf("%u", &n);
	if (auth(buf, n) == 0)
	{
		puts("Authenticated!");
		system("/bin/sh");
		return 0;
	} 
	else
		return 1;
}
