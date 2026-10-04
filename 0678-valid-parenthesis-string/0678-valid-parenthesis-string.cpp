class Solution {
public:
    bool checkValidString(string s) {
        int min=0;
        int max=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                min = min+1;
                max = max+1;
            }
            else if(s[i]==')'){
                min = min-1;
                max = max-1;
            }
            else{                   
                min = min-1;        //  '*' as ')'
                max = max+1;        //  '*' as '('
                }
            if(min < 0)  min=0;             //example : [-1 , 2] min can't be -ve. , [0 , 2] is correct
            if(max < 0)  return false;      // means '(' zyada hai 
        }
        return (min==0);         //return true agr minimum range 0 hai otherwise false
    }
};