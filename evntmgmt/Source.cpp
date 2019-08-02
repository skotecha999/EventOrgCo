#include"head.h"



void type(string str)
{
	/*int n;
	if (str.length() > 40)
		n = 25;
	else
		n = 40;*/
	for (int i = 0; i < str.length(); i++)
	{
		Sleep(1);
		cout << str[i];
	}
	cout << endl;
}
void clrscr()
{
	system("CLS");
	cout << "EVENT MANAGEMENT\n\n";
}
string genspace(int a)
{
	string b = "";
	for (; a >= 1; a--)
		b += " ";
	return b;
}
void rollback()
{
	movef(evfile, oevfile);
	movef(atfile, oatfile);
	movef(spfile, ospfile);
	movef(vefile, ovefile);
	movef(adfile, oadfile);
	movef(emfile, oemfile);
	movef(clfile, oclfile);
}
void commit()
{
	movef(oevfile, evfile);
	movef(oatfile, atfile);
	movef(ospfile, spfile);
	movef(ovefile, vefile);
	movef(oadfile, adfile);
	movef(oemfile, emfile);
	movef(oclfile, clfile);

}
void writeto(string fname, string data)
{
	ofstream f(fname, ios::app);
	//f.open(fname, ios::app);
	//cout << "write to\n";
	//f << data;
	//cout <<endl<< f.tellp()<<endl;
	f << data;
	//f << EOF;
	//cout << f.tellp() << endl;
	f.close();
}
void movef(string dest, string src)
{
	ifstream f1; 
	ofstream f2; 
	f1.open(src);
	if (f1.eof())
	{
		//cout << "empty" << src << endl;
		ofstream ofs;
		ofs.open(dest, std::ofstream::out | std::ofstream::trunc);
		ofs.close();
		return;
	}
	f2.open(dest);
	if (!f1 || !f2)
		return;
	string ch;
	while (f1.eof() == 0)
	{
		getline(f1, ch, '\n');
		if (ch.length() < 4)
			break;
		f2 << ch << endl;
	}
	f1.close();
	f2.close();
}
int nextIndex(string str, int recsize)
{
	fstream f1;
	f1.open(str, ios::in | ios::app);
	f1.seekg(0, ios::end);
	int int_id = 0;
	
		//cout << f1.tellg()<<endl;   //test
		if (f1.tellg())
		{
			int pos = f1.tellg();
			f1.seekg(pos-recsize);
			//cout << pos<<"\t"<<f1.tellg() << endl;
			// find the last index 
			char temp[5];
			//f1.read(temp, 5);
			//cout << temp;
			
			f1.read(temp, 5);

			//cout << temp << endl;   //test
			int_id = atoi(temp);
			//cout << int_id << endl;   //test
			
			//increment it and store it in int_id
			int_id++;

		}f1.close();
		return int_id;


}
string trim(const string& str)
{
	size_t first = str.find_first_not_of(' ');
	if (string::npos == first)
	{
		return str;
	}
	size_t last = str.find_last_not_of(' ');
	return str.substr(first, (last - first + 1));
}
vector<string> split(string s, string delimiter) {
	size_t pos_start = 0, pos_end, delim_len = delimiter.length();
	string token;
	vector<string> res;

	while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
		token = s.substr(pos_start, pos_end - pos_start);
		pos_start = pos_end + delim_len;
		res.push_back(token);
	}

	res.push_back(s.substr(pos_start));
	return res;
}
int search_rec(string id, string fname)
{
	//cout << "|" << id << "|" << endl<<id.length()<<endl;
	fstream f;
	int ind;
	string temp, trunc;
	f.open(fname, ios::in);
	while (!f.eof())
	{
		
		getline(f, temp, '|');
		ind = f.tellg();
		temp = trim(temp);
		
		getline(f, trunc, '\n');
		if (temp.compare(id) == 0)
		{
			f.close();
			return ind;
		}

	}
	return -1;
}
void add_offset_rec(string fname, string e_id, string buff)
{
	//read first line
	//find offset line
	// curr =  offset
	// insert line at curr without replacement using insert_line() 
	// update first line, if index>curr index ++
	// replace first line using insert_line()





	// open file, read first line
	fstream f;
	f.open(fname, ios::in|ios::out);
	string l,temp;
	int curr=1,i;
	getline(f, l, '\n');
	vector<string> v = split(l, "|");
	vector<string> e;

	for (i=0; i<v.size()-1; i++)								
	{
		e = split(v[i], ":");
	
		if (e[0].compare(e_id) == 0)
		{
			curr = stoi(e[1]);		
			break;	

		}
	}
	f.close();

	

	if (i == v.size() - 1)
	{
		
		if (i == 0)
		{
			//curr = 2;
			l = e_id + ":" + "2" + "|";
			//f.open(fname, ios::in);
			/*while (!f.eof())
			{
				getline(f, temp, '\n');
				cout << temp << "\t" << curr << "test\n";
				if (temp.compare("\n")!=0)
				curr++;
				cout << temp << "\t" << curr << "test1\n";
			}*/
		}
		
		if (i > 0)
		{
			i--;
			e = split(v[i], ":");
			curr = stoi(e[1]);
			
			l = l + e_id + ":" + to_string(curr) + "|";
			//curr = stoi(e[1]);
		}
	}

	
	
	
	//cout << "curr=" << curr << endl;  //test
	
	v = split(l, "|");
	l = "";
	for (int i = 0; i < v.size()-1; i++)
	{
		vector<string> e = split(v[i], ":");
		int t = stoi(e[1]);
		//cout << e[0] << "--" << e[1] << "?" << t<<"\t"<< (t < curr) <<endl;
		if ((t > curr)&&(e[0].compare(e_id)!=0))
		{
			t++;
			e[1] = to_string(t);
		}
		if (e[0].compare(e_id) == 0)
			e[1]=to_string(1+curr);
		l = l+ e[0] +":"+ e[1] + "|";
		//cout << l << endl;
		
	}

	insert_line(fname, l, 0, 1);
	insert_line(fname, buff, curr, 0);

	
}
void insert_line(string fname, string buff, int pos, int x = 0)
{
	//buff -  line to be written 
	// pos- line number where to write the buff
	//x- 0= simple insert(default)  1= replace line at position
	fstream f, f1, f2;
	f.open(fname, ios::in | ios::out);
	f1.open(temp1, ios::out);
	f2.open(temp2, ios::out);

	string temp;
	int  t, i;

	//cout << "-" << f.tellg() << endl;  //test

	for (i = 0; i < pos; i++)
	{
		//cout <<"--"<< f.tellg() << endl;  //test
		getline(f, temp, '\n');
		if (temp.length() < 3)
			continue;
		f2 << temp << endl;

		//cout << temp << "  skipped\n";
	}

	t = f.tellg();
	//cout << t << endl;

	if (x == 1)
		getline(f, temp, '\n');

	while (!f.eof())
	{
		getline(f, temp, '\n');
		if (temp.length() < 3)
			continue;
		f1 << temp << endl;
		//cout << temp << "  copied\n";
	}


	f.seekp(t);
	/*if (!f.tellg == f.tellp)
	{
		cout << "error";
		return;
	}*/
	//cout << f.tellp() << endl;
	f << buff << endl;
	//cout << buff << " user string\n";
	f2 << buff << endl;


	f1.close();
	//cout << "3\n";
	f1.open(temp1, ios::in);
	while (!f1.eof())
	{

		getline(f1, temp, '\n');
		if (temp.length() < 3)
			continue;
		f << temp << endl;
		//cout << temp << "  restored\n";
		f2 << temp << endl;
	}
	//cout << "4\n";
	f.close();
	f1.close();
	f2.close();
	movef(fname, temp2);

	// either enter a new line or replace a line
	//// for simple insert
		//go to pos
		//copy from pos to end, into temp
		//write buff to pos
		//copy temp back into file
	////to rplace line
		//goto pos
		//copy from pos+1 to end
		//write buff to pos
		//copy temp back into file
}
void display(string fname, string e_id)
{
	ifstream f;
	f.open(fname);
	string temp;
	int i, loc, n;
	getline(f, temp, '\n');
	if (temp.length() <4)
		return;
	vector<string> v, e;
	v = split(temp, "|");
	
	for (i = 0; i < v.size(); i++)
	{
		if (v[i].length() > 3);
		{
			e = split(v[i], ":");

			if (e[0] == e_id)
				break;
		}
	}
	
	if (e_id.compare("-1") == 0)
	{
		e = split(v[i - 2], ":");
		n = stoi(e[1]);
		
		loc = 1;
		goto print;
	}
	if (i == v.size())
	{
		cout << "No sponsor information found for specified event\n";
		return;
	}
	n = stoi(e[1]);
	
	
	if (i == 0)
		loc = 1;
	else
	{
		e = split(v[i - 1], ":");
		loc = stoi(e[1]);

	}
	n = n - loc;
	//cout << "Test -  loc " << loc << "\t no. of lines  " << n << endl;
	//cout << f.tellg() << endl;
print://f.seekg(((loc-1) * recsize), ios::cur);
	//cout << f.tellg() << endl;
	
	for(i=1;i<loc;i++)
		getline(f, temp, '\n');
	for (i = 1; i <= n; i++)
	{
		getline(f, temp, '\n');
		//cout << temp << endl;
		v = split(temp, "|");
		for (int j = 1; j < v.size(); j++)
		{
			cout << v[j]<< " ";
		}
		cout << endl;
	}
	f.close();
}


