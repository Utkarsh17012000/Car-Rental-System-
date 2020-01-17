#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
#include<conio.h>
#include<fstream>
#include<process.h>
#include<ctime>
#include<string.h>
//#include<graphics.h>
#include<stdlib.h>
using namespace std;
class database
{		int no_of_days,no_of_members,no_of_hours,shr,sdd,smm,syy,edd,emm,eyy;
		char st_point[20],des_point[20],name[20],payment_mode[15],car_name[30],status[10];

	public: 
		database()
		{	no_of_hours=0,shr=0,sdd=0,smm=0,syy=0,edd=0,emm=0,eyy=0;
		}

		void carnames(int members)
		{
				if(members==4)
				{	cout<<"\nSno. Name\n";
					cout<<"1    Maruti Swift\n";
					cout<<"2    Maruti Alto 800\n";
					cout<<"3    Hyundai Grand I10\n";
					cout<<"4    Maruti Wagon R\n";
					cout<<"5    Maruti Celerio\n";
				}
				else if(members==9)
				{	cout<<"\nSno. Name\n";
					cout<<"1    Mitsubishi Pajero Sport\n";
					cout<<"2    Mahindra Scorpio       \n";
					cout<<"3    Mahindra Bolero        \n";
					cout<<"4    Toyota Fortuner        \n";
					cout<<"5    Ford Endeavour         \n";
				}
				else if(members==7)
				{	cout<<"\nSno. Name\n";
					cout<<"1    Mahindra XUV500\n";
					cout<<"2    Mazda CX9      \n";
					cout<<"3    Toyota Klugar  \n";
					cout<<"4    Nissan Patrol  \n";
					cout<<"5    Tata Hexa      \n";
				}
				else
				cout<<"Invalid Input!!!";
		}
		void enterdetails();
		int car_checking(char*);
}db;

