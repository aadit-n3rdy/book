#include <stdlib.h>

struct Set {
	int raw=0;
};

int setContains(const struct Set* set, int element) {
	return set->raw&1<<element;
}

void setEmpty(struct Set* set) {
	set->raw = 0;
}

int setSize(const struct Set* set) {
	int size = 0;
	const int raw = set->raw;
	for(int i = 0; i < 32; i++) {
		if(raw&1<<i) {
			size++;
		}
	}
	return size;
}

struct Set setUnion(const struct Set* set1, const struct Set* set2) {
	struct Set ret;
	ret.raw = set1->raw|set2->raw;
	return ret;
}
