/*
 * StreamSource.h
 *
 *  Created on: Nov 21, 2015
 *      Author: Ashwin Patil
 */

#ifndef STREAMSOURCE_H_
#define STREAMSOURCE_H_

#include <string>
#include "BufferedFile.h"

class StreamSource{
public:
	StreamSource(const string& oldstring,const string& newstring, const char* filename);
	StreamSource& get(char& ch);
	void put(char ch);
	bool replacing();
	bool eof();
	void match();
	void halfMatch(char ch, int cnt);

private:
	BufferedFile file;
	string search;
	string replace;
	int writeNo;
	int partialNo;
	int curPartialNo;
	bool canReplace;
};



#endif /* STREAMSOURCE_H_ */
