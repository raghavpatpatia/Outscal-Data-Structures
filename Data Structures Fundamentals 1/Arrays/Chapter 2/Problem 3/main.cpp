#include <iostream>

using namespace std;
float NetIncome(float arr[], int size) 
{
    float sum = 0;
    for (int i = 0; i < size; i++) 
    {
        sum += arr[i];
    }
    return sum;
}

float GetPositiveValue(string message) 
{
    float value;
    do 
    {
        cout << message;
        cin >> value;
    } while (value < 0);
    return value;
}

void IncomeStatement() {
    float profitFromBusiness;
    float capitalGains;
    float salaryIncome = GetPositiveValue("Enter Salary Income (positive value only): ");
    float rentalIncome = GetPositiveValue("Enter Rental Income (positive value only): ");
    float otherIncome = GetPositiveValue("Enter Income from other sources (positive value only): ");
    cout << "Enter Income profit/loss from business: ";
    cin >> profitFromBusiness;
    cout << "Enter Capital gains/loss: ";
    cin >> capitalGains;
    float incomeArray[] = {salaryIncome, rentalIncome, profitFromBusiness, capitalGains, otherIncome};
    int size = sizeof(incomeArray) / sizeof(incomeArray[0]);
    cout << "Net Income of the person is: " << NetIncome(incomeArray, size) << endl;
}

int main() {
    IncomeStatement();
    return 0;
}
