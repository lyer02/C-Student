#include<iostream>
#include<vector>
#include<windows.h>
#include<algorithm>
using namespace std;






class Student;
class Source;
long long ID=1000;

vector<Student> allStudent;


//成绩模块   //建立学生信息时成绩为空 要进入菜单的成绩模块进行增删查改 
class Source
{

		 int english;
		 int chinese;
	     int all;
 	
 public:
 	Source(int i,int j,int a)
 	{
	   english = i;
	   chinese = j;
	   all = a;
	 }
	 
 		int getEnglish()
 		{
		 	return english;
		 }
		 int getChinese()
		 {
 			
 			return chinese;
 		}
 		int getAll()
 		{
		 	return all;
		 }
		 
 		void setEnglish(int e)
 		{
		 	english = e;
		 	all +=e;
		 }
		void setChinese(int c)
		{
			
			chinese = c;
			all +=c;
		}
			
	
};

//学生个人信息  内嵌入Source 
class Student
{
	private:
	 string name;
	 string  gender;
	 int age;
	 string tel;
	 long long id;
	Source *source;
	  
	  
	  
	public:
		Student()
		{
			name="null";
			age=0;
			gender="null";
			tel="null";
			id=0;
			source = NULL;
		}
		Student(string n,string t,int a,string g)
		{
			name = n;
			tel = t;
			age = a;
			gender = g;
			id = ID++;
		source = new Source(0,0,0);   //建立学生信息时成绩为空 要进入菜单的成绩模块进行增删查改 
		}
		
		void printSimple() //简单打印学生基本信息 
		{
			cout<<"ID: "<<id<<"     ";
			cout<<"Name:  "<<name<<"    ";
			
			cout<<endl;
		}
		//全部信息打印 但是不包括成绩 如需成绩 需要进入成绩模块 
		void printAll()
		{
			cout<<"ID: "<<id<<" ";
			cout<<"Name:  "<<name<<" ";
			cout<<"Age:   "<<age<<" ";
			cout<<"Gender: "<<gender<<" ";
			cout<<"Tel: "<<tel<<" ";
			cout<<endl;
			
		}
		
		void printSource()
		{
			cout<<"ID: "<<id<<" ";
			cout<<"Name:  "<<name<<" ";
			cout<<"English: "<<source->english<<" ";
			cout<<"Chinese: "<<source->chinese<<" ";
			cout<<"All: "<<source->all<<endl; 
		} 
		
		int getID()
		{
			return id;
		}
		string getName()
		{
			return name;
		}
		string getTel()
		{
			return tel;
		}
		Source getSource()
		{
			return source;
		}
		
		
		void setName(string name)
		{
			this->name = name;
		}
		void setTel(string tel)
		{
			this->tel = tel;
		}
		void setAge(int age)
		{
			this->age = age;
		}
		void setGender(string gender)
		{
			this->gender = gender;
		 } 
		 void setSource(Source s)
		 {
 			source = s;
 		}
};

void Menu();
void AddUser();
void Simple();
void printAll();
void deleteS();
void Consult();
void Change();
void StudentSource();

long long ContainId(long long id);  //检查ID是否存在 

int main(void)
{
	
	
	allStudent.clear();
	while(1)
	{
		int flag=1; 
		system("cls");
		Menu();
		int choose;
		cout<<"\n您需要什么业务？   请输入：";
		cin>>choose;
		
		if(choose>6 || choose<0)
		{
			system("cls");
			cout<<"无效命令！请重试！";
			Sleep(400);
			continue;
		}
		
		switch(choose)
		{
			system("cls");
			case 7:flag=0;break;  //flag是否退出系统标记 
			case 0:Simple();break;
      	    case 1:printAll();break;
      	    case 2:AddUser();break;
      	    case 3:deleteS();break;
      	    case 4:Consult();break;
      	    case 6:Change(); break;
      	    case 5:StudentSource();break; 
		}
		
		if(!flag)
		{
			system("cls"); 
			cout<<"***************欢迎再次使用！*************"; //结束提示语 
			Sleep(50);
			 break;
		}
	}
		
	
}


