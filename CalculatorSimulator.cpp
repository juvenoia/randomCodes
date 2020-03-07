#include <cstdio>
#include <cstring>
#include <stack>
#include <cmath>
using namespace std;
char ch[1000];
stack<double> calculator; 
bool isNumber (char x){
	return x >= '0' && x <= '9' ? true: false; 
}
int main () {
	scanf ("%s", ch);
	ch[strlen(ch)] = '\n';		// use a '\n' to make sure the final number acceptable 
	ch[strlen(ch)] = '\0';
	char prevSym = '-';
	int continousAlphaNum = 0;
	for (int i = 0; ch[i] != '\0'; i++) {
		if (isNumber(ch[i])) {
			calculator.push(1.0* (ch[i] - '0'));
			continousAlphaNum++;
		}
		else {
			double temp1 = 0, temp2 = 0;
			for (int i = 0; i < continousAlphaNum; i++) {
				temp1 = calculator.top();
				calculator.pop();
				temp2 = temp2 + temp1*pow(10, i);
				if (i == continousAlphaNum - 1) calculator.push(temp2);
			}
				
					if (ch[i] == '.'){    // . is different from other Calculators that it needs to be calculated at once
						double temp1 = 0, temp2 = 0;
						int cnt = 1;
						for (i = i+1; isNumber(ch[i]); i++) 
							temp1 = temp1 + (ch[i] - '0') *pow(10, -cnt++);
							temp2 = calculator.top();
							calculator.pop();
							calculator.push(temp1 + temp2);
						}
					
					if (prevSym == '/') {
						temp1 = calculator.top();
						calculator.pop();
						temp2 = calculator.top();
						calculator.pop();
						calculator.push(temp1*temp2);
					}
					
					if (prevSym == '*') {
						temp1 = calculator.top();
						calculator.pop();
						temp2 = calculator.top();
						calculator.pop();
						calculator.push(temp2/temp1);
					}
					
					if (prevSym == '-');
					
					if (prevSym == '+') {
						temp1 = calculator.top();
						calculator.pop();
						calculator.push(-temp1);
					}
					
					prevSym = ch[i];
					continousAlphaNum = 0;
		}
	}
	double res = 0;
	while (calculator.size() > 0) {
		res += calculator.top();
		calculator.pop();
	}
	printf ("%.0lf", res);
}
	

