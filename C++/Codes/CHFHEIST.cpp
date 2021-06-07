{
	long int t;
	cin>>t;
	while(t--)
	{
	   long int D,d,P,Q,n;
	   cin>>D>>d>>P>>Q;
	   long int S=0;
	   n = D/d;
	   if(n%2==0)
	   {
	      S=d*((n/2)*(2*P+(n-1)*Q));
	   }
	   else
	   {
	      S=d*(n*(P+((n-1)/2)*Q));
	   }
      S=S+(D%d)*(P+(n)*Q);
	   cout<<S<<"\n";
	}
	return 0;
}
