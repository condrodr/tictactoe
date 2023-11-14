#include<iostream>
using namespace std;

 //baris dan kolom untuk space game
char space[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row;
int coloumn;
char token='o,x';
bool tie;
//player
string p1="";
string p2=" ";
   
//untuk menampilkan awal game    
void functionOne() 
{
   

    cout<<"   |   |   \n";
    cout<<" "<<space[0][0]<<" | "<<space[0][1]<<" | "  <<space[0][2]<<" \n";
    cout<<"___|___|___\n";
    cout<<"   |   |   \n";
    cout<<" "<<space[1][0]<<" | "<<space[1][1]<<" | "<<space[1][2]<<" \n";
    cout<<"___|___|___\n";
    cout<<"   |   |   \n";
    cout<<" "<<space[2][0]<<" | "<<space[2][1]<<" | "<<space[2][2]<<" \n";
    cout<<"   |   |   \n";
	
}

//kondisi untuk input xo
void functionTwo()
{
	int digit;
	
	if (token=='x')
	{
		cout<<p1<<" please chosee a number then press enter key : ";
		cin>>digit;
	}
	
		if (token=='o')
	{
		cout<<p2<<" please chosee a number then press enter key : ";
		cin>>digit;
	}
	
	if(digit==1)
	{
		row=0;
		coloumn=0;
	}
	
		if(digit==2)
	{
		row=0;
		coloumn=1;
	}
		if(digit==3)
	{
		row=0;
		coloumn=2;
	}
		if(digit==4)
	{
		row=1;
		coloumn=0;
	}
		if(digit==5)
	{
		row=1;
		coloumn=1;
	}
		if(digit==6)
	{
		row=1;
		coloumn=2;
	}
		if(digit==7)
	{
		row=2;
		coloumn=0;
	}
		if(digit==8)
	{
		row=2;
		coloumn=1;
	}
		if(digit==9)
	{
		row=2;
		coloumn=2;
	}
	
	else if(digit<1 || digit>9){
		cout<<" Invalid !!"<<endl;
	}
	
	if(token=='x' && space[row][coloumn] !='x' && space[row][coloumn] !='o')
	{
		space[row][coloumn]='x';
		token='o';
	}else if(token=='o' && space[row][coloumn] !='x' && space[row][coloumn] !='o'){
		space[row][coloumn]='o';
		token='x';	
	}else{
		cout<<"There is no empty space!"<<endl;
		functionTwo();
	}
	
}

bool functionThree()
{
	//kondisi menang game
	for(int i=0; i<3; i++)
	{
		if (space[i][0]==space[i][1] && space[i][0]==space[i][2] || space[0][i]==space[1][i] && space[0][i]==space[2][i])
		{
			return true;
		}
	}
		if (space[0][0]==space[1][1] && space[1][1]==space[2][2] || space[0][2]==space[1][1] && space[1][1]==space[2][0])
		{
			return true;
		}
	
	
	//kondisi untuk tetap lanjut game
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			if (space[i][j] !='x' && space [i][j] !='o')
			{
					return false;
			}
		}
	}
	tie=true;
	return false;
}

int main()
{
	
    cout<<"Enter First Player Name : ";
    getline(cin,p1);
    cout<<"Enter Second Player Name : ";
    getline(cin,p2);
    cout<<"-----------------------------------------\n";
    cout<<p1<<" is player 1 and will play first (x)\n";
    cout<<p2<<" is player 2 and will play second (o)\n";
    cout<<"-----------------------------------------\n";

	while(tie==false)
	{
		functionOne();
		functionTwo();
		functionThree();
	}
	
	if(token=='x' && tie==false)
	{
		cout<<p1<<" wins!!"<<endl;
	}else if (token=='o' && tie==false)
	{
		cout<<p2<<" wins!!"<<endl;
	}else{
		cout<<"Its a Draw"<<endl;
	}
}
