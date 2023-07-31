#include "Orkestr.h"
#include <MMSystem.h>
#pragma comment (lib, "winmm")

void Orkestr::addInstrument(Musical_Instrument* instr, int index)
{
	try
	{
		if (index < 0 && index > 6)
		{
			throw invalid_argument("Error input index\n");
		}
		else
		{
			instruments[index] = instr;
		}
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
}

void Orkestr::playConcert()
{
	cout << "Dear guests, welcome to the concert\n" <<
		"Today for you will play " << this->name << " Orkestr\n" <<
		"============================================================\n" <<
		"Start the concert : \n";
	try
	{
		for (int i = 0; i < 3; ++i)
		{
			if (!instruments)
			{
				throw invalid_argument("Ñould not access the element or the element is empty\n");
			}
			else
			{
				instruments[rand() % 3]->Play();
				instruments[ 3 + rand() % (5 -3)]->Play();
			}
		}
	}
	catch (const std::exception& e)
	{
		cout << e.what();
	}
}

void Wind_Instrument::Play()
{
	cout << "Playing " << name << " (Wind Instrument)" << endl;
}

void String_Instrument::Play()
{
	cout << "Playing " << name << " (String Instrument)" << endl;
}

void func_main()
{
	Flute flute("Flute");
	Trumpet trumpet("Trumpet");
	Saxophone saxophone("Saxophone");
	Violin violin("Violin");
	Guitar guitar("Guitar");
	Balalaika balalaika("Balalaika");
	
	Orkestr orkestr("Musical");
	
	orkestr.addInstrument(&flute, 0);
	orkestr.addInstrument(&trumpet, 1);
	orkestr.addInstrument(&saxophone, 2);
	orkestr.addInstrument(&violin, 3);
	orkestr.addInstrument(&guitar, 4);
	orkestr.addInstrument(&balalaika, 5);

	orkestr.playConcert();
}

void Saxophone::Play()
{
	Wind_Instrument::Play();
	PlaySound(TEXT("saksofon.wav"), NULL, SND_FILENAME | SND_ASYNC);
	Sleep(5000);
}

void Flute::Play()
{
	Wind_Instrument::Play();
	PlaySound(TEXT("fleyta.wav"), NULL, SND_FILENAME | SND_ASYNC);
	Sleep(5000);
}

void Trumpet::Play()
{
	Wind_Instrument::Play();
	PlaySound(TEXT("truba.wav"), NULL, SND_FILENAME | SND_ASYNC);
	Sleep(5000);
}

void Violin::Play()
{
	String_Instrument::Play();
	PlaySound(TEXT("skripka.wav"), NULL, SND_FILENAME | SND_ASYNC);
	Sleep(1500);
}

void Guitar::Play()
{
	String_Instrument::Play();
	PlaySound(TEXT("bass-gitara.wav"), NULL, SND_FILENAME | SND_ASYNC);
	Sleep(1500);
}

void Balalaika::Play()
{
	String_Instrument::Play();
	PlaySound(TEXT("balalayka.wav"), NULL, SND_FILENAME | SND_ASYNC);
	Sleep(5000);
}