/*void database::statuszero()
{	int i;
	for(i=0;i<10;++i)
	{	status[i]='\0';
	}
}*/
void database::enterdetails()
		{ 	int i,get;
			int confirm_renting,enter_again;
			label:	system("cls");
					cout<<"Enter days you want car: ";
					cin>>no_of_days;

			if(no_of_days==1)
			{  	cout<<"Enter the starting point: ";
				cin.sync();
				cin.getline(st_point,20);
				cout<<"Enter the destination point: ";
				cin.sync();
				cin.getline(des_point,20);
				cout<<"Enter the number of hours you want car: ";
				cin>>no_of_hours;
				cout<<"Enter start hour(24 hour format): ";
				cin>>shr;
				cout<<"Number of members: ";
				cin>>no_of_members;

				carnames(no_of_members);

				cout<<endl<<"Enter the car's name you want: ";
				cin.sync();
				cin.getline(car_name,30);
				
				ofstream filout;
				filout.open("testing.txt",ios::out|ios::app);
				
				get=car_checking(car_name);
				
				if(get==1)
				{	cout<<"Car has already been rented!!\n sorry!!\n";
					cout<<"Do you want to enter again(1 for yes): ";
					cin>>enter_again;
					if(enter_again==1)
				    {	enter_again=0;
						goto label;
				    }
				}
				else
				{	cout<<"Do you want to confirm your renting(1 for yes)... ";
					cin>>confirm_renting;
				}

				if(confirm_renting==1)
				{	cout<<"Enter designated name: ";
					cin.sync();
					cin.getline(name,20);
					cout<<"payement mode(Cash/Debit card/credit card): ";
					cin.sync();
					cin.getline(payment_mode,15);
					strcpy(status,"rented");

					filout.write((char*)&db,sizeof(db));
					filout.close();

					no_of_days=0; no_of_hours=0; no_of_members=0;

					for(i=0;i<20;++i)
					{	status[i]='\0';
					}
					for(i=0;i<20;++i)
					{	st_point[i]='\0';
						des_point[i]='\0';
						name[i]='\0';
					}
					for(i=0;i<15;++i)
					{      payment_mode[i]='\0';
					}
					for(i=0;i<30;++i)
					{      car_name[i]='\0';
					}

					confirm_renting=0;

					cout<<"Thanks for using services!!!";

					cout<<endl<<"Enter 1 if you want to enter again";
					cin>>enter_again;

					if(enter_again==1)
					{	enter_again=0;
						goto label;
					}
				}

				else
				{       cout<<"Thanks for using services!!!";

					no_of_days=0; no_of_hours=0; no_of_members=0;

					for(i=0;i<20;++i)
					{	status[i]='\0';
					}
					for(i=0;i<20;++i)
					{	st_point[i]='\0';
						des_point[i]='\0';
						name[i]='\0';
					}
					for(i=0;i<15;++i)
					{      payment_mode[i]='\0';
					}
					for(i=0;i<30;++i)
					{      car_name[i]='\0';
					}

					cout<<endl<<"Enter 1 if you want to enter again";
					cin>>enter_again;

					if(enter_again==1)
					{       enter_again=0;
						goto label;
						
					}
				}
			}
			else
			{	cout<<endl<<"Enter the starting point: ";
				cin.sync();
				cin.getline(st_point,20);
				cout<<"Enter the destination point: ";
				cin.sync();
				 cin.getline(des_point,20);
				cout<<"Enter starting date (dd mm yy): ";
				cin>>sdd>>smm>>syy;
				cout<<"Enter ending date (dd mm yy) (Month must be same): ";
				cin>>edd>>emm>>eyy;
				cout<<"Number of members: ";
				cin>>no_of_members;
				carnames(no_of_members);
				cout<<endl<<"Enter the car's name you want: ";
				cin.sync();
				cin.getline(car_name,30);
				
				ofstream filout;
				filout.open("testing.txt",ios::out|ios::app);
					
				get=car_checking(car_name);
				
				if(get==1)
				{	cout<<"Car has already been rented!!\n sorry!!\n";
					cout<<"Do you want to enter again(1 for yes): ";
					cin>>enter_again;
					if(enter_again==1)
				   {	enter_again=0;
						goto label;
				   }
				}
				else
				{	cout<<"Do you want to confirm your renting(1 for yes)... ";
					cin>>confirm_renting;
				}

				if(confirm_renting==1)
				{	cout<<"Enter designated name: ";
					cin.sync();
					cin.getline(name,20);
					cout<<"payement mode(Cash/Debit card/credit card): ";
					cin.sync();
					cin.getline(payment_mode,15);
					strcpy(status,"rented");

					filout.write((char*)&db,sizeof(db));
					filout.close();

					 no_of_days=0; sdd=0; smm=0; syy=0;
					 edd=0; emm=0; syy=0;

					for(i=0;i<20;++i)
					{	status[i]='\0';
					}
					for(i=0;i<20;++i)
					{	st_point[i]='\0';
						des_point[i]='\0';
						name[i]='\0';
					}
					for(i=0;i<15;++i)
					{      payment_mode[i]='\0';
					}
					for(i=0;i<30;++i)
					{      car_name[i]='\0';
					}

					confirm_renting=0;

					cout<<"Thanks for using services!!!";

					cout<<endl<<"Enter 1 if you want to enter again";
					cin>>enter_again;

					if(enter_again==1)
					{       enter_again=0;
						goto label;
					}
				}
				else
				{       cout<<"Thanks for using services!!!";

					 sdd=0; smm=0; syy=0;
					 edd=0; emm=0; syy=0;


					for(i=0;i<20;++i)
					{	status[i]='\0';
					}
					for(i=0;i<20;++i)
					{	st_point[i]='\0';
						des_point[i]='\0';
						name[i]='\0';
					}
					for(i=0;i<15;++i)
					{      payment_mode[i]='\0';
					}
					for(i=0;i<30;++i)
					{      car_name[i]='\0';
					}

					 cout<<endl<<"Enter 1 if you want to enter again";
					 cin>>enter_again;

					if(enter_again==1)
					{        enter_again=0;
						 goto label;
					}
				}
			}
		}

