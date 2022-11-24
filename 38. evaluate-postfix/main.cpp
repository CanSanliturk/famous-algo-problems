#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

#include <forward_list>

using namespace std;

#define ERR (((1 << 30) - 1) << 1)

long evaluatePostfix(const vector<string>& input) {

	stack<long> stck;

	auto isNumber = [](const string& str) {

		try {
			stoi(str);
			return true;
		}
		catch(std::exception ex) {
			return false;
		}

	};

	auto errFlag = false;

	unordered_map<string, function<void()>> perform {
		{ "+", [&]() {

				if (stck.empty()) {
					errFlag = true;
					return;
				}

				auto rightOperand = stck.top();
				stck.pop();

				if (stck.empty()) {
					errFlag = true;
					return;
				}

				auto leftOperand = stck.top();
				stck.pop();

				stck.push(leftOperand + rightOperand);				
			} 
		},
		{ "-", [&]() {

				if (stck.empty()) {
					errFlag = true;
					return;
				}

				auto rightOperand = stck.top();
				stck.pop();

				if (stck.empty()) {
					errFlag = true;
					return;
				}

				auto leftOperand = stck.top();
				stck.pop();

				stck.push(leftOperand - rightOperand);				
			} 
		},
		{ "*", [&]() {

				if (stck.empty()) {
					errFlag = true;
					return;
				}

				auto rightOperand = stck.top();
				stck.pop();

				if (stck.empty()) {
					errFlag = true;
					return;
				}

				auto leftOperand = stck.top();
				stck.pop();

				stck.push(leftOperand * rightOperand);				
			}
		},
		{ "/", [&]() {

				if (stck.empty()) {
					errFlag = true;
					return;
				}

				auto rightOperand = stck.top();
				stck.pop();

				if (stck.empty()) {
					errFlag = true;
					return;
				}

				auto leftOperand = stck.top();
				stck.pop();

				stck.push(leftOperand / rightOperand);				
			} 
		}
	};

	for (auto& str : input) {

		if (isNumber(str)) {
			stck.push(stoi(str));
			continue;
		}

		perform[str]();
		if (errFlag)
			return ERR;
	}

	if (stck.empty())
		return ERR;

	auto ans = stck.top();
	stck.pop();

	if (!stck.empty())
		return ERR;

	return ans;
}

int main() {

	auto testCase = [](const vector<string>&& input, int expected) {
		cout << "_______________" << endl;
		cout << "TEST CASE" << endl;
		cout << "Input: ";
		for (auto& str : input)
			cout << str << " ";
		cout << endl;
		cout << "Expected: " << expected << endl;
		auto ans = evaluatePostfix(input);
		cout << "Calculated: " << ans << endl;
		cout << "Result: " << (ans == expected ? "OK" : "NOT OK") << endl;
		cout << "_______________" << endl;
	};

	testCase({ "2", "1", "+", "3", "*" }, 9);
	testCase({ "4", "13", "5", "/", "+" }, 6);
	testCase({ "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" }, 22);

	return 0;
}