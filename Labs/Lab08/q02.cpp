#include<bits/stdc++.h>
using namespace std;

bool allNines(string s){
  for (int i = 0; i < s.size(); i++){
    if (s[i] != '9'){
        return false;
    }
  }
  return true;
}

string addToString(string s, int add){
  int carry = add;
  reverse(s.begin(), s.end());
  for (int i = 0; i < s.size(); i++){
    int total = carry + s[i] - '0';
    s[i] = total % 10 + '0';
    carry = total / 10;
  }
  if (carry > 0){
    s.push_back(carry + '0');
  }
  reverse(s.begin(), s.end());
  return s;
}

bool isBigger(string s, string result)
{
  if (result.size() != s.size()){
    return result.size() > s.size();
  }
  for (int i = 0; i < s.size(); i++){
    if (result[i] > s[i]){
        return true;
    }
    else if (result[i] < s[i]){
        return false;
    }
  }
  return false;
}

string getNextPalindrome(string s)
{
  if (allNines(s)){
    string result = addToString(s, 2);
    return result;
  }
  int half = s.size() / 2;
  string firstHalf;
  if (s.size() % 2 == 0){
    firstHalf = s.substr(0, half);
  }
  else{
    firstHalf = s.substr(0, half + 1);
  }
  string result;
  string reversedFirst = firstHalf;
  if (s.size() % 2 == 1){
    reversedFirst.pop_back();
  }
  reverse(reversedFirst.begin(), reversedFirst.end());
  result = firstHalf + reversedFirst;
  
  while (!isBigger(s, result))
  {
    firstHalf = addToString(firstHalf, 1);
    reversedFirst = firstHalf;
    if (s.size() % 2 == 1){
        reversedFirst.pop_back();
    }
    reverse(reversedFirst.begin(), reversedFirst.end());
    result = firstHalf + reversedFirst;
  }
  
  return result;
}

int main(void){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string result = getNextPalindrome(s);
    cout<<result<<"\n";
    return 0;
}
