class Solution {
    string digits2string(vector<int>& digits,map<int,string>& unitPlace,map<int,string>& tenPlace,
                            map<int,string>& oneCase){
        string res;
        //For Billion
        if(digits[9])    res += unitPlace[digits[9]]+" Billion ";
        
        //For Million
        if(digits[8])
            res += unitPlace[digits[8]]+" Hundred ";
        if(digits[7]==1)    res+=oneCase[digits[6]]+" ";
        else{
            if(digits[7])   res+=tenPlace[digits[7]]+" ";
            if(digits[6])   res+=unitPlace[digits[6]]+" ";
        }
        if(digits[8] or digits[7] or digits[6]) res+="Million ";

        //For Thousand
        if(digits[5])
            res+=unitPlace[digits[5]]+" Hundred ";
        if(digits[4]==1)    res+=oneCase[digits[3]]+" ";
        else{
            if(digits[4])   res+=tenPlace[digits[4]]+" ";
            if(digits[3])   res+=unitPlace[digits[3]]+" ";
        }
        if(digits[5] or digits[4] or digits[3]) res+="Thousand ";

        //For Hundred
        if(digits[2])
            res+=unitPlace[digits[2]]+" Hundred ";
        if(digits[1]==1)    res+=oneCase[digits[0]]+" ";
        else{
            if(digits[1])   res+=tenPlace[digits[1]]+" ";
            if(digits[0])   res+=unitPlace[digits[0]];
        }

        //remove spaces from the end
        while(res.size() and res.back()==' ')
            res.pop_back();
        return res;
    }
public:
    string numberToWords(int num) {
        if(num==0)
            return "Zero";

        map<int,string> unitPlace;
        unitPlace[0]="";
        unitPlace[1]="One";
        unitPlace[2]="Two";
        unitPlace[3]="Three";
        unitPlace[4]="Four";
        unitPlace[5]="Five";
        unitPlace[6]="Six";
        unitPlace[7]="Seven";
        unitPlace[8]="Eight";
        unitPlace[9]="Nine";

        map<int,string> tenPlace;
        tenPlace[0]="";
        tenPlace[1]="Ten";//We will never use this
        tenPlace[2]="Twenty";
        tenPlace[3]="Thirty";
        tenPlace[4]="Forty";
        tenPlace[5]="Fifty";
        tenPlace[6]="Sixty";
        tenPlace[7]="Seventy";
        tenPlace[8]="Eighty";
        tenPlace[9]="Ninety";

        map<int,string> oneCase;
        oneCase[0]="Ten";
        oneCase[1]="Eleven";
        oneCase[2]="Twelve";
        oneCase[3]="Thirteen";
        oneCase[4]="Fourteen";
        oneCase[5]="Fifteen";
        oneCase[6]="Sixteen";
        oneCase[7]="Seventeen";
        oneCase[8]="Eighteen";
        oneCase[9]="Nineteen";

        vector<int> digits;
        int n=num;
        //Extract all digits
        while(n){
            digits.push_back(n%10);
            n/=10;
        }
        //Append leading 0's to make 10 digit number
        while(digits.size()<10)
            digits.push_back(0);

        return digits2string(digits,unitPlace,tenPlace,oneCase);
    }
};
