#include <stdio.h>
#include <stdlib.h>

#include "../algo_prac/algo_str/cust_str.h"

#define LINE_SIZE 64

char* justifyLine(struct StringBuilder* lineBuf) {
	int spaces = 0;
	int characters = 0;
	int len = sbsize(lineBuf);
	char* temp = sbgetstr(lineBuf);
	for(int i = 0; i < len; i++) {
		if(temp[i] == ' ') {
			spaces++;
		}
		else {
			characters++;
		}
	}
	int totalSpaces = LINE_SIZE-characters;
	int extraCount = totalSpaces%spaces;
	int evenDistrib = (totalSpaces - extraCount)/spaces;
	int curSpace = 0;
	struct StringBuilder sb;
	sbinit(&sb);
	for(int i = 0; i < len; i++) {
		if(temp[i] == ' ') {
			//Push evenDistrib spaces to the final string if curSpace >= extraCount
			//Else push evenDistrib+1 spaces
			if(curSpace < extraCount) {
				for(int j = 0; j < evenDistrib+1; j++) {
					sbappendchar(&sb, ' ');
				}
			}
			else {
				for(int j = 0; j < evenDistrib; j++) {
					sbappendchar(&sb, ' ');
				}
			}
			curSpace++;
		}
		else {
			sbappendchar(&sb, temp[i]);
		}
	}
	return sbgetstr(&sb);
}

char* formatFile(const char* fileName) {
	FILE* file = fopen(fileName, "r");
	struct StringBuilder ret;
	struct StringBuilder lineBuf;
	struct StringBuilder wordBuf;

	sbinit(&ret);
	sbinit(&lineBuf);
	sbinit(&wordBuf);
	int done=0;
	char c;
	do {
		c = fgetc(file);
		if(feof(file) || c==EOF || c == '\377') {
			if(sbsize(&lineBuf) + sbsize(&wordBuf) > LINE_SIZE) {
				//TODO: push linebuf to ret and add a '\n'
				sbappendstring(&ret, justifyLine(&lineBuf));
				free(lineBuf.data);
				sbinit(&lineBuf);
				sbappendchar(&ret, '\n');
				sbappendstring(&ret, sbgetstr(&wordBuf));
				sbappendchar(&ret, '\n');
			}
			else {
				sbappendchar(&lineBuf, ' ');
				sbappendstring(&lineBuf, sbgetstr(&wordBuf));
				sbappendstring(&ret, justifyLine(&lineBuf));
				free(lineBuf.data);
				sbinit(&lineBuf);
				sbappendchar(&ret, '\n');
			}
			done = 1;
		}
		else if(c != ' ' && c!='\t' && c!= '\n') {
			sbappendchar(&wordBuf, c);
		}
		else {
			if(sbsize(&lineBuf) + sbsize(&wordBuf) > LINE_SIZE) {
				sbappendstring(&ret, justifyLine(&lineBuf));
				sbappendchar(&ret, '\n');
				free(lineBuf.data);
				sbinit(&lineBuf);
				sbappendstring(&lineBuf, sbgetstr(&wordBuf));
				sbappendchar(&lineBuf, ' ');
				free(wordBuf.data);
				sbinit(&wordBuf);
			}
			else {
				sbappendstring(&lineBuf, sbgetstr(&wordBuf));
				sbappendchar(&lineBuf, ' ');
				free(wordBuf.data);
				sbinit(&wordBuf);
			}
		}
	} while(!done);
	free(lineBuf.data);
	free(wordBuf.data);
	return sbgetstr(&ret);
}
