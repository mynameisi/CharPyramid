#include <stdio.h>
#include <stdlib.h>

int main(void) {


	
    char c = 'A';
    int height;
    
	/* ֪ʶ��0: ����һ���ǳ��õ�ģʽ��
	 * Ҫ���û�����һ����Ϣ����������Ϣ����ĳ�������ͼ������������������������
	 */
	do {
        printf("Enter strictly positive number: "); //��ӡ��ʾ��Ϣ
        rewind(stdin);								//����������������������һλ
    } while ((!scanf("%d", &height) || height < 1 ) && !fflush(stdin));	
	/* ����������� <1 ���� �޷��ɹ������������ʱ��[�޷��ɹ���������������������ȡ��������ʱ�����˴���] 
	 * ������������
	*/
	
    for (int i = 1; i <= height; ++i) {			//i��ʾ��ʾ������
        for (int j = 0; j < height - i; ++j)	//j��ʾ�����Ҫ���ٿո�
            printf(" ");
        for (int k = 1; k < i; ++k) {
            printf("%c", c);
            c = (c - 'A' + 1) % 26 + 'A';		//֪ʶ��1���õ�һ��������ĸ֮����Ǹ���ĸ
        }
       
        printf("%c", c);						//��ӡ�м���Ǹ���ĸ
 
        for (k = 1; k < i; ++k) {
            
            c = (c -'A' + 25) % 26 + 'A';		//֪ʶ��2���õ�һ��������ĸ֮ǰ���Ǹ���ĸ
            printf("%c", c);
        }
        printf("\n");
       
        c = ((1 + i) * i / 2) % 26 + 'A';		//֪ʶ�㣺������µ�һ�е�����ĸ
												//���⣺���Բ���ͨ��֪ʶ��1���õ������ĸ?
		
    }
    return EXIT_SUCCESS;						//֪ʶ��3���� macro ����ʽ���� 0�� �ȼ��� return 0;
}