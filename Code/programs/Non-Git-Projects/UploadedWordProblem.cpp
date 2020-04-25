#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

// my code treats uppercase and lowercase characters differently; please input only lowercase characters

void printmapping(int **a, string inp0, string inp1, string inp2)
{
	for(int i = 0; i < 26; i++)
	{
		if(a[i][0] != -1)
		{
			char alphabet = 'a' + i;
			cout << alphabet << '=' << a[i][0] <<", ";
		}
	}
//		cout << "6	";
	for (int i = 0; i < 26; i++)
	{
		if(a[i][1] != -1)
		{
			char alphabet = 'a' + i;
			cout << alphabet << '=' << a[i][1] <<", ";
		}
	}	
//		cout << "7	";
	for (int i = 0; i < 26; i++)
	{
		if(a[i][2] != -1)
		{
			char alphabet = 'a' + i;
			cout << alphabet << '=' << a[i][2] <<", ";
		}
	}
	cout << endl;
}


void initialization(int **a, string &inp0, string &inp1, string &inp2)
{
	for (int i = 0; i < inp0.length(); i++)
		a[inp0[i] - 'a'][0] = 0;

	for (int i = 0; i < inp1.length(); i++)
		a[inp1[i] - 'a'][1] = 0;	

	for (int i = 0; i < inp2.length(); i++)
		a[inp2[i] - 'a'][2] = 0;
}


void resutingcharassignment(int **a, string &inp0, string &inp1, string &inp2, int pos, int carry)
{
	if(pos <= inp0.length()-1 && pos <= inp1.length()-1)
	{
//		cout<<"5a"<<endl;
		if(a[inp2[pos] - 'a'][2] != a[inp0[pos] - 'a'][0] || a[inp2[pos] - 'a'][2] != a[inp1[pos] - 'a'][1])
		{
			if(a[inp0[pos] - 'a'][0] != -1 && a[inp1[pos] - 'a'][1] != -1)
			{
				a[inp2[pos] - 'a'][2] = (a[inp0[pos] - 'a'][0] + a[inp1[pos] - 'a'][1] + carry)%10;
				carry = (a[inp0[pos] - 'a'][0] + a[inp1[pos] - 'a'][1] + carry)/10;
			}
			else
			{
				a[inp2[pos] - 'a'][2] = (max(a[inp0[pos] - 'a'][0], a[inp1[pos] - 'a'][1]) + carry)%10;
				carry = (max(a[inp0[pos] - 'a'][0], a[inp1[pos] - 'a'][1]) + carry)/10;	
			}
		}
		else if(a[inp2[pos] - 'a'][2] == a[inp0[pos] - 'a'][0])
		{
			a[inp1[pos] - 'a'][1] = 0;
		}
		else if(a[inp2[pos] - 'a'][2] == a[inp1[pos] - 'a'][1])
		{
			a[inp0[pos] - 'a'][0] = 0;
		}
		else if(a[inp2[pos] - 'a'][2] == a[inp0[pos] - 'a'][0] && a[inp2[pos] - 'a'][2] == a[inp1[pos] - 'a'][1])
		{
			a[inp2[pos] - 'a'][2] = 0;
			a[inp1[pos] - 'a'][1] = 0;
			a[inp0[pos] - 'a'][0] = 0;
		}
	}
	else if(pos > inp0.length()-1 && pos <= inp1.length()-1)
	{
		a[inp2[pos] - 'a'][2] = (a[inp1[pos] - 'a'][1] + carry)%10 ;
	}
	else if(pos <= inp0.length()-1 && pos > inp1.length()-1)
	{
		a[inp2[pos] - 'a'][2] = (a[inp0[pos] - 'a'][0] + carry)%10;
	}
	else if(pos > inp0.length()-1 && pos > inp1.length()-1)
	{
		a[inp2[pos] - 'a'][2] = carry;
	}	
	if((a[inp2[pos] - 'a'][0] != -1) && (a[inp2[pos] - 'a'][0] != a[inp2[pos] - 'a'][2]))
		a[inp2[pos] - 'a'][0] = a[inp2[pos] - 'a'][2];
	if((a[inp2[pos] - 'a'][1] != -1) && (a[inp2[pos] - 'a'][1] != a[inp2[pos] - 'a'][2]))
		a[inp2[pos] - 'a'][1] = a[inp2[pos] - 'a'][2];
}
 

int currentvalue(int **a, string &source, int pos)
{
	for(int j = 0; j < 9; j++)
	{
		if( a[source[pos] - 'a'][1] == j)
			return j;
	}	
} 


void reassigninp1(int **a, string &inp0, string &inp1, string &inp2, int pos)
{
	if(a[inp1[pos] - 'a'][1] != 9)
	{
		a[inp1[pos] - 'a'][1] = currentvalue(a, inp1, pos) + 1;
		if(a[inp1[pos] - 'a'][1] == a[inp1[pos] - 'a'][0] + 1)
			a[inp1[pos] - 'a'][0] = a[inp1[pos] - 'a'][1];
		if(a[inp1[pos] - 'a'][1] == a[inp1[pos] - 'a'][2] + 1)
			a[inp1[pos] - 'a'][2] = a[inp1[pos] - 'a'][1];
	}
	else
	{
		a[inp1[pos] - 'a'][1] = 0;
		if(a[inp0[pos] - 'a'][0] != 9)
		{
			a[inp0[pos] - 'a'][0] = currentvalue(a, inp0, pos) + 1;
			if(a[inp0[pos] - 'a'][0] == a[inp0[pos] - 'a'][1] + 1)
				a[inp0[pos] - 'a'][1] = a[inp0[pos] - 'a'][0];
			if(a[inp0[pos] - 'a'][0] == a[inp0[pos] - 'a'][2] + 1)
				a[inp0[pos] - 'a'][2] = a[inp0[pos] - 'a'][0];
		}
		else
			return;
	}
}


