#include<iostream>
using namespace std;
class String
{
	char *ptr;
	public:
	String()
	{
		ptr=new char[20];
	}
	String(const char *p)
	{
		int i;
		for(i=0;p[i];i++);
		ptr = new char[i+1];
		for(int j=0;j<i;j++)
			ptr[j] = p[j];
	}
	String(const String &temp)
	{
		int i;
		for(i=0;temp.ptr[i];i++);
		ptr=new char[i+1];
		for(int j=0;j<i;j++)
			ptr[j]=temp.ptr[j];
	}

	~String()
	{
		delete []ptr;
	}

	int length();
	void set_data();
	void get_data();
	char & operator[](int);
	String operator+(String );
	bool operator==(String );
	bool operator!=(String );
	bool operator>(String );
	bool operator>=(String );
	bool operator<(String );
	bool operator<=(String );
	String operator=(String );
	friend void str_cpy(String &,String &);
	friend void str_ncpy(String &,String &,int);
	friend void str_lower(String &);
	friend void str_upper(String &);
	friend int str_cmp(const String ,const String );
	friend String str_cat(String ,String );
	friend String str_ncat(String ,String ,int );
	friend char str_chr(const String ,char );
	friend char str_rchr(const String ,char );
	friend int str_len(String );
	friend String str_rev(String );
};


int String::length()
{
	int i=0;
	for(i=0;ptr[i];i++);
	return i;
}	
void String::set_data()
{
	int i;
	cout<<"enter the string"<<endl;
	cin>>ptr;
}
void String::get_data()
{
	cout<<"string="<<ptr<<endl;
}


/////////////////////////////operator overloading //////////////////////////


char & String::operator[](int index)
{
	return ptr[index];
}
String String::operator+(String obj)
{
	cout << "Overloaded + "<<endl;
	int i,j,k;
	i = this -> length();
	j = obj.length();
	String res;
	res.ptr = new char [i+j+1];
	for( k=0;k<i;k++)
	{
		res.ptr[k] = ptr[k];
	}
	for(int c=0;c<j;k++,c++)
	{
		res.ptr[k] = obj.ptr[c];
	}
	return res;
}
bool String::operator==(String obj)
{
	cout << "Overloaded == "<<endl;
	int i,j;
	i = this -> length();
	j = obj.length();
	if (i != j )
		return 0;
	else
	{
		for(i=0;i<j;i++){
			if(ptr[i] != obj.ptr[i])
				break;
		}
		if(i == j)
			return 1;
		else
			return 0;
	}
}
bool String::operator!=(String obj)
{
	cout << "Overloaded != "<<endl;
	int i,j;
	i = this -> length();
	j = obj.length();
	if (i != j )
		return 1;
	else
	{
		for(i=0;i<j;i++)
		{
			if(ptr[i] != obj.ptr[i])
				return 1;
		}
		if(i == j)
			return 0;
	}
}
bool String::operator>(String obj)
{
	cout << "Overloaded > "<<endl;
	int i,j;
	i = this -> length();
	j = obj.length();
	for(i=0;i<j;i++)
	{
		if(ptr[i] > obj.ptr[i])
			return 1;
		else
		{
			if(ptr[i] < obj.ptr[i])
				return 0;
		}
	}
	return 0;
}

bool String::operator>=(String obj)
{
	cout << "Overloaded >= "<<endl;
	int i,j;
	i = this -> length();
	j = obj.length();
	for(i=0;i<j;i++)
	{
		if(ptr[i] > obj.ptr[i])
			return 1;
		else
		{
			if(ptr[i] < obj.ptr[i])
				return 0;
		}
	}
	if(i==j)
		return 1;
	return 0;
}


bool String::operator<(String obj)
{
	cout << "Overloaded < "<<endl;
	int i,j;
	i = this -> length();
	j = obj.length();
	for(i=0;i<j;i++)
	{
		if(ptr[i] < obj.ptr[i])
			return 1;
		else
		{
			if(ptr[i] > obj.ptr[i])
				return 0;
		}
	}
	return 0;
}

