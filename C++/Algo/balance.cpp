int balance = 0;
    int ans = 0;
  
    for (int i = 0; i < s.length(); ++i) {
  
        balance += s[i] == '(' ? 1 : -1;
  
        if (balance == -1) {
            ans += 1;
            balance += 1;
        }
    }
  
    return balance + ans;
