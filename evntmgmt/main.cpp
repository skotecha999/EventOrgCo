#include"head.h"

class event
{
public:
	char name[20], location[20], date[12], id[5], duration[2], entryfee[3];
	const int recsize = 117;

	void addnew()  //works as expected except character length of each field is not constrained
	{
		cout << "\n Number of records to enter :";
		int n;
		cin >> n;
		cout << "Enter the details \nName\tLocation\tDate(dd-mm-yyyy)\tDuration(number of days)\tEntry Fee\n";

		// open file move to the end 
		//fstream f1;
		//f1.open(evfile, ios::in | ios::app);
		strcpy_s(id, "0");
		int int_id = nextIndex(evfile, recsize);
		cout << int_id;
		//int int_id = 0;
		for (; n >= 1; n--, int_id++)
		{
			
			cin >> name >> location >> date >> duration >> entryfee;
			//name[15] = 0x00;
			//location[20] = 0x00;
			//date[10] = 0x00;
			//id[5] = 0x00;
			//duration[2] = 0x00; 
			//entryfee[3] = 0x00;
			string buff;
			_itoa_s(int_id, id, 10);
		
			buff = id + genspace(10 - strlen(id)) + "|" + name + genspace(30 - strlen(name)) + "|" + location + genspace(40 - strlen(location)) + "|" + date + genspace(20 - strlen(date)) + "|" + duration + genspace(5 - strlen(duration)) + "|" + entryfee + genspace(5 - strlen(entryfee))  ;
			
			writeto(evfile, buff);
			cout << "Done!\n";
			
			//cout << buff;             //test
			
			//write buffer to file      
		}


		//cin >> n;		//test
		
		//exit(0);		//test
	}
};

class employee
{
public:
	char id[5], e_id[5], name[15], mobile[15], desg[15], salary[10];
	const int recsize = 117;

	void addnew()
	{
		cout << "\n Number of records to enter :";
		int n;
		cin >> n;
		cout << "Enter the details \nName\tContact no.\tDesignation\tSalary\tEvent id\n";
		
		// open file move to the end 
		// find the last index 
		// int int_id= last_index;
		int int_id = nextIndex(emfile, recsize);
		//increment it and store it in int_id
		//strcpy_s(id, "0");
		for (; n >= 1; n--, int_id++)
		{
			cin >> name >> mobile >> desg >> salary >> e_id;
			string buff;
			_itoa_s(int_id, id, 10);
			buff = id + genspace(10 - strlen(id)) + "|" + name + genspace(30 - strlen(name)) + "|" + mobile + genspace(20 - strlen(mobile)) + "|" + desg + genspace(20 - strlen(desg)) + "|" + salary + genspace(20 - strlen(salary)) + "|" + e_id + genspace(10 - strlen(e_id)) + "\n";
			writeto(emfile, buff);
			cout << "Done!\n";
			//cout << buff;  //test
			//cin >> buff;

			

			//write buffer to file
		}
		//cin >> n;		//test

		//exit(0);		//test
	

	}
	void modify()// does not modify changes to file
	{
		int ch; 
		string key_id;
		cout << "enter the Employee id to be modiflied\n";
		cin >> key_id;
		int ind = search_rec(key_id, emfile);
		if (ind == -1)
		{
			cout << "record not found\n";
			return;
		}
		//Search the record store the index 
		//return if not found
		cout << "1.Change id\n2.Update details\n";
		cin >> ch;
		fstream f1;
		string buff;
		char strid[5];
		f1.open(emfile, ios::in || ios::out);
		switch (ch)
		{
			case 1:
			{
				
				//buff = add new_id+genspace+record(5:)
				int ind = search_rec(key_id, emfile);
				//if (ind != -1)
				//{
					int new_id;
					cout << "Enter the new Employee id ";
					cin >> new_id;
					
					f1.seekg(ind);
					getline(f1, buff, '\n');
					cout << "pos\t"<<f1.tellg() << "\t-index" << ind << "\t" << buff<<endl;
					_itoa_s(new_id, strid, 10);
					//f1 << strid << genspace(10 - strlen(strid)) << buff << "\n";
					cout << "id modified";
					buff = strid + genspace(10 - strlen(strid)) +"|"+ buff ;
					//read record
					//write buff
					/*cout << buff.length();
					cout << "test\n";
					cout << buff;
					cout << "test\n";
					f1.seekp(ios::end);
					f1 << buff;*/
					// write buff to file 
					//close file 
					//cout << buff;
					insert_line(emfile, buff, ind/recsize, 1);
					cout << "Done!\n";
					f1.close();
				//}
//				else
					//cout << "Invalid id \n";
				//f1.close();
	

			}
				break;
			case 2:
			{	 // open file 
				 // browse for id 

				cout << "Enter new details \n\nName\tContact no.\tDesignation\tSalary\tEvent id\n";
				cin >> name >> mobile>>desg >> salary >> e_id;
				cout << mobile << endl;
				string buff;
				buff = key_id + genspace(10 - key_id.length()) + "|" + name + genspace(30 - strlen(name)) + "|" + mobile + genspace(20 - strlen(mobile)) + "|" + desg + genspace(20 - strlen(desg)) + "|" + salary + genspace(20 - strlen(salary)) + "|" + e_id + genspace(10 - strlen(e_id)) ;
				//cout << buff.length();
				//cout << "test\n";
				cout << buff;
				//cout << "test\n";
				insert_line(emfile, buff, ind / recsize, 1);
				cout << "Done!\n";
				// write buff to file 
				//close file 
				f1.close();
			}
			
			break;

		}
	}
};

