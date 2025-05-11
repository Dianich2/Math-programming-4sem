#include "permutation.h"
#include <algorithm>
#define NINF  ((short)0x8000)

namespace permutations {
	unsigned long long fact(unsigned long long x) {
		return(x == 0) ? 1 : (x * fact(x - 1));
	}

	permutation::permutation(short n) {
		this->n = n;
		this->sset.resize(n);
		this->dart.resize(n);
		this->reset();
	}

	void permutation::reset() {
		this->getfirst();
	}

	long long permutation::getfirst() {
		this->np = 0;
		for (int i = 0; i < this->n; i++) {
			this->sset[i] = i;
			this->dart[i] = L;
		}
		return(this->n > 0) ? this->np : -1;
	}

	int permutation::ntx(short i) {
		return this->sset[i];
	}

	long long  permutation::count() {
		return fact(this->n);
	}

	long long permutation::getnext() {
		long long rc = -1;
		short maxm = NINF;
		int idx = -1;
		for (int i = 0; i < this->n; i++) {
			if (i > 0 && this->dart[i] == L && this->sset[i] > this->sset[i - 1] &&
				maxm < this->sset[i]) {
				maxm = this->sset[idx = i];
			}
			if (i < (this->n - 1) && this->dart[i] == R && this->sset[i] > this->sset[i + 1] &&
				maxm < this->sset[i]) {
				maxm = this->sset[idx = i];
			}
		}
		if (idx >= 0) {
			std::swap(this->sset[idx], this->sset[idx + (this->dart[idx] == L ? -1 : 1)]);
			bool temp = dart[idx];
			bool temp2 = dart[idx + (dart[idx] == L ? -1 : 1)];
			dart[idx + (dart[idx] == L ? -1 : 1)] = temp;
			dart[idx] = temp2;
			for (int i = 0; i < this->n; i++) {
				if (this->sset[i] > maxm) {
					this->dart[i] = !this->dart[i];
				}
			}
			rc = ++this->np;
		}
		return rc;
	}
}