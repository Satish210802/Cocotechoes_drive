#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> generateCommissions() {
    vector<int> commissions(12);

    for (int i = 0; i < 12; i++) {
        commissions.push_back(rand() % 4001 + 1000);
    }

    return commissions;
}

int main() { 
    
    vector<pair<string, vector<int>>> employeesData(100);
    
    for (int i = 1; i <= 100; ++i) {
        employeesData[i - 1] = {"Employee" + to_string(i), generateCommissions()};
    }

    vector<pair<string, double>> averageCommissions(employeesData.size());
    
    transform(employeesData.begin(), employeesData.end(), averageCommissions.begin(),
              [](const auto& employee) {
                  int sum = 0;
                  for (int commission : employee.second) {
                      sum += commission;
                  }
                  return make_pair(employee.first, sum / 12.0);
              });

    sort(averageCommissions.rbegin(), averageCommissions.rend());
    
    
    cout<<"\t+-------------------------------------------------------+"<<endl;
    cout << "\t| Top 5 employees with the highest average commission   |" << endl;
    cout<<"\t+-------------------------------------------------------+"<<endl;
    
    for (int i = 0; i < 5; ++i) {
        cout <<"\t|\t\t"<< i + 1 << ". " << averageCommissions[i].first << ": $" << averageCommissions[i].second <<"\t\t\t|"<< endl;
    }
    cout<<"\t+-------------------------------------------------------+"<<endl;

    return 0;
}