class client
{
public:
	char  e_id[5], name[15], mobile[13], amount[10];
	int recsize = 83;
	void addnew()
	{
		cout << "Enter details\nName\tContact no.\tAmount\tEvent id\n";
		cin >> name >> mobile >> amount >> e_id;
		//Open file
		// read offset for event 
		//if not present add to event id to offset list and index it as end of file 
		//find last index; store in id
		//strcpy(id, "0");
		string buff = e_id + genspace(10 - strlen(e_id)) + "|"+ name + genspace(30 - strlen(name)) + "|" + mobile + genspace(20 - strlen(mobile)) + "|" + amount + genspace(20 - strlen(amount)) ;
		add_offset_rec(clfile, e_id, buff);
		

		//print to 
	}
	//void addnew()
	//{
	//	
	//	////	
	//	cout << "\n Number of records to enter :";
	//	int n;
	//	cin >> n;
	//	cout << "Enter details\nName\tContact no.\tAmount\tEvent id\n";
	//	
	//	string temp;


	//	
	//	for (; n >= 1; n--)
	//	{
	//		fstream f;
	//		f.open(clfile, ios::in | ios::out);
	//		cin >> name >> mobile >> amount >> e_id;
	//		int c = 0;
	//		while (!f.eof())
	//		{
	//			c++;
	//			getline(f, temp, '|');
	//			temp = trim(temp);
	//			if (temp == e_id)
	//			{
	//				getline(f, temp, '\n');
	//				break;
	//			}
	//			getline(f, temp, '\n');
	//		}


	//		string buff;

	//		buff = e_id + genspace(10 - strlen(e_id)) + "|" + name + genspace(30 - strlen(name)) + "|" + mobile + genspace(20 - strlen(mobile)) + "|" + amount + genspace(20 - strlen(amount));
	//		insert_line(clfile, buff, c, 0);
	//		cout << buff << endl;  //test
	//		//cin >> buff;
	//		f.close();
	//		//write buffer to file
	//	}

	//}
};
	
class vendor
{
public:
	char e_id[5], name[15], mobile[15], desc[40], amount[10];
	int recsize=114;
	void addnew()
	{
		cout << "Enter details\n";
		cout << "Name\t";
		cin >> name;
		cout << "Contact no.\t";
		cin >> mobile;
		cout << "Description\t";
		getchar();
		cin.getline(desc, 35);
		cout << "Amount\t";
		cin >> amount;
		cout << "Event id\n";
		cin >> e_id;
		
		string buff = e_id + genspace(10 - strlen(e_id)) + "|" + name + genspace(30 - strlen(name)) + "|" + mobile + genspace(20 - strlen(mobile)) + "|" + desc + genspace(50 - strlen(desc)) +"|"+ amount + genspace(20 - strlen(amount));
		add_offset_rec(vefile, e_id, buff);
		cout << "Done!\n";
		
	}
};

class attendee
{
public:
	char name[15], mobile[15], email[20], id[5], e_id[5];
	int recsize = 105;
	
	void addnew()
	{
		int c;
		ifstream f;
		int int_id=1;
		f.open(atfile);
		//cout << ios::end << endl;
		
			if (!f.eof());
			{
				
				//cin >> c;
				string t;
				getline(f, t, '\n');
				
				if (t.length() >= 4)
				{
					vector<string> v = split(t, "|");
					
					c = v.size() - 2;
				
					vector<string> e = split(v[c], ":");
					int_id = stoi(e[1]);
					
				}
			}
			
		
	
		_itoa_s(int_id, id, 10);
		cout << "Enter details\nName\tContact no.\temail id\tEvent id\n";
		cin >> name >> mobile >> email >> e_id;

		string buff = e_id + genspace(10 - strlen(e_id)) + "|" + id + genspace(10 - strlen(id)) + "|" + name + genspace(30 - strlen(name)) + "|" + mobile + genspace(20 - strlen(mobile)) + "|" + email + genspace(30 - strlen(email)) ;
		cout << buff << endl;
		
		add_offset_rec(atfile, e_id, buff);
	}
};

