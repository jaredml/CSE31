
int fib(int clk)
{
int r1 = 1;
int r2 = 0;
int sum = 0;
while(clk == 1)
{
int sum = r1+r2;
r2=r1;
r1=sum;
}
return r2;
}

