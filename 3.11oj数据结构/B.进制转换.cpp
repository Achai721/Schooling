#include<stdio.h>
using namespace std;
int main() {
	int i=0,j,n,b,m,r;
	char a[1000];
	while(scanf("%d%d",&n,&r)!=EOF) {
		if (n< 0) { //当负数进行进制转换时进行如下运算
			printf("-");
			n=n-2*n;//变正为负 
		}
		switch(n) {
			case 0:
				break;
			default:
				break;
		}
		while(n!=0) { //当一个正数进行进制转换时，用这个数除以要转换的进制数，保留余数，如果商不为0，就用商接着除以这个进制数，直到商为0时结束，把各个相除的余数存入数组，最后倒叙输出，即为要求进制数
			++i;//i自增1 
			b=n/r;//除以要转换成的进制数
			a[i]=n%r;//把余数存入数组
			n=b;//如果商不为0就把商接着赋给n继续运算
		}
		for(j=i; j>0; j--) {
			if(a[j]>=10&&a[j]<=16) {
				if(j!=1)
					printf("%c",a[j]+55);//当要转换成10到16进制时把大于十的数用字母表示
				else
					printf("%c\n",a[j]+55);
				i=0;
			} else {
				if(j!=1)
					printf("%d",a[j]);
				else
					printf("%d\n",a[j]);
				i=0;
			}
		}
	}
	return 0;
}
