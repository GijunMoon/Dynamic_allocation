//2019/08/16
#include <stdio.h>
#include <stdlib.h> //메모리 할당 함수(malloc)를 위한 헤더
#include <string.h>// 문자열을 위한 헤더

int main() {
	int arraySize = 4; //배열 크기
	char * nchar[arraySize]; 
	char buffer[30]; //입력을 위한 버퍼

	int n = 0;
	int i = 0;

	while (n < arraySize)
	{
		scanf("%s", buffer); //버퍼에 문자열 입력 후 메모리 할당
		i = strlen(buffer);//버퍼 내용 복사
		if (i > 0) {
			char* nstrptr = (char*)malloc(sizeof(char) * (i + 1));
			strcpy(nstrptr, buffer);
			nchar[n] = nstrptr;
			n++;
		}
		else
		{
			break;
		}
	}

	for (n = 0; n < arraySize; n++) {
		/**배열을 순회하면서 해당 값의 메모리에서 시작되는 문자열 출력
		출력 후에는 메모리 해제 후 파괴**/
		printf("%02d: %s\n", n, nchar[n]);
		free(nchar[n]);
	}
	return 0;
}