void Menu()
{
	cout<<"                _________________________________________________\n\n";
	cout<<"                                 学生管理系统1.0（@PB）           \n";      
	cout<<"                _________________________________________________ \n";
	cout<<"\n 		 		(1) 显示学生详细信息\n\n";
	cout<<" 		 		(0) 显示学生简约信息\n";
	cout<<"\n";
	cout<<" 		 		(2)   添加学生信息\n";
	cout<<"\n";
	cout<<" 				(3)   删除学生信息\n";
	cout<<"\n";
	cout<<" 				(4)       查询\n";
	cout<<"\n";
	cout<<" 				(6)   修改学生信息\n";
	cout<<"\n";
	cout<<" 				(5)       成绩系统\n";
	cout<<"\n";
	cout<<" 				(7)       退出\n";  
    cout<<"                _________________________________________________\n"; 
}


void AddUser()
{
	system("cls"); 
	int time=0;
	string n,t,g;
	int a=0;
	cout<<endl;
	cout<<"第 "<<ID<<" 号学生的姓名：  ";
	cin>>n;
	cout<<endl;
	cout<<"第 "<<ID<<" 号学生的年龄：  ";
	cin>>a;
	cout<<endl; 
	cout<<"第 "<<ID<<" 号学生的性别：  ";
	cin>>g;
	cout<<endl;
	cout<<"第 "<<ID<<" 号学生的电话：  ";
	cin>>t;
	cout<<endl;
	system("cls");
	cout<<"信息正在录入中";            
	while(time++<20)  //动画效果 
	{
		cout<<".";
		Sleep(50);
	 }
	 system("cls");
	 cout<<"\n                    信息录入成功！" ;
	 Sleep(1000);
	 Student student(n,t,a,g);
	 allStudent.push_back(student);   
	
}



//简约信息 
void  Simple()
{
	system("cls");
	for(int i=0;i<allStudent.size();i++)
	{
			allStudent[i].printSimple();
			cout<<endl;
	}
	if(allStudent.size()!=0)
	cout<<"按A键继续.....";
	else
	cout<<"学生信息为空 系统还未记录学生信息！按A键继续.....";
	char ch;
	cin>>ch;
	cout<<endl; 
}



//详细详细 
void printAll()
{
	system("cls");
	for(int i=0;i<allStudent.size();i++)
	{
			allStudent[i].printAll();
			cout<<endl;
	}
	if(allStudent.size()!=0)
	cout<<"按A键继续.....";
	else
	cout<<"学生信息为空 系统还未记录学生信息！按A键继续.....";
	char ch;
	cin>>ch;
	cout<<endl; 
	
}



//删除模块 
void deleteS()
{
	
	int rt = 1; //循环标志
	 
	while(rt)   //设置循环  可以在找不到ID的情况下重新输入id 
	{
		int flag=0;
		
		system("cls");
		cout<<"请输入要删除学生信息的ID 【注意：删除该ID后ID不可复用】:  ";
		long long  id;
		cin>>id;
	 cout<<endl; 
		
	for(int i=0;i<allStudent.size();i++)
	 {
	 	
	 	int time=0;
		system("cls");    //清屏   
		if(allStudent[i].getID()==id)
		{	
				flag=1;
				
				cout<<"正在删除";            
				while(time++<20)  //动画效果 
				{
					cout<<".";
					Sleep(50);
				 }
			system("cls");
				 
			cout<<"成功删除学生 "<<allStudent[i].getID()<<": "<<allStudent[i].getName()<<" 的信息！"; 
			allStudent.erase(allStudent.begin()+i);    //从容器中删除  这里产生了一个错误 现在改了 把erase放在最后 安全 防止空 
			char choose;
			cout<<" \n 是否继续删除？【Y/N】 "; 
			cin>>choose; 
			if(choose!='Y')
			rt=0;
			break; 
		}
		
	 } 
	 	if(!flag)  //没有这个id 
		{
			
            char choose;
			cout<<"\n系统找不到该学生！是否重新输入？(Y/N) : "; 
			cin>>choose;
			
			if(choose!='Y')
				rt = 0;  //退出循环标志 
			
			break;
		} 	 
   }  //while 
	
	
}