struct copy
{	int no_of_days,no_of_members,no_of_hours,shr,sdd,smm,syy,edd,emm,eyy;
	char st_point[20],des_point[20],name[20],payment_mode[15],car_name[30],status[10];
}cpy;

struct deletion
{	int no_of_days,no_of_members,no_of_hours,shr,sdd,smm,syy,edd,emm,eyy;
	char st_point[20],des_point[20],name[20],payment_mode[15],car_name[30],status[10];
}del;

int database::car_checking(char *car_name)
{	int count=0,i;
	ifstream filin;
	filin.open("testing.txt",ios::in);

  while(!filin.eof())
  {     filin.read((char*)&cpy,sizeof(cpy));
		if(strcmp(cpy.car_name,car_name)==0)
		count++;
  }
	     cpy.sdd=0; cpy.smm=0; cpy.syy=0;
		 cpy.edd=0; cpy.emm=0; cpy.syy=0;
		 cpy.no_of_days=0; cpy.no_of_hours=0; cpy.no_of_members=0;

		 for(i=0;i<20;++i)
		 {	cpy.st_point[i]='\0';
			cpy.des_point[i]='\0';
			cpy.name[i]='\0';
		 }
		 for(i=0;i<15;++i)
		 {      cpy.payment_mode[i]='\0';
		 }
		 for(i=0;i<30;++i)
		 {      cpy.car_name[i]='\0';
		 }
		 for(i=0;i<10;++i)
		 {      cpy.status[i]='\0';
		 }

  
  if(count!=0)
  return(1);
  else
  return(0);
 } 

void availability()
{   
	char car_name[30];
	int i,count=0;
	
	cout<<endl<<"Enter the name of car: ";
	cin.sync();
	cin.getline(car_name,30);

	ifstream filin;
	filin.open("testing.txt",ios::in);

  while(!filin.eof())
  {     filin.read((char*)&cpy,sizeof(cpy));
	if(strcmp(cpy.car_name,car_name)==0)
	{       if(cpy.no_of_days==1)
		{	cout<<"\n\t NAME MATCHED\n\n";
			cout<<"Car has already been rented !!!!\n\nDetails are:-\n\n";
			cout<<endl<<"\tCar rented is: "<<cpy.car_name;
			cout<<endl<<"\tStarting point: "<<cpy.st_point<<endl;
			cout<<"\tEnding point: "<<cpy.des_point<<endl;
			cout<<"\tNumber of days: "<<cpy.no_of_days<<endl;
			cout<<"\tNumber of hours: "<<cpy.no_of_hours<<endl;
			cout<<"\tNumber of members: "<<cpy.no_of_members<<endl;
			cout<<endl<<"\tPERSONAL DETAILS:-\n";
			cout<<"\tDesignted name: "<<cpy.name<<endl;
			cout<<"\tPayment mode: "<<cpy.payment_mode<<endl;
		}
		else if(cpy.no_of_days>1)
		{   cout<<"\t NAME MATCHED\n\n";
			cout<<"Car has already rented !!!!\n\nDetails are:-\n\n";
			cout<<"\tCAR RENTED: "<<cpy.car_name;
			cout<<"\tStarting point: "<<cpy.st_point<<endl;
			cout<<"\tEnding point: "<<cpy.des_point<<endl;
			cout<<"\tStarting date: "<<cpy.sdd<<"/"<<cpy.smm<<"/"<<cpy.syy<<endl;
			cout<<"\tEnding date: "<<cpy.edd<<"/"<<cpy.emm<<"/"<<cpy.syy<<endl;
			cout<<"\tNumber of members: "<<cpy.no_of_members<<endl;
			cout<<"\tPERSONAL DETAILS:-\n";
			cout<<"\tDesignted name: "<<cpy.name<<endl;
			cout<<"\tPayment mode: "<<cpy.payment_mode<<endl;
		 }
		 else
		 {	cout<<endl<<"Invalid Input!!!!";
		 }
		 count++;

		 cpy.sdd=0; cpy.smm=0; cpy.syy=0;
		 cpy.edd=0; cpy.emm=0; cpy.syy=0;
		 cpy.no_of_days=0; cpy.no_of_hours=0; cpy.no_of_members=0;

		 for(i=0;i<20;++i)
		 {	cpy.st_point[i]='\0';
			cpy.des_point[i]='\0';
			cpy.name[i]='\0';
		 }
		 for(i=0;i<15;++i)
		 {      cpy.payment_mode[i]='\0';
		 }
		 for(i=0;i<30;++i)
		 {      cpy.car_name[i]='\0';
		 }
		 for(i=0;i<10;++i)
		 {      cpy.status[i]='\0';
		 }

	}
  }
  filin.close();

  if(count==0)
  {	cout<<endl<<"CAR is AVAILABLE!!";
  }
  count=0;
}

