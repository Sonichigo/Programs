sort(cars.begin(),cars.end());
    long ans=LLONG_MAX,tmp;
    for(int i=0;i<=cars.size()-k;i++)
    {
        tmp= cars[i+k-1] -cars[i];
        ans= min(ans,tmp+1);
    }
    return ans;
