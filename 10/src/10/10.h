#pragma once
#include <cassert>

struct obj {
	int x;
	int y;
};


void rotate(obj& myObj, int angleTimes) {
	switch (angleTimes)
	{
	case 0: {break; }
	case 1: { 
		int tmp = myObj.y;
		myObj.y = -myObj.x;
		myObj.x = tmp;
		break;
	}
	case 2: { myObj.x *= -1;  myObj.y *= -1;  break; }
	case 3: {
		int tmp = myObj.x;
		myObj.x = -myObj.y;
		myObj.y = tmp;
		break; 
	}
	default:
		angleTimes -= 4;
		rotate(myObj, angleTimes);
		break;
	}

}