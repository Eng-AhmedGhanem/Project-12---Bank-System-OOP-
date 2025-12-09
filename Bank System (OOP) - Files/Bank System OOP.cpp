
#include <iostream>
#include "clsLoginScreen.h"
#include "clsUser.h"
#include "Global.h"
using namespace std;

template<typename T> 
class Calculator

{
private:
	 
	T _X;
	T _Y;

public:


	Calculator(T x , T y)
	{
		_X = x;
		_Y = y;
	}

	T Sum()
	{
		return _X + _Y;
	}

	T Subtract()
	{
		return _X - _Y;
	}

	T Multiply()
	{
		return _X * _Y;
	}

	T Divide()
	{
		return _X / _Y;
	}

};

int main()
{
	Calculator<char> Cal('a', 'v');

	cout << Cal.Sum() << endl;
	cout << Cal.Subtract() << endl;
	cout << Cal.Multiply() << endl;
	cout << Cal.Divide() << endl;
	
	
	/*while (true)
	{
		if (!clsLoginScreen::ShowLoginScreen())
		{
			break;
		}
	}*/

}