//查询模块
long long ContainId(long long id)  //存在返回id  不存在返回-1 
{
	int flag=0;
	for(int i=0;i<allStudent.size();i++)
	{
		if(allStudent[i].getID()==id)
		{
			flag=1;
			return i;
		}
	}
	if(!flag)
	return -1;
}
void Consult()
{
	
	int rt=1;
	while(rt)
	{
		int flag=0;  //是否找到该id标志 
				system("cls");
				cout<<"请输入要查询的ID :"; 
				long long  id=0;
				cin>>id;
			 cout<<endl; 
			 	
			 
			 	for(int i=0;i<allStudent.size();i++)
			   {
				system("cls");    //清屏   
				if(allStudent[i].getID()==id)
				{	
				    flag=1;
					 
					system("cls");	 
					allStudent[i].printAll();  //打印查询详细信息
					 
					 cout<<"\n\n"<<endl;
					 cout<<"要对该学生进行什么操作？【D删除|N不做操作】";
						char ch;
						cin>>ch;
						if(ch=='D')  //删除 
						{
							int time=0;
									cout<<"正在删除";            
								while(time++<20)  //动画效果 
								{
									cout<<".";
									Sleep(50);
								 }
							system("cls");
								 
							cout<<"成功删除学生 ";
							allStudent.erase(allStudent.begin()+i); 
						}
						else
						{
							system("cls");
							allStudent[i].printAll();
						} 
		
					char choose;
					cout<<" \n\n 是否继续查询？【Y/N】 "; 
					cin>>choose; 
					if(choose!='Y')
					rt=0;
					break; 
				}
					
			 } 
			  
			  if(!flag)  //没有这个id 
				{
					
		            char choose;
					cout<<"\n系统找不到该学生！是否重新输入？(Y/N) : "; 
					cin>>choose;
					
					if(choose!='Y')
						rt = 0;  //退出循环标志 
					
					break;
				} 
	 
	}//while	
		
	
} 

//修改模块
void Change()
{
	int rt=1;
	while(rt)
	{
		system("cls");
				cout<<"请输入要修改的ID :"; 
				long long  id=0;
				cin>>id;
			 cout<<endl;
			 if(ContainId(id)==-1)  //id不存在 
			 {
			 		char choose;
					cout<<" \n\n找不到ID  是否继续查询？【Y/N】 "; 
					cin>>choose; 
					if(choose!='Y')
					rt=0;
					
			  }
			  else{
			  	
			  	 int cg;
			  	 
			  	 
			  	 
				   cout<<"修改哪个属性？【1】姓名 【2】年龄 【3】性别 【4】电话 （ID不可改 ID是唯一的）"<<endl; 
			  	cin>>cg;
			  	string s = "";
			  	system("cls");
			  	switch(cg)
			  	{
			  		
			  	   	  case 1:cout<<"请输入新的姓名：  ";cin>>s;allStudent[ContainId(id)].setName(s);s =""; break;
					  case 2:cout<<"请输入新的年龄：  ";cin>>cg;allStudent[ContainId(id)].setAge(cg);break;
					  case 3:cout<<"请输入新的性别：  ";cin>>s;allStudent[ContainId(id)].setGender(s);s ="";break;
					  case 4:cout<<"请输入新的电话：  ";cin>>s;allStudent[ContainId(id)].setTel(s);s ="";break;
					  default:cout<<"无效命令！"<<endl;continue;
				  }
			  	
			  	int time=0;
				cout<<"正在更新";            
				while(time++<20)  //动画效果 
				{
					cout<<".";
					Sleep(50);
				 }
				system("cls");
								 
					cout<<"成功更新学生:"<<endl;
					allStudent[ContainId(id)].printAll();
					
			  	cout<<" \n\n 是否继续查询？【Y/N】 "; 
			  	char choose;
					cin>>choose; 
					if(choose!='Y')
					rt=0;
			  } 
	}
 } 



//成绩模块 单独 

bool compareAll(Student i,Student j);
bool compareEnglish(Student i,Student j);
bool compareChinese(Student i,Student j);