void tracking()
{       char name[20];
		int diff,i,count=0;

	cout<<"Enter Designated Name: ";
	cin.sync();
	cin.getline(name,20);

	ifstream filin;
	filin.open("testing.txt",ios::in);

	time_t now=time(0);
	tm* ltm=localtime(&now);

   while(!filin.eof())
   {	filin.read((char*)&cpy,sizeof(cpy));

	if(strcmp(cpy.name,name)==0)
	{	if(cpy.no_of_days==1)
		{   system("cls");
			cout<<"NAME MATCHED!!!!"<<endl;
			cout<<"Car has already rented !!!!\n\nDetails are:-\n\n";
			cout<<"CAR RENTED: "<<cpy.car_name<<endl<<endl;
			cout<<"\tStarting point: "<<cpy.st_point<<endl;
			cout<<"\tEnding point: "<<cpy.des_point<<endl;
			cout<<"\tNumber of days: "<<cpy.no_of_days<<endl;
			cout<<"\tNumber of hours: "<<cpy.no_of_hours<<endl;
			cout<<"\tStarting hour: "<<cpy.shr<<endl;
			cout<<"\tNumber of members: "<<cpy.no_of_members<<endl;
			cout<<"\tPERSONAL DETAILS:-\n";
			cout<<"\tDesignted name: "<<cpy.name<<endl;
			cout<<"\tPayment mode: "<<cpy.payment_mode<<endl;

			cout<<"\n\nTracking would start in a while.\nPlease wait...  ";
								
			int curr_hour,halfhours;
			curr_hour=ltm->tm_hour;
			halfhours=cpy.no_of_hours/2;
				
			if(curr_hour>=cpy.shr)
			{	
				diff=curr_hour-cpy.shr;

				if(diff<=cpy.no_of_hours)
				{	int gd=DETECT,gm;
					initgraph(&gd, &gm,"C:\\TC\\BGI");
					
					for( i=0;i<=halfhours;++i)
					{	line(200+(100*i),210,200+(100*i),190);
					}	
				
					if(diff<=halfhours)
					{	circle(200+(100*diff),180,10);
						getch();
					}
					else
					{	diff=cpy.no_of_hours-diff;
						circle(200+(100*diff),180,10);
						getch();
					}
				}
				if(diff>cpy.no_of_hours)
				{	filin.close();
					free(filin);
					
					cout<<"Journey has finished..";
					if((cpy.no_of_hours)%2!=0)
					{	cout<<"Car is delayed by 1 hour.";
					}
					
							strcpy(del.car_name,cpy.car_name);
							strcpy(del.des_point,cpy.des_point);
							strcpy(del.st_point,cpy.st_point);
							strcpy(del.status,cpy.status);
							strcpy(del.name,cpy.name);
							strcpy(del.payment_mode,cpy.payment_mode);
							del.edd=cpy.edd; del.emm=cpy.emm; del.eyy=cpy.eyy; del.no_of_days=cpy.no_of_days; del.no_of_hours=cpy.no_of_hours; del.no_of_members=cpy.no_of_members; del.sdd=cpy.sdd; del.shr=cpy.shr; del.smm=cpy.smm; del.syy=cpy.syy;
												
							ifstream fin1;
							fin1.open("testing.txt",ios::in);
								
							remove("test.txt");	
															
							ofstream fout1;
							fout1.open("test.txt",ios::out|ios::app);
							
							while(!fin1.eof())
							{	fin1.read((char*)&cpy,sizeof(cpy));
								fout1.write((char*)&cpy,sizeof(cpy));
								cpy.sdd=0; cpy.smm=0; cpy.syy=0;
		 						cpy.edd=0; cpy.emm=0; cpy.syy=0;
		 						cpy.no_of_days=0; cpy.no_of_hours=0; cpy.no_of_members=0;
	
			 					for(i=0;i<20;++i)
								 {	cpy.st_point[i]='\0';
									cpy.des_point[i]='\0';
									cpy.name[i]='\0';
								 }
								 for(i=0;i<15;++i)
								 {      cpy.payment_mode[i]='\0';
								 }
								 for(i=0;i<30;++i)
								 {      cpy.car_name[i]='\0';
								 }
								 for(i=0;i<10;++i)
								 {      cpy.status[i]='\0';
								 }
									
							}
							cout<<endl<<count;
							fout1.close();
							fin1.close();
							
					ifstream fin2;
					fin2.open("test.txt",ios::in);
					
					remove("testing.txt");
					
					ofstream fout2;
					fout2.open("testing.txt",ios::out|ios::app);
					
					while(!fin2.eof())
					{	fin2.read((char*)&cpy,sizeof(cpy));
						if(strcmp(del.car_name,cpy.car_name)==0)
						{	cpy.sdd=0; cpy.smm=0; cpy.syy=0;
		 					cpy.edd=0; cpy.emm=0; cpy.syy=0;
		 					cpy.no_of_days=0; cpy.no_of_hours=0; cpy.no_of_members=0;

		 					for(i=0;i<20;++i)
							 {	cpy.st_point[i]='\0';
								cpy.des_point[i]='\0';
								cpy.name[i]='\0';
							 }
							 for(i=0;i<15;++i)
							 {      cpy.payment_mode[i]='\0';
							 }
							 for(i=0;i<30;++i)
							 {      cpy.car_name[i]='\0';
							 }
							 for(i=0;i<10;++i)
							 {      cpy.status[i]='\0';
							 }
						   	continue;
						}
						else
						{
							fout2.write((char*)&cpy,sizeof(cpy));
						}
						
							cpy.sdd=0; cpy.smm=0; cpy.syy=0;
		 					cpy.edd=0; cpy.emm=0; cpy.syy=0;
		 					cpy.no_of_days=0; cpy.no_of_hours=0; cpy.no_of_members=0;

		 					for(i=0;i<20;++i)
							 {	cpy.st_point[i]='\0';
								cpy.des_point[i]='\0';
								cpy.name[i]='\0';
							 }
							 for(i=0;i<15;++i)
							 {      cpy.payment_mode[i]='\0';
							 }
							 for(i=0;i<30;++i)
							 {      cpy.car_name[i]='\0';
							 }
							 for(i=0;i<10;++i)
							 {      cpy.status[i]='\0';
							 }
					}
					
					fout2.close();
					fin2.close();
					
					ifstream filin;
					filin.open("testing.txt",ios::in);
				}
			}
			else
			cout<<"Journey has not started yet!!!";
		}
		else
		{   system("cls");
			cout<<"\t NAME MATCHED\n";
			cout<<"Car has already rented !!!!\n\nDetails are:-\n\n";
			cout<<"\tCAR RENTED: "<<cpy.car_name<<endl;
			cout<<"\tStarting point: "<<cpy.st_point<<endl;
			cout<<"\tEnding point: "<<cpy.des_point<<endl;
			cout<<"\tStarting date: "<<cpy.sdd<<"/"<<cpy.smm<<"/"<<cpy.syy<<endl;
			cout<<"\tEnding date: "<<cpy.edd<<"/"<<cpy.emm<<"/"<<cpy.eyy<<endl;
			cout<<"\tNumber of members: "<<cpy.no_of_members<<endl;
			cout<<"\tPERSONAL DETAILS:-\n";
			cout<<"\tDesignted name: "<<cpy.name<<endl;
			cout<<"\tPayment mode: "<<cpy.payment_mode<<endl;

			cout<<"\n\nTracking would start in a while.\nplease wait...  ";
					
			int curr_dd,curr_mm,halfdays;

			curr_dd=ltm->tm_mday;
			curr_mm=1+ltm->tm_mon;

			halfdays=(cpy.no_of_days/2);

			if(curr_mm==cpy.emm)
			{	if(curr_dd>=cpy.sdd)
				{	if(curr_dd<=cpy.edd)
					{	int gd=DETECT,gm;
						initgraph(&gd, &gm,"C:\\TC\\BGI");
					
						for( i=0;i<=halfdays;++i)
						{	line(200+(100*i),210,200+(100*i),190);
						}
						diff=curr_dd-cpy.sdd;

						if(diff<=halfdays)
						{	circle(200+(100*diff),180,10);
							getch();
						}
						else
						{	diff=cpy.no_of_days-diff;
							circle(200+(100*diff),180,10);
							getch();
						}
					}
					else
					{	
						cout<<endl<<"Journey has finished";
						 if((cpy.no_of_days%2)!=0)
						 {	cout<<endl<<"Car is delayed by 1 day";					
						 	filin.close();
							free(filin);
					
								cout<<"Journey has finished..";
								if((cpy.no_of_hours)%2!=0)
								{	cout<<"Car is delayed by 1 hour.";
								}
								
										strcpy(del.car_name,cpy.car_name);
										strcpy(del.des_point,cpy.des_point);
										strcpy(del.st_point,cpy.st_point);
										strcpy(del.status,cpy.status);
										strcpy(del.name,cpy.name);
										strcpy(del.payment_mode,cpy.payment_mode);
										del.edd=cpy.edd; del.emm=cpy.emm; del.eyy=cpy.eyy; del.no_of_days=cpy.no_of_days; del.no_of_hours=cpy.no_of_hours; del.no_of_members=cpy.no_of_members; del.sdd=cpy.sdd; del.shr=cpy.shr; del.smm=cpy.smm; del.syy=cpy.syy;
															
										ifstream fin1;
										fin1.open("testing.txt",ios::in);
											
										remove("test.txt");	
																		
										ofstream fout1;
										fout1.open("test.txt",ios::out|ios::app);
										
										while(!fin1.eof())
										{	fin1.read((char*)&cpy,sizeof(cpy));
											fout1.write((char*)&cpy,sizeof(cpy));
											cpy.sdd=0; cpy.smm=0; cpy.syy=0;
					 						cpy.edd=0; cpy.emm=0; cpy.syy=0;
					 						cpy.no_of_days=0; cpy.no_of_hours=0; cpy.no_of_members=0;
				
						 					for(i=0;i<20;++i)
											 {	cpy.st_point[i]='\0';
												cpy.des_point[i]='\0';
												cpy.name[i]='\0';
											 }
											 for(i=0;i<15;++i)
											 {      cpy.payment_mode[i]='\0';
											 }
											 for(i=0;i<30;++i)
											 {      cpy.car_name[i]='\0';
											 }
											 for(i=0;i<10;++i)
											 {      cpy.status[i]='\0';
											 }
												
										}
										cout<<endl<<count;
										fout1.close();
										fin1.close();
										
								ifstream fin2;
								fin2.open("test.txt",ios::in);
								
								remove("testing.txt");
								
								ofstream fout2;
								fout2.open("testing.txt",ios::out|ios::app);
								
								while(!fin2.eof())
								{	fin2.read((char*)&cpy,sizeof(cpy));
									if(strcmp(del.car_name,cpy.car_name)==0)
									{	cpy.sdd=0; cpy.smm=0; cpy.syy=0;
					 					cpy.edd=0; cpy.emm=0; cpy.syy=0;
					 					cpy.no_of_days=0; cpy.no_of_hours=0; cpy.no_of_members=0;
			
					 					for(i=0;i<20;++i)
										 {	cpy.st_point[i]='\0';
											cpy.des_point[i]='\0';
											cpy.name[i]='\0';
										 }
										 for(i=0;i<15;++i)
										 {      cpy.payment_mode[i]='\0';
										 }
										 for(i=0;i<30;++i)
										 {      cpy.car_name[i]='\0';
										 }
										 for(i=0;i<10;++i)
										 {      cpy.status[i]='\0';
										 }
									   	continue;
									}
									else
									{
										fout2.write((char*)&cpy,sizeof(cpy));
									}
									
										cpy.sdd=0; cpy.smm=0; cpy.syy=0;
					 					cpy.edd=0; cpy.emm=0; cpy.syy=0;
					 					cpy.no_of_days=0; cpy.no_of_hours=0; cpy.no_of_members=0;
			
					 					for(i=0;i<20;++i)
										 {	cpy.st_point[i]='\0';
											cpy.des_point[i]='\0';
											cpy.name[i]='\0';
										 }
										 for(i=0;i<15;++i)
										 {      cpy.payment_mode[i]='\0';
										 }
										 for(i=0;i<30;++i)
										 {      cpy.car_name[i]='\0';
										 }
										 for(i=0;i<10;++i)
										 {      cpy.status[i]='\0';
										 }
								}
								
								fout2.close();
								fin2.close();
								
								ifstream filin;
								filin.open("testing.txt",ios::in);
						 	
						}
					}
				}
				else
				{	cout<<endl<<"Journey has not started yet!!";
				}
			}
			else
			{	cout<<endl<<"Error in tracking !!!!";
			}
		}
		 count++;
		 cpy.sdd=0; cpy.smm=0; cpy.syy=0;
		 cpy.edd=0; cpy.emm=0; cpy.syy=0;
		 cpy.no_of_days=0; cpy.no_of_hours=0; cpy.no_of_members=0;

		 for(i=0;i<20;++i)
		 {	cpy.st_point[i]='\0';
			cpy.des_point[i]='\0';
			cpy.name[i]='\0';
		 }
		 for(i=0;i<15;++i)
		 {      cpy.payment_mode[i]='\0';
		 }
		 for(i=0;i<30;++i)
		 {      cpy.car_name[i]='\0';
		 }
		 for(i=0;i<10;++i)
		 {      cpy.status[i]='\0';
		 }
	}
}
   if(count==0)
   {	cout<<endl<<"Sorry !! Name doesnot exist.";
   		count=0;	
   }
   
   filin.close();
   closegraph();
} 

