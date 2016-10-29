/*
 * BufferedFile.cpp
 *
 *  Created on: Nov 21, 2015
 *      Author: Ashwin Patil
 */

#include <iostream>
#include <unistd.h>
#include <cassert>

#include "BufferedFile.h"

using namespace std;

BufferedFile::BufferedFile(const char* filename) : fstream(filename, std::ios::out|std::ios::in),
		name(filename), getter(0),putter(0), end(0)
{

}
BufferedFile::~BufferedFile()
{
	truncate(name.c_str(),putter);
}

BufferedFile& BufferedFile::get(char& ch)
{
	if(deque.empty() && end != -1)
	{
		fstream::seekg(getter);
		getter+=1;
		ch = end = fstream::get();


	}
	else
	{
		ch = deque.front();
		deque.pop_front();
	}

	return *this;
}

void BufferedFile :: doOver(char ch)
{
	deque.push_front(ch);
}

void BufferedFile::put(char ch)
{
	if(putter >= getter && end != -1)
	{
		char temp;
		fstream::seekg(getter);
		getter += 1;
		temp = end = fstream :: get();
		deque.push_back(temp);
	}
	fstream :: clear();
	fstream :: seekp(putter);
	fstream :: put(ch);
	putter += 1;

}

bool BufferedFile :: eof()
{
	if(deque.empty() && end == -1)
	{
		return true;
	}
	else
	{
		return false;
	}

}
