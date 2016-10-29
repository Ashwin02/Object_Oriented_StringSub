/*
 * BufferedFile.h
 *
 *  Created on: Nov 21, 2015
 *      Author: Ashwin Patil
 */

#ifndef BUFFEREDFILE_H_
#define BUFFEREDFILE_H_

#include <fstream>
#include <string>
#include "TrackingDeque.h"

using namespace std;

class BufferedFile : public std :: fstream
{
public:
	BufferedFile(const char* filename);
	~BufferedFile();
	void doOver(char ch);
	void put(char ch);
	BufferedFile& get(char& ch);
	bool eof();

private:
	string name;
	streampos getter;
	streampos putter;
	TrackingDeque<char> deque;
	int end;

};


#endif /* BUFFEREDFILE_H_ */
