#include <stdio.h>

int main(){
	float a,b, res;
	char c;

	scanf("%f", &a);
	scanf("%f", &b);
	scanf(" %c", &c);

	if(c == '/'){
		res = a/b;
	}
	if(c == '%'){
		res = (int)a%(int)b;
	}
	if(c == '+'){
		res = a+b;
	}
	if(c == '-'){
		res = a-b;
	}

	printf("%.1f", res);

	return 0;
}