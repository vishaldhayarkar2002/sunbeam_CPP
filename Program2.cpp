#include<iostream>

using namespace std;

class Date{
	int date;
  	int month;
  	int year;

  	public :
	void initDate(){
    		this->date=1;
    		this->month=1;
    		this->year=1800;
	}

  	void printDateOnConsole(){
    		cout<<this->date<<"-"<<this->month<<"-"<<this->year;
  	}

  	void acceptDateFromConsole(){
    		cout<<"Give day";
 		cin>>this->date;
    		cout<<"Give Month";
    		cin>>this->month;
    		cout<<"Give Year";
    		cin>>this->year;
  	}

	bool isLeapYear(){

    		if(year % 400 == 0)
      			return true;

    		if(year % 100 == 0)
      			return false;

    		if(year % 4 == 0)
      			return true;

     	 	return false;
  	}
};
int main(){

  	Date d;

	printf("Please choose:\n");

  	int num = 100;

  	while(num != 0) {
    		cout<<"0 to Exit:\n";
    		cout<<"1 to Initialize Date:\n";
    		cout<<"2 for Giving Date:\n";
    		cout<<"3 to print Date:\n";
    		cout<<"4 to check leap year:\n";

    		cin>>num;

    		switch(num){
      			case 0:
        			num = 0;
        			break;

      			case 1:
        			d.initDate();
        			break;

      			case 2:
        			d.acceptDateFromConsole();
        			break;

      			case 3:
        			d.printDateOnConsole();
        			break;
      			case 4:
      				{
        			bool res = d.isLeapYear();

        			if(res == true)
        			{
         			cout<<"Leap year\n";
        			}
        			else
        			{
          				cout<<"Not a leap year\n";
        			}

        			break;
      			}

      			default:
        			printf("Wrong choice\n");
       	 			break;
    			}
  		}

  	return 0;
}
