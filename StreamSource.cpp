/*
 * StreamSource.cpp
 *
 *  Created on: Nov 21, 2015
 *      Author: Ashwin Patil
 */

#include <iostream>
#include <unistd.h>
#include <cassert>

#include "BufferedFile.h"
#include "StreamSource.h"

using namespace std;

StreamSource::StreamSource(const string& oldstring,const string& newstring,
		const char* filename) :file(filename), search(oldstring),replace(newstring),
				writeNo(0),partialNo(0),curPartialNo(0),canReplace(false)
{

}


bool StreamSource ::replacing()
{
	return canReplace;
}

bool StreamSource :: eof()
{
	if(!canReplace && curPartialNo == partialNo && file.eof())
	{
		return true;
	}
	else
	{
		return false;
	}
}

StreamSource& StreamSource::get(char& ch)
{
	if(writeNo == 0 && canReplace == true)
	{
		canReplace = false;
	}
	if(writeNo > 0)
	{
		ch = replace[replace.size() - writeNo];
		writeNo--;
	}
	else if(curPartialNo < partialNo)
	{
		ch = search[curPartialNo];
		curPartialNo++;
	}
	else
	{
		file.get(ch);
	}

	return *this;
}

void StreamSource :: match()
{
	writeNo = replace.size();
	canReplace = true;
}

void StreamSource :: halfMatch(char ch , int cnt)
{
	put(search[0]);
	if(partialNo == curPartialNo)
	{
		file.doOver(ch);
		partialNo =cnt;
		curPartialNo = 1;
	}
	else
	{
		curPartialNo = partialNo - cnt - 1;
	}

}

void StreamSource :: put(char ch)
{
	file.put(ch);
}
