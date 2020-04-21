#ifdef HOMIE_H
char charBuf[BUFFER_LENGHT_FOR_STRTOCHARARRAY_FUNC];
char* strToCharArray(String s)
	 {
	 s.toCharArray(charBuf, s.length()+1);
	 return charBuf;
}
#endif