#ifndef UCLN_H
#define UCLN_H
int UCLN(int a, int b)
{ 
	int r= a%b;
	while (r!=0)
	{
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}
#endif /* UCLN_H */
