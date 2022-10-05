class search
{
 public:
      inta[5],no,flag;
      void getdata();
      void linear();
 };

void  search::getdata()
       {
	cout<<"\n Enter the numbers:";
	for(int i=0;i<5;i++)
	{
	     cin>>a[i];
	}
	    cout<<"Enter the no to be searched:";
	    cin>>no;
	}
    void search::linear()
     {
	for(int i=0;i<5;i++)
	    {
            	     if(no==a[i])
	      {
			flag=1;
			break;
	      }
	   }
       if(flag==1)
	{
	       cout<<"\n The no is found at position:"<<i+1;
	 }
      else
	 {
    	       cout<<"The no is not found:";
	 }
	 }
      void main()
      {
	search obj;
	clrscr();
	cout<<"\n Program to implement Linear sort search on given array list";
	obj.getdata();
	obj.linear();
	getch();
      }
