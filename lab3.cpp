#include <iostream>
#include <stack>
#include <string>

using namespace std;

class checker{
	private:
		string String;

	public:
		void setString(string str)
		{
			String = str;
		}


		/*constructor*/
		checker(string str)
		{
			String = str;
		}

		bool stringchecker(string str)
		{
			//create stack
			stack<char> stringStack;
			/*go through each character of the string*/
			for(int i = 0; i < str.size(); i++ )
			{
				char k = str[i];

				if ( k == '<' || k == '{' || k == '(' || k == '[' || k == ' ')
				{
					stringStack.push(k);
				}
				else if (k == '>' || k == '}' || k == ')' || k == ']' || k == ' ')
				{
					if (stringStack.size() == 0)
					{
						return false;
					}

					char endvalue = stringStack.top();
					/*remove the top so nothing remains in stack*/
					stringStack.pop();

					if ((k == '>' && endvalue != '<') || (k == '}' && endvalue != '{') || (k == ')' && endvalue != '(') || (k == ']' && endvalue != '[') || (k == ' ' && endvalue != ' '))
					{
						return false;
					}
				}
			}

			if (stringStack.empty())
			{
				return true;
			}
			else {
				return false;
			}


		}




};

int main()
{
	string str;
	cout << "Delimiter checker" << endl;
	cout << "Enter a string with delimiters: ";
	cin >> str;


	checker check = checker(str);

	if (check.stringchecker(str)) /*if this returns true then string is delimited therefore if false string is not*/
	{
		cout << "String is delimited";
	}
	else {
		cout << "String is not delimited";
	}
}


/*
Sample runs

Run 1
kevinalvarez@Kevins-MacBook CS136 % g++ lab3.cpp 
kevinalvarez@Kevins-MacBook CS136 % ./a.out
Delimiter checker
Enter a string with delimiters: <dsadsa>
String is delimited%   

Run 2 
kevinalvarez@Kevins-MacBook CS136 % g++ lab3.cpp
kevinalvarez@Kevins-MacBook CS136 % ./a.out     
Delimiter checker
Enter a string with delimiters: <dsadsa}
String is not delimited%   

Run 3
kevinalvarez@Kevins-MacBook CS136 % g++ lab3.cpp 
kevinalvarez@Kevins-MacBook CS136 % ./a.out     
Delimiter checker
Enter a string with delimiters: <dsadsa>
String is delimited%    

Run 4
kevinalvarez@Kevins-MacBook CS136 % g++ lab3.cpp  
kevinalvarez@Kevins-MacBook CS136 % ./a.out
Delimiter checker
Enter a string with delimiters: < dsadas > } ]
String is not delimited%                            

*/