int main()
{	
	int ch,car_rent_choice,admin_choice,i;
	char pass[20];

label:	//system("cls"); 
	 	cout<<endl<<"Enter operation to perform:"<<endl;
		cout<<endl<<"\t(1) USER MODE\n\t(2)ADMINISTRATIVE MODE\n\t(3)EXIT MODE\n\t";
		cin>>ch;

	if(ch==1)
	{	cout<<"\nDo you want to rent a car(1 for yes): ";
		cin>>car_rent_choice;

		if(car_rent_choice==1)
		{       car_rent_choice=0;
				db.enterdetails();
				goto label;
		}
		else
		{		goto label;
		}
	}
	else if(ch==2)
	{	cout<<"Enter Password: ";
		fflush(stdin);
		cin.getline(pass,20);

		if(strcmp(pass,"utkarsh")==0)
		{	cout<<"\n\t\tWELCOME!!!!\n\t\tACCESS GRANTED\n\n";
			cout<<"Enter opertion to perform: "<<endl;
			cout<<"(1) AVAILABILITY OF A CAR\n(2) TRACKING OF A CAR\n";
			cin>>admin_choice;

			switch(admin_choice)
			{	case 1:		availability(); break;
				case 2: 	tracking(); break;
				default: 	cout<<"Invalid Input !!!!";
			}
			goto label;
   	   }
	       else
	       {	cout<<"SORRY!!! WRONG PASSWORD";
				goto label;
	       }
	}
	else if(ch==3)
	{	exit(0);
	}
	else
	{	cout<<endl<<"Invalid input";
		cout<<"\n\nYou are directing to Main Menu...  ";
		goto label;
	}
	getch();
}







