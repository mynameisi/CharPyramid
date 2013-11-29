#include <stdio.h>
#include <stdlib.h>

int main(void) {


	
    char c = 'A';
    int height;
    
	/* 知识点0: 这是一个非常好的模式：
	 * 要求用户输入一个信息，如果这个信息满足某个条件就继续，如果不满足则重新输入
	 */
	do {
        printf("Enter strictly positive number: "); //打印提示信息
        rewind(stdin);								//把输入流的输入点调整到第一位
    } while ((!scanf("%d", &height) || height < 1 ) && !fflush(stdin));	
	/* 当输入的内容 <1 或者 无法成功清空输入流的时候[无法成功清空输入流，表明程序读取输入流的时候发生了错误] 
	 * 程序重新启动
	*/
	
    for (int i = 1; i <= height; ++i) {			//i表示显示多少行
        for (int j = 0; j < height - i; ++j)	//j表示左边需要多少空格
            printf(" ");
        for (int k = 1; k < i; ++k) {
            printf("%c", c);
            c = (c - 'A' + 1) % 26 + 'A';		//知识点1：得到一个任意字母之后的那个字母
        }
       
        printf("%c", c);						//打印中间的那个字母
 
        for (k = 1; k < i; ++k) {
            
            c = (c -'A' + 25) % 26 + 'A';		//知识点2：得到一个任意字母之前的那个字母
            printf("%c", c);
        }
        printf("\n");
       
        c = ((1 + i) * i / 2) % 26 + 'A';		//知识点：计算出新的一行的首字母
												//问题：可以不可通过知识点1，得到这个字母?
		
    }
    return EXIT_SUCCESS;						//知识点3：用 macro 的形式返回 0， 等价于 return 0;
}