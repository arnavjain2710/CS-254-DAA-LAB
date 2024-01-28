#include <bits/stdc++.h>

int main() {

  std::ofstream outfile("input.txt");

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(1, 100);

  for (int i = 0; i < 32; i++) {
    for (int j = 0; j < 32; j++) {
      outfile << dis(gen) << " "; 
    }
    outfile << "\n";
  }

  outfile.close();

  return 0;
}