bool checkposition(int **a, string &inp0, string &inp1, string &inp2, int pos, int carry)//needs work
{
	if(pos != inp2.length() - 1)
	{
		if(pos <= inp0.length()-1 && pos <= inp1.length()-1)
		{
			if(a[inp0[pos] - 'a'][0] != -1 && a[inp1[pos] - 'a'][1] != -1)
			{
				if(a[inp2[pos] - 'a'][2] == (a[inp0[pos] - 'a'][0] + a[inp1[pos] - 'a'][1] + carry)%10)
					return true;
				else
					return false;
			}
			else
			{
				if(a[inp2[pos] - 'a'][2] == (max(a[inp0[pos] - 'a'][0], a[inp1[pos] - 'a'][1]) + carry)%10)
					return true;
				else
					return false;
			}
		}	
		else if(pos > inp0.length()-1 && pos <= inp1.length()-1)
		{
			if(a[inp2[pos] - 'a'][2] == (a[inp1[pos] - 'a'][1] + carry)%10)
				return true;
			else
				return false;
		}
		else if(pos <= inp0.length()-1 && pos > inp1.length()-1)
		{
			if(a[inp2[pos] - 'a'][2] == (a[inp0[pos] - 'a'][0] + carry)%10)
				return true;
			else
				return false;
		}
		else if(pos > inp0.length()-1 && pos > inp1.length()-1)
		{
			if(a[inp2[pos] - 'a'][2] == carry)
				return true;
			else
				return false;
		}
	}
	else
	{
		if(pos <= inp0.length()-1 && pos <= inp1.length()-1)
		{
			if(a[inp0[pos] - 'a'][0] != -1 && a[inp1[pos] - 'a'][1] != -1)
			{
				if(a[inp2[pos] - 'a'][2] == (a[inp0[pos] - 'a'][0] + a[inp1[pos] - 'a'][1] + carry)%10)
					return true;
				else
					return false;
			}
			else if(a[inp0[pos] - 'a'][0] == -1 && a[inp1[pos] - 'a'][1] == -1)
			{
				if(a[inp2[pos] - 'a'][2] == carry)
					return true;
				else
					return false;
			}
			else
			{
				if(a[inp2[pos] - 'a'][2] == (max(a[inp0[pos] - 'a'][0], a[inp1[pos] - 'a'][1]) + carry)%10)
					return true;
				else
					return false;
			}
		}
		else if(pos > inp0.length()-1 && pos <= inp1.length()-1)
		{
			if(a[inp2[pos] - 'a'][2] == (a[inp1[pos] - 'a'][1] + carry)%10)
				return true;
			else
				return false;
		}
		else if(pos <= inp0.length()-1 && pos > inp1.length()-1)
		{
			if(a[inp2[pos] - 'a'][2] == (a[inp0[pos] - 'a'][0] + carry)%10)
				return true;
			else
				return false;
		}
		else if(pos > inp0.length()-1 && pos > inp1.length()-1)
		{
			if(a[inp2[pos] - 'a'][2] == carry)
				return true;
			else
				return false;
		}
	}	
}


void createmapping(int **a, string &inp0, string &inp1, string &inp2, int pos, int carry)
{
//	cout << "1a  "<<endl;
	if ( !( inp2.length() == max(inp0.length(), inp1.length()) ||  inp2.length() == max(inp0.length(), inp1.length()) + 1 ) )
	{
		cout << "No such combination exists\n";
		return ;
	}
	else
	{
//		cout <<"1b  "<<endl;
		if(pos != inp2.length() - 1)
		{
			if(!checkposition(a, inp0, inp1, inp2, pos, carry))
			{
//				cout <<"2a  "<<endl;
				resutingcharassignment(a, inp0, inp1, inp2, pos, carry);
				createmapping(a, inp0, inp1, inp2, pos, carry);
			}	
			else if(checkposition(a, inp0, inp1, inp2, pos, carry))
			{
//				cout<<"2b  "<<endl;
				createmapping(a, inp0, inp1, inp2, pos +1, carry);
			}	
		}
		else if(pos == inp2.length() - 1)
		{
			if(checkposition(a, inp0, inp1, inp2, pos, carry))
			{	
//				cout<<"3a  "<<endl;
				printmapping(a, inp0, inp1, inp2);
				pos = 0;
				reassigninp1(a, inp0, inp1, inp2, pos);
//				cout<<"3b  "<<endl;
				createmapping(a, inp0, inp1, inp2, pos, 0);
			}
			else
			{
//				cout<<"4a  "<<endl;
				resutingcharassignment(a, inp0, inp1, inp2, pos, carry);
			//	createmapping(a, inp0, inp1, inp2, pos, carry);
			}
		}	
	}	
}


int main()
{
	string inp1, inp2, inp0;
	cout << "Enter three strings :\n";
	cin >> inp0 >> inp1 >> inp2;
	cout << "To check whether the following combination is possible :\n";
	cout << inp0 << " + " << inp1 << " = " << inp2 << endl;

	int **a;
	a = new int*[26];
	for (int i = 0; i < 26; i++)
		a[i] = new int[3];
	for(int i = 0; i < 26; i++)
	{
		a[i][0] = -1;
		a[i][1] = -1;
		a[i][2] = -1;
	}

	reverse(inp0.begin(), inp0.end());
	reverse(inp1.begin(), inp1.end());
	reverse(inp2.begin(), inp2.end());	
//	cout << inp2 << endl;

	initialization(a, inp0, inp1, inp2);

	createmapping(a, inp0, inp1, inp2, 0, 0);
	cout << "Printing the map\n";
	printmapping(a, inp0, inp1, inp2);
}