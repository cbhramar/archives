#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

// my code treats uppercase and lowercase characters differently; please input only lowercase characters


void merge(int **a, string inp0, string inp1, string inp2)
{
	for (int i = 0; i < 26; i++)
	{
		if(a[i][0] != -1)
		{
			a[i][1] = a[i][0];
			a[i][2] = a[i][0];
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if(a[i][1] != -1)
		{
			a[i][0] = a[i][1];
			a[i][2] = a[i][1];
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if(a[i][2] != -1)
		{
			a[i][0] = a[i][2];
			a[i][1] = a[i][2];
		}
	}
}


void printmapping(int **a, string inp0, string inp1, string inp2)
{
	merge(a, inp0, inp1, inp2);
	for(int i = 0; i < 26; i++)
	{
		if(a[i][0] != -1)
		{
			char alphabet = 'a' + i;
			cout << alphabet << '=' << a[i][0] <<", ";
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


int currentvalue(int **a, string &source, int pos)
{
	for(int j = 0; j < 9; j++)
	{
		if( a[source[pos] - 'a'][1] == j)
			return j;
		else 
			return 9;
	}	
} 


void reassigninp(int **a, string &inp0, string &inp1, string &inp2, int pos)
{
	if(pos < inp1.length())
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
			if(pos < inp0.length())
			{
				if(a[inp0[pos] - 'a'][0] != 9)
				{
					a[inp0[pos] - 'a'][0] = currentvalue(a, inp0, pos) + 1;
					if(a[inp0[pos] - 'a'][0] == a[inp0[pos] - 'a'][1] + 1)
						a[inp0[pos] - 'a'][1] = a[inp0[pos] - 'a'][0];
					if(a[inp0[pos] - 'a'][0] == a[inp0[pos] - 'a'][2] + 1)
						a[inp0[pos] - 'a'][2] = a[inp0[pos] - 'a'][0];
				}
				else
				{
					return;
				}
			}
			else
			{
				return;
			}
		}
	}
	else
	{
		return;
	}	
}


bool checkposition(int **a, string &inp0, string &inp1, string &inp2, int pos, int carry)//needs work
{
	int l0 = inp0.length();
	int l1 = inp1.length();
	int l2 = inp2.length();
	if(pos < l0 && pos < l1)
	{
		if(a[inp0[pos] - 'a'][0] != -1 && a[inp1[pos] - 'a'][1] == -1)
		{
			if(a[inp2[pos] - 'a'][2] == (a[inp0[pos] - 'a'][0] + carry)%10)
				return true;
			else 
				return false;
		}
		else if(a[inp0[pos] - 'a'][0] == -1 && a[inp1[pos] - 'a'][1] != -1)
		{
			if(a[inp2[pos] - 'a'][2] == (a[inp1[pos] - 'a'][1] + carry)%10)
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
		else if(a[inp0[pos] - 'a'][0] != -1 && a[inp1[pos] - 'a'][1] != -1)
		{
			if(a[inp2[pos] - 'a'][2] == (a[inp0[pos] - 'a'][0] + a[inp1[pos] - 'a'][1] + carry)%10)
				return true;
			else 
				return false;
		}				
	}
	else if(pos < l0 && pos >= l1)
	{
		if(a[inp0[pos] - 'a'][0] != -1)
		{
			if(a[inp2[pos] - 'a'][2] == (a[inp0[pos] - 'a'][0] + carry)%10)
				return true;
			else 
				return false;
		}
		else
		{
			if(a[inp2[pos] - 'a'][2] == carry)
				return true;
			else 
				return false;
		}
	}
	else if(pos >= l0 && pos < l1)
	{
		if(a[inp1[pos] - 'a'][1] != -1)
		{
			if(a[inp2[pos] - 'a'][2] == (a[inp1[pos] - 'a'][1] + carry)%10)
				return true;
			else 
				return false;
		}
		else
		{
			if(a[inp2[pos] - 'a'][2] == carry)
				return true;
			else 
				return false;
		}
	}
	else 
	{
		if(a[inp2[pos] - 'a'][2] == carry)
			return true;
		else 
			return false;
	}		
}


void resutingcharassignment(int **a, string &inp0, string &inp1, string &inp2, int pos, int carry)
{
	int l0 = inp0.length();
	int l1 = inp1.length();
	int l2 = inp2.length();
	if(pos < l0 && pos < l1)
	{
		if(a[inp0[pos] - 'a'][0] != -1 && a[inp1[pos] - 'a'][1] == -1)
		{
			a[inp2[pos] - 'a'][2] = (a[inp0[pos] - 'a'][0] + carry)%10;
			carry = (a[inp0[pos] - 'a'][0] + carry)/10;
		}
		else if(a[inp0[pos] - 'a'][0] == -1 && a[inp1[pos] - 'a'][1] != -1)
		{
			a[inp2[pos] - 'a'][2] = (a[inp1[pos] - 'a'][1] + carry)%10;
			carry = (a[inp1[pos] - 'a'][1] + carry)/10;
		}	
		else if(a[inp0[pos] - 'a'][0] == -1 && a[inp1[pos] - 'a'][1] == -1)
		{
			a[inp2[pos] - 'a'][2] = carry;
			carry = 0;
		}
		else if(a[inp0[pos] - 'a'][0] != -1 && a[inp1[pos] - 'a'][1] != -1)
		{
			a[inp2[pos] - 'a'][2] = (a[inp0[pos] - 'a'][0] + a[inp1[pos] - 'a'][1] + carry)%10;
			carry = (a[inp0[pos] - 'a'][0] + a[inp1[pos] - 'a'][1] + carry)/10;
		}
	}	
	else if(pos < l0 && pos >= l1)
	{
		if(a[inp0[pos] - 'a'][0] != -1)
		{
			a[inp2[pos] - 'a'][2] = (a[inp0[pos] - 'a'][0] + carry)%10;
			carry = (a[inp0[pos] - 'a'][0] + carry)/10;
		}
		else
		{
			a[inp2[pos] - 'a'][2] == carry;
			carry = 0;
		}
	}
	else if(pos >= l0 && pos < l1)
	{
		if(a[inp1[pos] - 'a'][1] != -1)
		{
			a[inp2[pos] - 'a'][2] = (a[inp1[pos] - 'a'][1] + carry)%10;
			carry = (a[inp1[pos] - 'a'][1] + carry)/10;
		}
		else
		{
			a[inp2[pos] - 'a'][2] = carry;
			carry = 0;
		}
	}
	else 
	{
		a[inp2[pos] - 'a'][2] = carry;
		carry = 0;
	}


	if(a[inp2[pos] - 'a'][0] != -1 && a[inp2[pos] - 'a'][0] != a[inp2[pos] - 'a'][2]) 
		a[inp2[pos] - 'a'][0] = a[inp2[pos] - 'a'][2];
	if(a[inp2[pos] - 'a'][1] != -1 && a[inp2[pos] - 'a'][1] != a[inp2[pos] - 'a'][2]) 
		a[inp2[pos] - 'a'][1] = a[inp2[pos] - 'a'][2];
}


void createmapping(int **a, string &inp0, string &inp1, string &inp2, int pos, int carry)
{
	if ( !( inp2.length() == max(inp0.length(), inp1.length()) ||  inp2.length() == max(inp0.length(), inp1.length()) + 1 ) )
	{
		cout << "No such combination exists\n";
		return ;
	}
	else
	{
		cout <<"1a  ";
		if(pos != inp2.length() - 1)
		{
			if(!checkposition(a, inp0, inp1, inp2, pos, carry))
			{
				cout <<"2a  ";
				resutingcharassignment(a, inp0, inp1, inp2, pos, carry);
				createmapping(a, inp0, inp1, inp2, pos, carry);
			}	
			else 
			{
				cout<<"2b  ";
				createmapping(a, inp0, inp1, inp2, pos +1, carry);
			}	
		}
		else 
		{
			if(checkposition(a, inp0, inp1, inp2, pos, carry))
			{	
				cout << "2.3  \n";
				if(checkposition(a, inp0, inp1, inp2, pos, carry))
				{
					cout << "3a  ";
					printmapping(a, inp0, inp1, inp2);
					pos = 0;
					carry = 0;	
					reassigninp(a, inp0, inp1, inp2, pos);	
					if(checkposition(a, inp0, inp1, inp2, pos, carry))
					{
						createmapping(a, inp0, inp1, inp2, pos, carry);
					}
					else
					{
						resutingcharassignment(a, inp0, inp1, inp2, pos, carry);
						createmapping(a, inp0, inp1, inp2, pos, carry);
					}
				}
				else
				{
					cout << "3b  \n";
					resutingcharassignment(a, inp0, inp1, inp2, pos, carry);
					createmapping(a, inp0, inp1, inp2, pos, carry);
				}
/*				pos = 0;
				carry = 0;	
				reassigninp(a, inp0, inp1, inp2, pos);	
				if(checkposition(a, inp0, inp1, inp2, pos, carry))
				{
					cout << "3a  ";
					printmapping(a, inp0, inp1, inp2);
					reassigninp(a, inp0, inp1, inp2, pos);
					if(checkposition(a, inp0, inp1, inp2, pos, carry))
						createmapping(a, inp0, inp1, inp2, pos, carry);
					else
					{
						resutingcharassignment(a, inp0, inp1, inp2, pos, carry);
					    if(checkposition(a, inp0, inp1, inp2, pos, carry))
					    	printmapping(a, inp0, inp1, inp2);					
					}
				}
				else
				{
					cout << "3b  \n";
					resutingcharassignment(a, inp0, inp1, inp2, pos, carry);
					createmapping(a, inp0, inp1, inp2, pos, carry);
				}	*/	
			}
			else
			{
				cout<<"4a  "<<endl;
				resutingcharassignment(a, inp0, inp1, inp2, pos, carry);
	 			createmapping(a, inp0, inp1, inp2, pos, carry);
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
//	cout << "Printing the map\n";
//	printmapping(a, inp0, inp1, inp2);
}