#pragma once
#include<stdio.h>
#include<fstream>
#include<stdlib.h>
#include <iostream>
#include<Windows.h>
#include<string>
#include <sstream>
#include <vector>




using namespace std;


#define evfile "Files/event_list.txt"
#define atfile "Files/attendee_records.txt"
#define spfile "Files/sponsors_details.txt"
#define vefile "Files/vendors_details.txt"
#define adfile "Files/advertise_contracts.txt"
#define emfile "Files/employee_records.txt"
#define clfile "Files/client_list.txt"

#define oevfile "Files/rollback/event_list.txt"
#define oatfile "Files/rollback/attendee_records.txt"
#define ospfile "Files/rollback/sponsors_details.txt"
#define ovefile "Files/rollback/vendors_details.txt"
#define oadfile "Files/rollback/advertise_contracts.txt"
#define oemfile "Files/rollback/employee_records.txt"
#define oclfile "Files/rollback/client_list.txt"
#define temp1   "Files/temp/temp_file_1.txt"
#define temp2   "Files/temp/temp_file_2.txt"


void type(string str);
void clrscr();
string genspace(int a);
void rollback();
void commit();
void writeto(string, string);
void movef(string dest, string src);
int nextIndex(string str, int recsize);
int search_rec(string id, string fname);
string trim(const string& str);
vector<string> split(string s, string delimiter);
void add_offset_rec(string fname, string e_id, string buff);
void insert_line(string fname, string buff, int pos, int x);
void display(string fname, string e_id);
int add(string fname, string e_id, int rec =0);
string getFeild(string str, int f = 0);