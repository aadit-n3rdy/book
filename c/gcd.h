int gcd(int p, int q) {
	int r = 0;
	do {
		r = p%q;
		p=q;
		q=r;
	} while(r!=0);
	return p;
}
