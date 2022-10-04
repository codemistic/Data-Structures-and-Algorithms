class search
{
  private:
	int a[5];
	int i,n,j,temp;
    public:
	  void getdata();
	  void bubble_search();
	  void select_search();
	 };

	 void search::getdata()
         {
	cout<<"\n Enter size of array:";
	cin>>n;
	cout<<"\n Enter the array elements:";

	    for(i=0;i<n;++i)
	    {
	         cin>>a[i];
	     }
	 }
	   void search::bubble_search()
	    {
	      for(i=0;i<n-1;i++)
	       {
		for(j=0;j<n-i-1;j++)
		{
		     if(a[j]>a[j+1])
		 {
			temp=a[j];
			 a[j]=a[j+1];
			 a[j+1]=temp;
		   }
		}
	     }

cout<<"\n Array after bubble sort:";
       for(i=0;i<n;i++)
       {
	cout<<a[i]<<" ";
       }
    }
	  void search::select_search()
             {
	    cout<<"Sorting of array using selection:\n" ;
               for(i=0;i<n;i++)
            {
                    for(j=i+1;j<n;j++)
	       {
	           if(a[i]>a[j])
	      {
	             temp=a[i];
	             a[i]=a[j];
	            a[j]=temp;
	      }
	}
       }
                cout<<"Array after selection sort:\n";
                    for(i=0;i<n;i++)
                     {
                          cout<<a[i]<<" ";
                     }
          }

	      void main()
	       {
		search s;
		clrscr();
	            char choice;
		cout<<"Program to implement Bubble and Selection sort:\n";
		cout<<"Enter A for binary search\nEnter B for Selection sort:";
		cout<<"\n Enter your choice:";
		cin>>choice;
		 switch(choice)
		  {

		
                         case 'A':
			  cout<<"Program to implement Bubble sort on a array list:";
			  s.getdata();
			  s.bubble_search();
			    break;
		  case 'B':
			cout<<"Program to implement Selection sort on a array list:";
			s.getdata();
			s.select_search();
			   break;
		 default: cout<<"Enter correct choice:";
		 }
	getch();
	 }