class sponsor
{
public:
	char e_id[5], name[15], mobile[15], email[20], amount[10];
	const int recsize = 125;
	void addnew()
	{
		cout << "Enter details\nName\tContact no.\tEmail\tAmount\tEvent id\n";
		cin >> name >> mobile >>email>> amount >> e_id;
		//Open file
		// read offset for event 
		//if not present add to event id to offset list and index it as end of file 
		//find last index; store in id
		//strcpy(id, "0");
		string buff = e_id + genspace(10 - strlen(e_id)) + "|" + name + genspace(30 - strlen(name)) + "|" + mobile + genspace(20 - strlen(mobile)) + "|" + email + genspace(40 - strlen(email)) + "|" + amount + genspace(20 - strlen(amount));
		add_offset_rec(spfile, e_id, buff);


		//print to 
	}

	
};

class advert
{
public:
	char e_id[5], company[15], email[20], location[20], amount[10], reach[10];
	void addnew()
	{
		cout << "Enter details\nCompany Name\tEmail\tLocation\tExpected Reach\tAmount\tEvent id\n";
		cin >> company >> email >>location>> reach>> amount >> e_id;
		//Open file
		// read offset for event 
		//if not present add to event id to offset list and index it as end of file 
		//find last index; store in id
		//strcpy(id, "0");
		string buff = e_id + genspace(10 - strlen(e_id)) + "|" + company + genspace(30 - strlen(company)) + "|"  + email + genspace(40 - strlen(email)) + "|" + location + genspace(40 - strlen(location)) + "|" +  reach + genspace(20 - strlen(reach)) +"|"+ amount + genspace(20 - strlen(amount))  ;
		add_offset_rec(adfile, e_id, buff);


		//print to 
	}
};










