#include <iostream>

using namespace std;

// функци€ затрат на эксплуатацию оборудовани€ возраста t в течение мес€ца
double r(int t) {
	return 96.0-47.0/(t + 1);
}

// функци€ ликвидной стоимости старого оборудовани€ возраста t
double phi(int t) {
	return 90.0 / (t + 1);
}

int main() {

	double p = 100, // стоимость нового оборудовани€
		   sum = 0;
	long double alpha = 0.9,  // дисконтирующий множитель
			    P,            // затраты на эксплуатацию оборудовани€ за N мес€цев
				P_pr;		  // затраты на эксплуатацию оборудовани€ за N-1 мес€цев

	int t = 1;

	FILE* file;
	fopen_s(&file, "output.txt", "w");
	fprintf_s(file, "%3s  | %6s \n", "N", "P(0)");

	while (true) {
		sum += pow(alpha, t-1) * r(t-1);

		// расчЄт затрат на эксплуатацию оборудовани€ за N мес€цев
		P = (1 / (1 - pow(alpha, t)))* (sum + pow(alpha,t)*(p - phi(t)));
		
		fprintf_s(file, "%3i  | %6.3f \n", t, P);

		// условие завершени€ работы цикла
		if (t > 1 && P > P_pr) {
			fprintf_s(file, "\nќтвет: P(0) = %6.3f  при N = %i", P_pr, t-1);
			break;
		}

		t++;
		P_pr = P;
	}
}