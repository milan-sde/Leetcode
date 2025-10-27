int n = bank.size();
int result = 0;
int prevCount = 0;
for(int i= 0 :i < n ;i++){
  int currCount = 0;
    for(char &ch : bank[i]){
      if(ch == '1'){
        currCount++;
      }
    }

    result = result + (currCount * prevCount);
    if(currCount != 0){
      prevCount = currCount;
    }
}

return result;
