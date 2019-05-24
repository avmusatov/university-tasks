#pragma once
#ifndef BITS_H
#define BITS_H
union Numbers
{
	int a;
	float b;
};
int inbit(Numbers);
enum markaavto { BMW, Lada, Taiota, YAZ, GAZ };
enum cvet { white, black, red, blue };

struct Auto
{
	//enum markaavto{BMW,Lada,Taiota,YAZ,GAZ};
	enum markaavto marka;
	//enum cvet{white,black,red,blue};
	enum cvet color;
	int kolvo;
	int cost;
	bool sklad;
	bool sale;
};

#endif