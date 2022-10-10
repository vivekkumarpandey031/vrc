#include<iostream>
#include<fstream>
using namespace std;
class student
{
  int roll_no,marks[10];
  public:
    void getstudent()
    {
      cout<<"\nEnter marks of three subjects(Out of 50): \n";
      for(int i=0;i<3;i++)
        cin>>marks[i]; 
    }
    void dispstudent()
    {
      int tot=0;
      cout<<"\n\nStudent Roll-no: "<<roll_no;
      cout<<"\nMarks of 3 Subjects(Out of 50): "<<endl;
      for(int i=0;i<3;i++)
      {
        cout<<"Mark "<<i+1<<" :"<<marks[i]<<endl;
        tot+=marks[i];
      }
      cout<<"\nTotal Marks(out of 150): "<<tot;
    }
    int getroll_no()
    {
      return roll_no;
    }
};
int main()
{
    cout<<"vivek kumar pandey "<<'\n'<<"47"<<'\n';
  student s;
  fstream f1;
  int n,flag=0;
  char ch;
  f1.open("newfile.bin",ios::out | ios::in | ios::binary);
  int pos;
  if(!f1)
    cout<<"\n!Cannot open file!";
  else
  {
    cout<<"\n!!STUDENT'S MARKS MODIFICATION!!\n";
    cout<<"\nEnter Roll-no of the student to modify: ";
    cin>>n;
    while(!f1.eof())
    {
      f1.read((char*)&s,sizeof(s));
      pos=f1.tellg();
      if(n==s.getroll_no())
      {
        s.dispstudent();
        cout<<"\nEnter new marks: \n";
        s.getstudent();
        pos=pos-sizeof(s);
        f1.seekp(pos);
        f1.write((char*)&s,sizeof(s));
        flag=1;
        break;
      }  
    }
    if(!flag)
    {
      cout<<"\n!!Data not found!!";
      f1.close();
      exit(0);
    }
    f1.seekg(0);
    cout<<"\nUpdated data: "<<endl;
    f1.read((char *)&s,sizeof(s));
    while(!f1.eof())
    {
      s.dispstudent();
      f1.read((char *)&s,sizeof(s));
    }
  }
  f1.close();
  return 0;
}