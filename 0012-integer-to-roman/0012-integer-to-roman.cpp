class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        int d = 1;
        while(num > 0) {
            int temp = num%10;
            if(temp > 0 && temp <=3) {
                while(temp > 0) {
                    res =  getRoman(d) + res;
                    temp--;
                }
            }
            else if(temp > 3 && temp <=5){
                if(temp == 4) {
                    res =  getRoman(d) + getRoman(5 * d) + res;
                }else {
                    res = getRoman(5 * d) + res;
                }
            }
            else if(temp > 5 && temp <=8) {
                string t = "";
                while(temp > 5) {
                    t = getRoman(d) + t;
                    temp --;
                }
                res = getRoman(5* d) + t + res;
            }else if(temp == 9) {
                res =  getRoman(d) + getRoman(10 * d) + res; 
            }
            d *= 10;
            num = num/10;
        }
        return res;
    }
    string getRoman(int n)
    {
        switch(n)        {
            case 1: return "I";
            case 5: return "V";
            case 10: return "X";
            case 50: return "L";
            case 100: return "C";
            case 500: return "D";
            case 1000: return "M";
            default: return "";
        }
    }
};