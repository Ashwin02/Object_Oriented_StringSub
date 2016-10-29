/*
 * main.cpp
 *
 *  Created on: Nov 21, 2015
 *      Author: Ashwin Patil
 */


#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

#include "StreamSource.h"

using namespace std;

int main(int argc , const char* argv[])
{
	if(argc != 4)
		{
			cout<<"Invalid number of arguments ...!!! "<<endl;
			return 1;
		}

	string oldstring = argv[1];
	string newstring = argv[2];
	StreamSource stream(oldstring,newstring,argv[3]);
	int cnt;
	char ch;

	while(!stream.get(ch).eof())
	{
		if(!stream.replacing() && ch == oldstring[cnt])
		{
			cnt++;
			if(cnt < oldstring.size())
			{
				continue;
			}
		}

		if(cnt == oldstring.size())
		{
			stream.match();
		}
		else if(cnt > 0)
		{
			stream.halfMatch(ch,cnt);

		}
		else
		{
			stream.put(ch);
		}
		cnt = 0;
	}
	return 0;
}




