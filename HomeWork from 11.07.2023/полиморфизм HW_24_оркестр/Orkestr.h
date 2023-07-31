#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <MMSystem.h>
#pragma comment (lib, "winmm")

using namespace std;

class Musical_Instrument
{
protected:
	string name;
public:
	Musical_Instrument(const string& instr_name) : name(instr_name) {}
	virtual ~Musical_Instrument() {}
	virtual void Play() = 0;
	void Set_Name(const string& instr_name) { name = instr_name; }
	string getName() const { return name; }

};

class Wind_Instrument : public Musical_Instrument
{
public:
	Wind_Instrument(const string& instr_name) : Musical_Instrument(instr_name) {}
	void Play();
};

class String_Instrument : public Musical_Instrument
{
public:
	String_Instrument(const string& instr_name) : Musical_Instrument(instr_name) {}
	void Play();
};

class Saxophone : public Wind_Instrument
{
public:
	Saxophone(const string& instr_name) : Wind_Instrument(instr_name) {}
	void Play();
};

class Flute : public Wind_Instrument
{
public:
	Flute(const string& instr_name) : Wind_Instrument(instr_name) {}
	void Play();
};

class Trumpet : public Wind_Instrument
{
public:
	Trumpet(const string& instr_name) : Wind_Instrument(instr_name) {}
	void Play();
};

class Violin : public String_Instrument
{
public:
	Violin(const string& instr_name) : String_Instrument(instr_name) {}
	void Play();
};

class Guitar : public String_Instrument
{
public:
	Guitar(const string& instr_name) : String_Instrument(instr_name) {}
	void Play();
};

class Balalaika : public String_Instrument
{
public:
	Balalaika(const string& instr_name) : String_Instrument(instr_name) {}
	void Play();
};

class Orkestr 
{
private:
	string name;
	Musical_Instrument* instruments[6];
public:
	Orkestr(const string& orkestr_name) : name(orkestr_name) {}
	void addInstrument(Musical_Instrument* instr, int index);
	void playConcert();
};

void func_main();
