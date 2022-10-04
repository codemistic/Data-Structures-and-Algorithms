class search
{
  private:
	inta[20],beg,end,mid,item,n;
  public:
	  void getdata();
	  void binary_search();
	 };

	 void search::getdata()
	 {
	     cout<<"Enter the size of array:";
           	    cin>>n;
               cout<<"Enter the array elements:";
	for(int i=1;i<=n;i++)
	  {
	        cin>>a[i];
	     }
	 }
       void search::binary_search()
    {

  	cout<<"Enter a number to be search:";
	cin>>item;
	      beg=0;end=n-1;
	      mid=(beg+end)/2;

	      while((beg<=end)&&(a[mid]!=item))
 		{
               	if(item<a[mid])
		  {
	        	            end=mid-1;
		   }

		else
		{
		     beg=mid+1;
		    mid=(beg+end)/2;
		 }
	       }

	  if(a[mid]==item)
	{
		cout<<"The item found at location:"<<mid+1;
	  }
	else
	{
		cout<<"Items dosent exits:";
	}
       }


	       void main()
	       {
		 search s;
		clrscr();
		cout<<"Program to implement Binary search on given array list";
		s.getdata();
		s.binary_search();
		getch();
		 }

