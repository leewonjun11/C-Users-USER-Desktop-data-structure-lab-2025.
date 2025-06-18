#include <iostream>
#include <vector>
using namespace std;

struct Term {
    int coef; // ���
    int exp;  // ����

    Term(int c, int e) : coef(c), exp(e) {}
};

// �� ��� ���׽��� ����
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

// ���׽� ���
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

// ���׽� �Է�
vector<Term> inputPolynomial() {
    int n;
    cout << "���� ������ �Է��ϼ���: ";
    cin >> n;

    vector<Term> poly;
    for (int i = 0; i < n; ++i) {
        int coef, exp;
        cout << i + 1 << "��° ���� ����� ������ �Է��ϼ��� (��: ��� ����): ";
        cin >> coef >> exp;
        if (coef != 0) {
            poly.emplace_back(coef, exp);
        }
    }
    return poly;
}

int main() {
    cout << "ù ��° ���׽� �Է�\n";
    vector<Term> poly1 = inputPolynomial();

    cout << "�� ��° ���׽� �Է�\n";
    vector<Term> poly2 = inputPolynomial();

    vector<Term> result = addPolynomials(poly1, poly2);

    // �� ���׽� ���
    cout << "\n[ù ��° ���׽�]: ";
    printPolynomial(poly1);

    cout << "[�� ��° ���׽�]: ";
    printPolynomial(poly2);

    cout << "[���� ��� ���׽�]: ";
    printPolynomial(result);

    return 0;
}