int add(string fname, string e_id, int rec)
{

	ifstream f;
	f.open(fname);
	string temp;
	vector<string> v, e;
	int i, loc, n, sum=0;
	if (fname.compare(emfile) == 0)
	{
		
		while (!f.eof())
		{
			getline(f, temp, '\n');
			//cout << endl<<temp<<endl;
			//cout << temp.length() << endl;
			if (temp.length() < 100)
			{
				break;
			}
				v = split(temp, "|");
				//cout << "eid\t" << e_id << "\t\tv[5]\t" << v[5] << endl;
				if (e_id.compare(trim(v[5])) == 0)
					sum += stoi(v[4]);
				//cout << sum << endl;
			
		}
		return sum;
	}


	getline(f, temp, '\n');
	//cout << endl << temp << endl;
	//cout << temp.length() << endl;
	if (temp.length() < 4)
		return 0;
	
	v = split(temp, "|");

	for (i = 0; i < v.size(); i++)
	{
		if (v[i].length() > 3);
		{
			//cout << v[i];
			//cout << endl << i << endl;
			e = split(v[i], ":");

			if (e[0] == e_id)
				break;
		}
	}


	if (i == v.size())
	{
		
		return 0;
	}
	n = stoi(e[1]);


	if (i == 0)
		loc = 1;
	else
	{
		e = split(v[i - 1], ":");
		loc = stoi(e[1]);

	}
	n = n - loc;
	if (fname.compare(atfile) == 0)
		return n;

	for (i = 1; i < loc; i++)
		getline(f, temp, '\n');
	//cout << n << endl;
	for (i = 1; i <=n; i++)
	{
		getline(f, temp, '\n');
		//cout << temp << endl;
		sum += stoi(getFeild(temp));
		//cout << sum << endl;
		//cout << endl<<temp<<endl;
		//cout << temp.length() << endl;
		
	}
	f.close();
	return sum;
}
	


string getFeild(string str, int f)
{
	//f=0 for last feild;
	//cout << str << endl;
	//f--;
	//cout << f << endl;
	vector<string> v = split(str, "|");
	//cout << str << endl;
	if (f == 0)
		f = v.size();
	//cout << v[f - 1];
	return (v[f - 1]);
}