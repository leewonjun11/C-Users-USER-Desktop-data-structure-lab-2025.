#include <iostream>
#include <vector>
using namespace std;

struct Term {
    int coef; // 계수
    int exp;  // 차수

    Term(int c, int e) : coef(c), exp(e) {}
};

// 두 희소 다항식의 덧셈
vector<Term> addPolynomials(const vector<Term>& A, const vector<Term>& B) {
    vector<Term> result;
    int i = 0, j = 0;

    while (i < A.size() && j < B.size()) {
        if (A[i].exp > B[j].exp) {
            result.push_back(A[i++]);
        }
        else if (A[i].exp < B[j].exp) {
            result.push_back(B[j++]);
        }
        else {
            int sumCoef = A[i].coef + B[j].coef;
            if (sumCoef != 0) {
                result.emplace_back(sumCoef, A[i].exp);
            }
            i++;
            j++;
        }
    }

    while (i < A.size()) result.push_back(A[i++]);
    while (j < B.size()) result.push_back(B[j++]);

    return result;
}

// 다항식 출력
void printPolynomial(const vector<Term>& poly) {
    if (poly.empty()) {
        cout << "0" << endl;
        return;
    }

    for (size_t i = 0; i < poly.size(); ++i) {
        if (i != 0 && poly[i].coef > 0) cout << "+";
        cout << poly[i].coef << "x^" << poly[i].exp << " ";
    }
    cout << endl;
}

// 다항식 입력
vector<Term> inputPolynomial() {
    int n;
    cout << "항의 개수를 입력하세요: ";
    cin >> n;

    vector<Term> poly;
    for (int i = 0; i < n; ++i) {
        int coef, exp;
        cout << i + 1 << "번째 항의 계수와 차수를 입력하세요 (예: 계수 차수): ";
        cin >> coef >> exp;
        if (coef != 0) {
            poly.emplace_back(coef, exp);
        }
    }
    return poly;
}

int main() {
    cout << "첫 번째 다항식 입력\n";
    vector<Term> poly1 = inputPolynomial();

    cout << "두 번째 다항식 입력\n";
    vector<Term> poly2 = inputPolynomial();

    vector<Term> result = addPolynomials(poly1, poly2);

    // 각 다항식 출력
    cout << "\n[첫 번째 다항식]: ";
    printPolynomial(poly1);

    cout << "[두 번째 다항식]: ";
    printPolynomial(poly2);

    cout << "[덧셈 결과 다항식]: ";
    printPolynomial(result);

    return 0;
}