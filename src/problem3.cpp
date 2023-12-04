#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void mergeSortedArrays(vector<int>& A, vector<int>& B) {
  // Create a new vector to hold the merged array
  vector<int> C;
  
  // Use two indices to iterate through A and B
  int i = 0, j = 0;
  
  // Merge elements until one of the arrays reaches its end
  while (i < A.size() && j < B.size()) {
    // Compare elements and add the larger element to C first
    if (A[i] >= B[j]) {
      C.push_back(A[i]);
      i++;
    } else {
      C.push_back(B[j]);
      j++;
    }
  }
  
  // Add remaining elements from A or B
  while (i < A.size()) {
    C.push_back(A[i]);
    i++;
  }
  while (j < B.size()) {
    C.push_back(B[j]);
    j++;
  }
  
  // Replace A with the merged array C
  A = C;
}

int main() {
  int T;
  cin >> T;

  while (T--) {
    int N, M;
    cin >> N >> M;

    vector<int> A(N), B(M);

    // Read elements of A
    for (int i = 0; i < N; i++) {
      cin >> A[i];
    }

    // Read elements of B
    for (int i = 0; i < M; i++) {
      cin >> B[i];
    }

    // Merge the arrays
    mergeSortedArrays(A, B);

    // Print the merged array (in non-increasing order)
    for (int i = 0; i < A.size(); i++) {
      cout << A[i] << " ";
    }
    cout << endl;
  }

  return 0;
}