int main()
{
	clrscr();
	rollback();
	int ch1;


	while (true)
	{
		
	home: clrscr(); 
		
		type("1.Enter Data\n2.View Event Information\n");
		cin >> ch1;
		clrscr();
		switch (ch1)
		{
			enter:case 1: 
			{ 
				type("1.New Event\n2.New Employee\n3.New Client\n4.New Vendor\n5.New Sponsor\n6.New Advertising Agency\n7.Add Participants/Attendees\n8.Commit Changes\n9.RollBack Changes\n");
				int ch;
				cin >> ch;
				switch (ch)
				{
					case 1: 
					{
						event e;
						clrscr();
						e.addnew();
						//modify: details (except id)
						//no delete
					}
						break;
					
					case 2:
					{
						clrscr();
						//1.add: similar add func
						//2.modify: other details
						//3.modify: id -  change id in program, sort, replace old e_id with new e_id in all files
						//4.delete : remove employee
						cout << "1.Create an entry for a new employee\n2.modify existing employee\n";
						int ch2;
						cin >> ch2;
						employee em;
						switch (ch2)
						{
						case 1:
						{
							em.addnew();
						}	break;
						case 2:
						{
							em.modify();
						}	break;
						default: cout << "invalid choice\n";
						}
					}
						break;
					case 3: 
					{
						clrscr();
						client c;
						c.addnew();
						//add no modify no delete
					}
						break;
					case 4:
					{
						clrscr();
						vendor v;
						v.addnew();
						//similar to client
					}
						break;
					case 5: 
					{
						clrscr();
						sponsor s;
						s.addnew();
						//similar to client
					}
						break;
					case 6:
					{
						clrscr();
						advert a;
						a.addnew();
						//similar to client
					}
						break;
					case 7:
					{
						clrscr();
						attendee at;
						at.addnew();
						//similar to client
					}
						break;
					case 8:
					{
						commit();

					}
						break;
					case 9: 
					{
						rollback();
					}
						break;

					default: cout << "Invalid choice";
							goto home;

				}
			
				//Sleep(3000);    //test
				goto enter;
			}
				break;
		
			case 2: 
			{ 
				type("1.Display Event List \n2.View Sponsorship Information\n3.View Clients\n4.View Vendors\n5.List of Attendees\n6.Expenditure vs Income\n7.Advertisement Analysis\nEnter 0 to jump to home");
				int ch;
				cin >> ch;
				switch (ch)
				{
					case 1: // display event list
					{
						fstream f1;
						string temp;
						f1.open(evfile, ios::in);
						clrscr();
						while (!f1.eof())
						{
							getline(f1, temp);
							cout << temp << endl;
						}
						f1.close();
					}
					Sleep(3000);
					break;
					
					case 2:// View Sponsorship Information
					{
						cout << "Enter event id -";
						string e_id;
						cin >> e_id;
	
						cout << "Name\t\t\t\tMobile\t\t     Email\t\t\t\t    Amount\n__________________________________________________________________________________________________________________\n";
						display(spfile, e_id);
						cin >> e_id;  //test
	
						// match event id with sponsors file 
					}		
					break;
	
					
					case 3:// View Clients	
					{
						clrscr();
						cout << "1.Display all Clients\n2.Specific to an event\n";
						int ch;
						string e_id;
						cin >> ch;
							
						if (ch == 1)
						{
							cout << "Name\t\t\t\tMobile\t\t    Amount\n______________________________________________________________\n";
							display(clfile, "-1");
							cin >> e_id; //test
						}
						else
						{
							cout << "Enter event id -";
								
							cin >> e_id;

							cout << "Name\t\t\t\tMobile\t\t    Amount\n______________________________________________________________\n";
							display(clfile, e_id);
							cin >> e_id; //test
						}
	
						// match event id with sponsors file 
					}
					// match event id with client file 
					break;
		
					case 4:// View Vendors
					{
						cout << "Enter event id -";
						string e_id;
						cin >> e_id;
						vendor v;
						cout << "Name\t\t\t       Mobile\t\t    Description\t\t\t\t\t       Amount\n_______________________________________________________________________________________________________________\n";
						display(vefile, e_id);
						cin >> e_id;
					}
					// match event id with client file 
					break;
		
					case 5: // View Attendees
					{
						cout << "Enter event id -";
						string e_id;
						cin >> e_id;
						cout << "id\t    Name\t\t\t  Mobile\t\te-mail\n_____________________________________________________________________\n";
						display(atfile, e_id);
						cin >> e_id;
					}
					break;
	
					case 6:// income expense
					{
						cout << "Enter event id -";
						string e_id;
						cin >> e_id;
						clrscr();
						// income = sum of amount from (client+sponsor) + num(attendees)*event_id.entryfee
						long t, sum = 0, income=0, expense =0;
						fstream f;
						f.open(evfile, ios::in);
						int  s =search_rec(e_id, evfile);
						if (s==-1)
						{
							cout<<"Event not found\n";
							Sleep(3000);
								break;
						}
						f.seekg(s);
						string temp;
						getline(f, temp, '\n');
						//cout << temp << endl;
						//vector<string> v = split(temp, "|");
						//int entryfee = stoi(trim(v[3]);
						int entryfee = stoi(getFeild(temp, 5));
						
						cout << "\nIncome sources -\n\n";
						t = add(clfile, e_id);
						income = income + add(clfile, e_id);
						cout << "Money from clients -> " << t<<endl;
						
						t = add(spfile, e_id);
						income = income + add(spfile, e_id);
						cout << "Money from sponsors -> " << t<<endl;
						
						t = (add(atfile, e_id)* entryfee);
						income = income +(add(atfile, e_id)* entryfee);
						cout << "Money from Attendees -> " << t<<endl;
						
						cout << "-------------------------------------\nTotal income =" << income << "\n\n";
						cout << "\nExpense -\n\n";
						t = add(emfile, e_id);
						expense = expense + add(emfile, e_id);
						cout << "Employees' salaries  -> " << t<<endl;
						
						t = add(adfile, e_id);
						expense = expense+ add(adfile, e_id);
						cout << "Marketing/Advertising cost  -> " << t << endl;
						
						t = add(vefile, e_id);
						expense = expense + add(vefile, e_id);
						cout << "Vendors' payments  -> " << t<<endl;
						cout << "-------------------------------------\nTotal Expenditure =" << expense << "\n\n";


						sum = income - expense;
						cout << "-------------------------------------\n-------------------------------------\nTotal profit =" << sum;
						cout << "\nProfitability =" << ((float)sum / income)*100 << "%\n";
						//cout << sum;
						cin >> sum;
							// expenditure= sum of amount from (employee+advert+vendor)
							// print profit, gain/loss%
					}	break;
		
					case 7:// advert analysis
						// enter event no 
					{
						cout << "Enter event id -";
						string e_id;
						cin >> e_id;
						clrscr();
						cout << "Advertisement Analysis\n\n";
						fstream f;
						f.open(evfile, ios::in);
						int  s = search_rec(e_id, evfile);
						if (s == -1)
						{
							cout << "Event not found\n";
							Sleep(3000);
							break;
						}
						// total amount spent:  expected attendees: actual attendees:  cost/attendee: 

						long a, b,c;
						a = add(adfile, e_id);
						cout << "Total amount spent : " << a << endl;
						b = add(adfile, e_id, 5);
						cout << "Expected attendees: " << b << endl;
						c = add(atfile, e_id);
						cout << "Actual attendees: " << c << endl;
						cout << "Fulfillment :" << ((float)c / b) * 100 <<"%\n";
						cout << "Cost per attendee: " << (float)a / c << endl;
						cin >> e_id;
					}
						break;
	
					case 0: goto home;
					default: cout << "Invalid choice";
						
				}
			}
			default: cout << "Invalid choice";
			

		}
	
	}
}