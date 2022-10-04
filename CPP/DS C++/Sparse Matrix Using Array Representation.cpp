class matrix
{
  private:
	int a[3][3],s[3][3],k,i,j;
  public:

	   void getdata();
	   void calculate();
	   void display();
};

        void matrix::getdata()
        {
	cout<<"Enter the order of matrix 3X3:";
	cout<<"\n Enter the elements of matrix:";

	for(int i=0;i<3;i++)
	       {
		 for(int j=0;j<3;j++)
		  {
		       cin>>a[i][j];
		    }
		 }
	    }

	      void matrix::calculate()
	       {
		 k=0;
		for(int i=0;i<3;i++)
		  {
		      for(int j=0;j<3;j++)
		     {
		        if(a[i][j]!=0)
		  	{
			   s[0][k]=i;
			   s[1][k]=j;
			   s[2][k]=a[i][j];
			   k++;
			}
		      }
		    }
		  }

        void matrix::display()
        {
	cout<<"The separate matrix is:\n";

	  for(i=0;i<3;i++)
	    {
	     for(j=0;j<3;j++)
	      {
		cout<<"\t"<<s[i][j];
	      }
		cout<<"\n";

	   }
        }

   void main()
 {
            matrix m;
          	clrscr();
	cout<<"program to implement the sparse matrix";
	m.getdata();
	m.calculate();
	m.display();
	getch();
   }