void Sort_All(); //总成绩 
void Sort_E();   //英语排序 
void Sort_C();   //语文 

void inputSource();


void StudentSource()
{
	int rt=1;
		system("cls");
		while(rt)
		{
						cout<<"\n------------------------> 欢迎进入PB成绩管理系统 <-----------------------------\n\n\n\n"; 
			int id=0;
			cout<<"--------------* 【1】学生总成绩排序\n\n";
			cout<<"--------------* 【2】学生语文成绩排序\n\n";
			cout<<"--------------* 【3】学生英语成绩排序\n\n";
			cout<<"--------------* 【4】录入学生成绩\n\n";
			cout<<"--------------* 【5】修改学生成绩\n\n";
			cout<<"--------------* 【0】退出成绩管理系统\n\n";
			cout<<"您需要什么业务？:   ";
			int choose=0;
			cin>>choose;
			
			switch(choose)
			{
				case 1:Sort_All();break;
				case 2:Sort_C();break;
				case 3:Sort_E();break;
				case 4:inputSource();break; 
				case 5:cout<<"因时间原因 同时代码相似 所以这里不写了！";break;
				case 0:	rt=0;break;
			}
			
		} 

	 
	
	
} 



//排序比较函数  升序 
bool compareAll(Student i,Student j)
{
	return i.source.all>j.source.all;
}
bool compareChinese(Student i,Student j)
{
	return i.source.chinese>j.source.chinese;
}
bool compareEnglish(Student i,Student j)
{
	return i.source.english>j.source.english;
}



void Sort_All()
{
	vector<Student> copyStudent(allStudent);
	sort()
	system("cls");
	cout<<"______________________________________\n\n";
	sort(copyStudent.begin(),copyStudent.end(),compareAll);   //按指定字段排序
	for(int i=0;i<copyStudent.size();i++)
	{
		cout<<"|  "<<i<<"  | "<<Student.printSource()<<endl;
	}	
}
void Sort_E()
{
	vector<Student> copyStudent(allStudent);
	sort()
	system("cls");
	cout<<"______________________________________\n\n";
	sort(copyStudent.begin(),copyStudent.end(),compareEnglish);   //按指定字段排序
	for(int i=0;i<copyStudent.size();i++)
	{
		cout<<"|  "<<i<<"  | "<<Student.printSource()<<endl;
	}	
} 
void Sort_C()
{
	vector<Student> copyStudent(allStudent);
	sort()
	system("cls");
	cout<<"______________________________________\n\n";
	sort(copyStudent.begin(),copyStudent.end(),compareChinese);   //按指定字段排序
	for(int i=0;i<copyStudent.size();i++)
	{
		cout<<"|  "<<i<<"  | "<<copyStudent[i].printSource()<<endl;
	}	



void inputSource()
{
	int rt=1;
	while(rt)
	{
		
		system("cls");
		cout<<"请输入要录入的学生ID： ";
		long long id=0;
		cin>>id;
		
		 if(ContainId(id)==-1)  //id不存在 
			 {
			 		char choose;
					cout<<" \n\n找不到ID  是否继续查询？【Y/N】 "; 
					cin>>choose; 
					if(choose!='Y')
					rt=0;
					
			  }
		  else
		  {
		  	int  c;
		  	int  e;
  			cout<<"语文："; 
  			cin>>c;
  			cout<<endl;
  			cout<<"英语："; 
  			cin>>e;
  			cout<<endl;
  			
  			//计入  总分会自动计算 
  			allStudent[ContainId[id]].source.english = e;
  			allStudent[ContainId[id]].source.chinese = c;
  			
  			
  			int time=0;
  			system("cls"); 
				cout<<"正在录入";            
				while(time++<20)  //动画效果 
				{
					cout<<".";
					Sleep(50);
				 }
				system("cls");
								 
					cout<<"录入成功！"<<endl;
					allStudent[ContainId(id)].printSource();
					
			  	cout<<" \n\n 是否继续查询？【Y/N】 "; 
			  	char choose;
					cin>>choose; 
					if(choose!='Y')
					rt=0;
  		  }	  
  		  
	}
}
	
