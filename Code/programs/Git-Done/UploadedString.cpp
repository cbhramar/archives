#include <iostream>
#include <cmath>

using namespace std;

void scopy ( char destination[] , const char source[] , int start )
{
	int i;
	for ( i = 0; source[i] != '\0'; i++)
		destination[start + i] = source[i];
	destination[start + i] = source[i];
}


int length ( const char source[] )
{
	int l = 0;
	for ( int i = 0; source[i] != '\0'; i++ ) l++;
	return l;
}


class String 
{
public :
	char * ptr;

	String() // Default construcor
	{
		ptr = NULL;
	}


	String(const char* given) // Another constructor
	{
		ptr = new char[length(given)+1];
		scopy(ptr,given,0);
	}

	String( const String & source ) // Copy constructor
	{
		ptr = new char[ length(source.ptr) + 1 ];
		scopy ( ptr, source.ptr, 0 );
	}

	String & operator = ( const char * rhs ) // Assigning = in b/w String and char array
	{
		delete [] ptr;
		ptr = new char[ length(rhs) + 1 ];
		scopy ( ptr, rhs  , 0 );
		return * this;
	}

	String & operator = ( const String & rhs ) // Assigning = b/w String and String 
	{	
		if ( this == &rhs ) return * this;
		else
		{
			delete [] ptr;
			ptr = new char[ length(rhs.ptr) + 1 ];
			scopy ( ptr, rhs.ptr , 0 );
			return * this;
		}
	}

	String operator + ( const String & rhs ) // Adding two Strings
	{
		String res;
		res.ptr = new char[ length(ptr) + length(rhs.ptr) +1 ];
		scopy ( res.ptr, ptr, 0);
		scopy ( res.ptr, rhs.ptr, length(ptr));
		res.ptr[length(ptr) + length(rhs.ptr)] = rhs.ptr[length(rhs.ptr)];
		return res;
	}

	String operator+(const char* rhs) // Adding a String and a char array					
	{
		String res;
		res.ptr=new char[length(ptr) + length(rhs)+1];
		scopy(res.ptr, ptr, 0);
		scopy(res.ptr, rhs, length(ptr));
		return res;
	}	

	char & operator [] ( int i ) const
	{
		return ptr[i];	
	}

	void print() // Printing a String
	{
		if ( ptr != NULL ) cout << ptr << endl;
		else cout << "NULL \n";
	}

	int size()
	{
		return length(ptr);
	}

	~String() // Destructor
	{
		delete [] ptr;
	}
};


String lcase( const String & arg ) // extra fuction , as given in An Introduction to Programming by A.Ranade
{
	String res = arg;
	for ( int i = 0; i<length(res.ptr); i++)
			if( res[i] >= 'A' && res[i] <= 'Z' ) res[i] += 'a' - 'A';
	return res;
}


struct  node
{
	String s;
	node *next;
	node()
	{
		next = NULL;
	}
};


void firstString(node *root)
{
	char ch[50];
	cin >> ch;
	root->s = ch;
	root->next = NULL;
}


void list(node *root, node *current, int n)
{
    current = root;
    for ( int i=0; i<n-1 ; i++)
    {
        current->next = new node;
        current = current->next;
        cout << "Enter String :\n";
    	char ch[50];
		cin >> ch;
		current->s = ch;    
    }
    current->next=NULL;
}


void printlist(node *root, node *current)
{
    current = root;
    while ( current->next != NULL)
    {
        (current->s).print();
        current = current->next;
    }
    (current->s).print();
}


bool lessrank(const String & lhs, const String & rhs)
{
	int minlen = min(length(lhs.ptr), length(rhs.ptr));

	for(int i = 0; i < minlen; i++)
	{
		if(lcase(lhs).ptr[i] < lcase(rhs).ptr[i])
			return true;
		else if(lcase(lhs).ptr[i] > lcase(rhs).ptr[i])
			return false;
	}

	if(length(lhs.ptr) <= length(rhs.ptr))
		return true;
	else
		return false;
}


void insertionsort(node **root_ref, node *newnode)
{
	node* current = *root_ref;
	if (current == NULL || lessrank(newnode->s, current->s)) 
	{
		newnode->next = *root_ref;
		*root_ref = newnode;
	}
	else
	{
		while(current->next != NULL && lessrank(current->next->s, newnode->s))
			current = current->next;
		newnode->next = current->next;
		current->next = newnode;
	}
}


void dictionaryorder(node **root_ref)
{
	node *sortedlist = NULL;
    node *current = *root_ref;
    if (current == NULL || current->next == NULL)	return;
    while ( current != NULL)
    {
    	node *next = current->next;
    	insertionsort(&sortedlist, current);
    	current = next;
    }
    *root_ref = sortedlist;
}


int main()
{
	String a;
	cout << "Default constructor :\n";
	a.print();
	char ch[] = "AbcD";
	a = ch;
	cout << "Assigning character array to a :\n";
	a.print();
	cout << "Using Another constructor :\n";
	String e("xyZ");
	e.print();
	String b(a);
	cout << "Copy constructor :\n";
	b.print();
	String c;
	c = a;
	cout << "Assigning String to a String :\n";
	c.print();
	cout << "Accesing the third element of String c :\n";
	cout << c[2] << endl;
	cout << "Testing lcase function :\n";
	lcase(c).print();	
	String d;
	d = a +b;
	cout << "Assigning d = a + b :\n";
	d.print();
	cout << "Assigning f = e + PQR ( String = String + char array) :\n ";
	String f;
	f = e + "PQR";
	f.print();

	// sorting

	cout << "Insert no. of Strings you want to enter : \n";
	int n;
	cin >> n;
	node *root;
    root = new node;
    node *current;
    cout << "Enter String :\n";
    firstString(root);
    list(root, current, n);
    cout << endl;
    cout << endl;
    cout << "Printing entered list : \n";
    printlist(root, current);
    cout << endl;
    cout << endl;
    cout << "Printing in dictionary order : \n";
    dictionaryorder(&root);
    printlist(root, current);
    cout << endl;
    cout << endl;
 }