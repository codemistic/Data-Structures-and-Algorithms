class insertquick
{
            inti,j,temp;
	int a[10];
  public:
	intk[10],no;
	 void getdata();
	 void insertionsort();
	 void display();
	 void getarray();
	 void sortit(int [], int, int);
	 void partition(int [],int ,int,int&);
	 void show();
	 };

      void insertquick::getdata()
       {
            cout<<"\n Enter the size of array:";
	cin>>no;
	cout<<"\n Enter the array elements:";
               for(int i=0;i<no;i++)
                {
	             cin>>a[i];
 	     }
	}

	void insertquick::insertionsort()
	 {
	   for(i=1;i<=no-1;i++)
	    {
	        for(j=i;j>=1;j--)
	     {
	            if(a[j]<a[j-1])
	       { 
		  temp=a[j];
		  a[j]=a[j-1];
		  a[j-1]=temp;
	       }
	     }
	    }
	   }
	   void insertquick::display()
	   {
	     cout<<"After insertion sort:";
	   for(i=0;i<no;i++)
	    {
                    cout<<a[i]<<"\t";
               }
   }
    void insertquick ::getarray()
{
     cout<<"\n Enter the size of array: ";
    cin>>no;
    cout<<"\n Enter array of element to sort: ";
    for(inti=0;i<no;i++)
      {
	   cin>>k[i];
       }
}
void insertquick::sortit(int x[], intlb, intub)
{
    int j;
   if(lb>= ub) 
         return;
         show();
       partition(x,lb,ub,j);
       sortit(x,lb,j-1);
       sortit(x,j+1,ub);
}

void insertquick::partition(int x[],intlb,intub,int&pj)
{
     int a, down, temp, up;
     a = x[lb];
     up = ub;
     down = lb;
while(down < up)
{
	while(x[down] <= a)
	    down++;
	while(x[up]  > a)
	    up--;
	if(down < up)
           {
	    temp = x[down];
	    x[down] = x[up];
	    x[up] = temp;
	}
    }

          x[lb] = x[up];
          x[up] = a;
         pj = up;
}

void insertquick::show()
{
      for(inti=0;i<no;i++)
      {
	cout<<k[i]<<" ";
       }

cout<<endl;
}

	    void main()
	    {
  	       clrscr();
 	       insertquick iq;
	       char choice;
		cout<<"Program to implement Insertion and Quick sort:\n";
		cout<<"Enter A for Insertion sort\nEnter B for Quick sort:";
		cout<<"\n Enter your choice:";
		cin>>choice;

	      switch(choice)
	     {
	        case 'A':
			cout<<"\n Program to implement Insertion sort:";
			iq.getdata();
			iq.insertionsort();
			iq.display();
			     break;

	       case 'B':
			cout<<"\n Program to implement Quick sort:";
			iq.getarray();
			iq.sortit(iq.k,0,iq.no-1);
			iq.show();
			   break;
	      default:

		          cout<<"Enter proper choice:";
	       }
	getch();
 }