bool String::operator<=(String obj)
{
	cout << "Overloaded <= "<<endl;
	int i,j;
	i = this -> length();
	j = obj.length();
	for(i=0;i<j;i++)
	{
		if(ptr[i] < obj.ptr[i])
			return 1;
		else
		{
			if(ptr[i] > obj.ptr[i])
				return 0;
		}
	}
	if(i==j)
		return 1;
	return 0;
}

String String::operator=(String obj)
{
	cout << "overloaded = " << endl;
	int k=obj.length();
	ptr = new char[k+1];
	for(int i=0;i<k;i++)
	{
		ptr[i] = obj.ptr[i];
	}
	return *this;
}	

////////////////////////////// operators overloading /////////////

/////////////////////////////   string functions      ////////////

void str_cpy(String &s1,String &s2)
{
	int i;
	for(i=0;s2.ptr[i];i++)
		s1.ptr[i]=s2.ptr[i];
}
void str_ncpy(String &s1,String &s2,int n)
{
	int i;
	for(i=0;i<n;i++)
		s1.ptr[i]=s2.ptr[i];
}
void str_lower(String &s)
{
	int i;
	for(i=0;s.ptr[i];i++)
	{
		if(s.ptr[i]>='A'&&s.ptr[i]<='Z')
			s.ptr[i]+=32;
	}
}
void str_upper(String &s)
{
	int i;
	for(i=0;s.ptr[i];i++)
	{
		if(s.ptr[i]>='a'&&s.ptr[i]<='z')
			s.ptr[i]-=32;
	}
}
int str_cmp(String s1,String s2)
{
	int i,j;
	i=s1.length();
	j=s2.length();
	if(i>j)
		return 2;
	else if(i<j)
		return 2;
	for(i=0;s1.ptr[i];i++)
	{
		if(s1.ptr[i]!=s2.ptr[i])
			break;
	}
	if(s1.ptr[i]==s2.ptr[i])
		return 0;
	else if(s1.ptr[i]>s2.ptr[i])
		return 1;
	else if(s1.ptr[i]<s2.ptr[i])
		return -1;
}
void str_cmpdata(int r)
{
	if(r==0)
		cout<<"string are equal"<<endl;
	else if(r==1)
		cout<<"strinf 1 is greater than string 2"<<endl;
	else if(r==-1)
		cout<<"string 1 is lesser than string2"<<endl;
	else
		cout<<"strings are not equal"<<endl;
}
String str_cat(String s1,String s2)
{
	int i,j,l,k,c;
	l=s1.length();
	k=s2.length();
	for(i=0;i<l;i++);
	for(c=0;c<k;i++,c++)
		s1.ptr[i]=s2.ptr[c];
	return s1;
}
String str_ncat(String s1,String s2,int n)
{
	int i,j,l,k,c;
	l=s1.length();
	k=s2.length();
	for(i=0;i<l;i++);
	for(c=0;c<n;i++,c++)
		s1.ptr[i]=s2.ptr[c];
	return s1;
}
char str_chr(const String s,char ch)
{
	int i;
	for(i=0;s.ptr[i];i++)
	{
		if(s.ptr[i]==ch)
			return i+1+48;
	}
}
char str_rchr(String s,char ch)
{
	int i,l;
	l=s.length();
	for(i=l-1;i>=0;i--)
	{
		if(s.ptr[i]==ch)
			return i+1+48;
	}
}
int str_len(String s)
{
	int i;
	for(i=0;s.ptr[i];i++);
	return i;
}
String str_rev(String s)
{
	int i,j,l;
	char ch;
	l=s.length();
	for(i=0,j=l-1;i<j;i++,j--)
	{
		ch=s.ptr[i];
		s.ptr[i]=s.ptr[j];
		s.ptr[j]=ch;
	}
	return s;
}
main()
{	
	String s1,s2,s3,s4;
	int op,i,n,r;
	bool ret;
	char ch,id;
	cout<<"enter the option"<<endl;
	cout<<" 1. Operator overloading"<<endl;	
	cout<<" 2. String functions"<<endl;	
	cout<<" 3. My_string data type"<<endl;	
	cin>>op;
	switch(op)
	{
		case 1:	cout<<"operator overloading"<<endl;
			cout<<"enter the option for"<<endl;
			cout<<" 1. []operator"<<endl;
			cout<<" 2. + operator"<<endl;
			cout<<" 3. ==operator"<<endl;
			cout<<" 4. !=operator"<<endl;
			cout<<" 5. > operator"<<endl;
			cout<<" 6. >=operator"<<endl;
			cout<<" 7. < operator"<<endl;
			cout<<" 8. <=operator"<<endl;
			cout<<" 9. = operator"<<endl;
			cin>>op;
			switch(op)
			{
				case 1:	cout<<"enter the no. of char"<<endl;
					cin>>n;
					for(i=0;i<n;i++)
						cin>>s1[i];
					for(i=0;i<n;i++)
						cout<<s1[i]<<" ";
					break;
				case 2: s1.set_data();
					s2.set_data();
					s4=s1+s2;
					s4.get_data();
					break;
				case 3: s1.set_data();
					s2.set_data();
					ret=s1==s2;
					cout<<boolalpha<<ret<<endl;
					break;
				case 4:	s1.set_data();
					s2.set_data();
					ret=s1!=s2;
					cout<<boolalpha<<ret<<endl;
					break;
				case 5: s1.set_data();
					s2.set_data();
					ret=s1>s2;
					cout<<boolalpha<<ret<<endl;
					break;
				case 6: s1.set_data();
					s2.set_data();
					ret=s1>=s2;
					cout<<boolalpha<<ret<<endl;
					break;
				case 7: s1.set_data();
					s2.set_data();
					ret=s1<s2;
					cout<<boolalpha<<ret<<endl;
					break;
				case 8: s1.set_data();
					s2.set_data();
					ret=s1<=s2;
					cout<<boolalpha<<ret<<endl;
					break;
				case 9: s1.set_data();
					s2.set_data();
					s1=s2;
					s1.get_data();
					break;
			}
			break;
		case 2: cout<<"string functions"<<endl;
			cout<<"enter the option for"<<endl;
			cout<<"1. strcpy"<<endl;
			cout<<"2. strncpy"<<endl;
			cout<<"3. strlower"<<endl;
			cout<<"4. strupper"<<endl;
			cout<<"5. strcmp"<<endl;
			cout<<"6. strcat"<<endl;
			cout<<"7. strncat"<<endl;
			cout<<"8. strchr"<<endl;
			cout<<"9. strrchr"<<endl;
			cout<<"10.strlen"<<endl;
			cout<<"11.strrev"<<endl;
			cin>>op;
			switch(op)
			{
				case 1: s1.set_data();
					s2.set_data();
					str_cpy(s1,s2);
					s1.set_data();
					break;
				case 2: s1.set_data();
					s2.set_data();
					cout<<"enter the n"<<endl;
					cin>>n;
					str_ncpy(s1,s2,n);	
					s1.get_data();
					break;
				case 3: s1.set_data();
					str_lower(s1);
					s1.get_data();
					break;
				case 4: s1.set_data();
					str_upper(s1);
					s1.get_data();
					break;
				case 5: s1.set_data();
					s2.get_data();
					r=str_cmp(s1,s2);
					str_cmpdata(r);
					break;
				case 6: s1.set_data();
					s2.set_data();
					s3=str_cat(s1,s2);
					s3.get_data();
					break;
				case 7: s1.set_data();
					s2.set_data();
					cout<<"enter n"<<endl;
					cin>>n;
					s3=str_ncat(s1,s2,n);
					s3.get_data();
					break;
				case 8: s1.set_data();
					cout<<"enter the char"<<endl;
					cin>>ch;
					id=str_chr(s1,ch);
					cout<<id<<endl;		
					break;
				case 9: s1.set_data();
					cout<<"enter the char"<<endl;
					cin>>ch;
					id=str_rchr(s1,ch);
					cout<<id<<endl;		
					break;
				case 10:s1.set_data();
					r=str_len(s1);
					cout<<r<<endl;
					break;
				case 11:s1.set_data();		
					s3=str_rev(s1);
					s3.get_data();		
					break;
			}
			break;
		case 3: cout<<"my string data type"<<endl;
			String s6("acegu"),s5(s6);
			s6.get_data();
			s5.get_data();

			String s7 = "gang";
			s7.get_data();
	}
}
